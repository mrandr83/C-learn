#include <stdio.h>
//add additional header files here
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <stdlib.h>
#include <string.h>

struct star {
    char name[50];
    int temperature;
    double luminosity;
    double radius;
    char classification;
};

void printStars(struct star mystars[], int N); 
//add your propotypes here
int readStars(struct star mystars[]);
void computeRadii(struct star mystars[], int N);
void classifyStars(struct star mystars[], int N);

// Do not modify the main() function!
int main(void) {
    struct star mystars[50];
    int N;

    N = readStars(mystars);
    computeRadii(mystars, N);
    classifyStars(mystars, N);
    printStars(mystars, N);

    return 0;
}

// Do not modify the printStars() function!
void printStars(struct star mystars[], int N) {
    int i;
    for (i=0; i<N; i++) {
        printf("%s is a ", mystars[i].name);
        if (mystars[i].classification == 'M') {
        	printf("Main Sequence Star\n");
        } else if (mystars[i].classification == 'G') {
            printf("Giant\n");
        } else if (mystars[i].classification == 'S') {
        	printf("Supergiant\n");
        } else if (mystars[i].classification == 'W') {
        	printf("White Dwarf\n");
        } else if (mystars[i].classification == 'N') {
        	printf("Unclassified Star\n");
        } else {
        	printf(" !!! Warning: '%c' not a valid classification code!!!\n", mystars[i].classification);
        }
        printf("Temp = %d Kelvin, Lum = %.4lf Sol, Rad = %.2lf * R_Sun\n\n", mystars[i].temperature, mystars[i].luminosity, mystars[i].radius);
    }
}

//add the functions readStars(), computeRadii() and classifyStars() here.
int readStars(struct star mystars[]) {
    int i = 0;
    FILE *fp;
    fp = fopen("stardata.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    while (fscanf(fp, "%s %d %lf", mystars[i].name, &mystars[i].temperature, &mystars[i].luminosity) != EOF) {
        i++;
    }
    fclose(fp);
    return i;
}

void computeRadii(struct star mystars[], int N) {
    int i;
    int Ts = 3500;
    for (i = 0; i < N; i++) {
        mystars[i].radius = pow(Ts/(double)mystars[i].temperature, 2) * sqrt(mystars[i].luminosity);
    }
}

void classifyStars(struct star mystars[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (mystars[i].luminosity > 0.01 && mystars[i].luminosity < 1000000 && mystars[i].radius > 0.1 && mystars[i].radius < 10) {
            mystars[i].classification = 'M';
        } else if (mystars[i].luminosity > 1000 && mystars[i].luminosity < 100000 && mystars[i].radius > 10 && mystars[i].radius < 100) {
            mystars[i].classification = 'G';
        } else if (mystars[i].luminosity > 100000 && mystars[i].luminosity < 1000000 && mystars[i].radius > 100) {
            mystars[i].classification = 'S';
        } else if (mystars[i].radius < 0.01) {
            mystars[i].classification = 'W';
        } else {
            mystars[i].classification = 'N';
        }
    }
}