#include <stdio.h>
#include <stdlib.h>

int ** allocateIntStarArray(int num);
int * allocateIntArray(int num);
void drawrow(int *, int);

int main(void){
    int length, width;
    int ** grid;
    int * row;
    int i, j;

    scanf("%d %d", &length, &width);
    grid = allocateIntStarArray(width);
    for(i = 0; i < width; i++){
        row = allocateIntArray(length);
        grid[i] = row;
    }
    free(row);

    for(i = 0; i < width; i++){
        for(j = 0; j < length; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    for(i = 0; i < width; i++){
        drawrow(grid[i], length);
    }
    free(grid);
    return 0;
}

int * allocateIntArray(int num){
    int * ptr = (int *) malloc(num * sizeof(int));
    return ptr;
}

int ** allocateIntStarArray(int num){
    int ** ptr = (int **) malloc(num * sizeof(int *));
    return ptr;
}

void drawrow(int * row, int length){
    for(int i = 0; i < length; i++){
        if(row[i] < 100){
            printf("[ ]");
        } 
        else if (row[i] < 1000){
            printf("[*]");
        }
        else{
            printf("[X]");
        }
    }
    printf("\n");
}