#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Taxi
{
    int id;
    char driver[20];
    char category[20];
    char plate[7];
    char color[20];
    float rate;
    float minCharge;
    char state;
    struct Taxi* next;
};

typedef struct Taxi Taxi;
Taxi* list; //list is like the head
void addTripCar();
void printList();
void setTripCar();


int main() 
{
    
   FILE* file = fopen("Taxies.txt", "r"); 

   if(file == NULL) 
       perror("Error in opening file");
   else
   {
     addTripCar();
    //rest of the code
    printList();
   }
    
    
    
    
    
    return 0;
}

void addTripCar()
{
  FILE* file = fopen("Taxies.txt", "r"); 
  char c;
  int i, count = 0;
  if(file) 
  { 
    while((c=fgetc(file)) != EOF) //counts number of lines (number of taxies)
    {
      if(c == '\n') 
        count++;
    }
    rewind(file);    
    while((c=fgetc(file)) != '\n'); //reaches new line after header
    
    Taxi *curr, *prev;
    list = (Taxi*)malloc(sizeof(Taxi));
    fscanf(file, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%f\t\t%f", &(list->id), list->driver, list->category, list->plate, list->color, &(list->rate), &(list->minCharge));
    list->state = 'A';
    prev = list;
    for(i=1; i<count; i++)
    {
      curr = (Taxi*)malloc(sizeof(Taxi));
      fscanf(file, "%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%f\t\t%f", &(curr->id), curr->driver, curr->category, curr->plate, curr->color, &(curr->rate), &(curr->minCharge));
      curr->state = 'A';
      prev->next = curr;
      prev = curr;
    }
    prev->next = NULL;
  }
  else
    perror("Error in opening file");        
  fclose(file);
}

void printList()
{ 
  Taxi* curr = list;
  printf("ID\tDriver\tCategory\tPlate\tColor\tRate\tMinCharge\tState\n");
  while(curr != NULL)
  {
    printf("%d\t%s\t%s\t%s\t%s\t%f\t%f\t%c\n", curr->id, curr->driver, curr->category, curr->plate, curr->color, curr->rate, curr->minCharge, curr->state); 
    curr = curr->next;
  }
}
void setTripCar(char* category, float* rate)
{
 Taxi *p= list;
 while(p!=NULL)
 {
 	if(p->state=='A')
 	{
 		if((p->category==*category)&&(p->rate==*rate))
 		{
 			p->state='R'
 			break;
 		}
 		p=p->next;
    }
 }

 
}



 

	
