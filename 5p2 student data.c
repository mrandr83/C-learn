#include <stdio.h>
#include <stdlib.h>
//it should really be like this
//#include <string.h>

struct student {
      char name[50];
      int age;
      struct student *next;
};

struct student *createStudent(char studentName[], int studentAge);
struct student *append(struct student * end, struct student * newStudptr); 
void printStudents(struct student *start);
void freeStudents(struct student *start);

int main(void) {
    struct student *start, *newStudptr, *end, *tmp;
    int ageP, ageR, ageM;

    scanf("%d %d %d", &ageP, &ageR, &ageM);

    start = createStudent("Petra", ageP);
    end = start;
    
    newStudptr = createStudent("Remi", ageR);
    end = append(end, newStudptr);
    
    newStudptr = createStudent("Mike", ageM);
    end = append(end, newStudptr);

    printStudents(start);
    freeStudents(start);

    return 0;
}

// Write your createStudent function here (and any other functions you see fit)
struct student *createStudent(char studentName[], int studentAge)
{
    struct student *ptr;
    int i;
    ptr = (struct student *)malloc(sizeof(struct student));
    // Copy characters from studentName to ptr->name
    for (i = 0; studentName[i] != '\0'; i++) {
        ptr->name[i] = studentName[i];
    }
    ptr->name[i] = '\0'; // Null-terminate the string
    
    //strcpy(ptr->name, studentName);
    ptr->age = studentAge;
    ptr->next = NULL;
    return(ptr);
}

struct student *append(struct student * end, struct student * newStudptr)
{
    end->next = newStudptr;
    end = newStudptr;
    return(end);
}

void printStudents(struct student *start)
{
    while (start != NULL) {
        printf("%s is %d years old.\n", start->name, start->age);
        start = start->next;
    }
}

void freeStudents(struct student *start)
{
    struct student * tmp;
    while (start != NULL) {
        tmp = start->next;
        free(start);
        start = tmp;
    }
}