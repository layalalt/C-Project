#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Taxi {
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

int main() {
    
    FILE* file = fopen("Taxies.txt", "r"); 

    if (file == NULL) {
        printf("file opening error");
    }
   else{
   printf("file opened successfully");
   //rest of the code
   }
    
    return 0;
}
