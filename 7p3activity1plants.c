#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int plants;
    double plantprice,totalcost;
    
    if(argc == 3) {
        plants = atoi(argv[1]);
        plantprice = atof(argv[2]);
        totalcost = plants * plantprice;
        printf("%d plants for %.2lf dollars each cost %.2lf dollars.\n", plants, plantprice, totalcost);
    }
    else{
        printf("Invalid input.\n");
    }
    return 0;
}