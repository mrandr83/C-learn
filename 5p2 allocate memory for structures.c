#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
};

void printPoint(struct point);
void printPoly(struct point *, int);
void initializePoly(struct point *, int);

int main(void) {
    //! showMemory(start=65520)
    struct point * polygon;
    int num;
    //printf("How many vertices does your polygon have? ");
    scanf("%d", &num);
    polygon = (struct point *) malloc(num * sizeof(struct point));
    initializePoly(polygon, num);
    printPoly(polygon, num);
    free(polygon);
	return 0;
}

void printPoint(struct point pt) {
    printf("(%d, %d)\n", pt.x, pt.y);
}

void printPoly(struct point *ptr, int N) {
    int i;
    for (i=0; i<N; i++) {
        printPoint(ptr[i]);
    }
}

void initializePoly(struct point * ptr, int N) {
    int i;
    for (i=0; i<N; i++){
        ptr[i].x = -1*i;
        ptr[i].y = i*i;
    }
}