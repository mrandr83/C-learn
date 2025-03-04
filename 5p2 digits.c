#include <stdio.h>
#include <stdlib.h>

struct digit {
    int num;
    struct digit *next;
};

struct digit * createDigit(int);
struct digit * append(struct digit * end, struct digit * newDigptr);
void printNumber(struct digit *);
void freeNumber(struct digit *start);
struct digit * readNumber();
int divisibleByThree(struct digit * start);
int changeThrees(struct digit * start);
struct digit * searchNumber(struct digit * start, int number);
struct digit * reverseNumber(struct digit * start);
struct digit * insertAtFront(struct digit * start, struct digit * newptr); 
struct digit * sortedCopy(struct digit * start);
struct digit * insertIntoSorted(struct digit *start, struct digit *newDig);

int main(void) {
    //! stack = showMemory(start=65520)
    struct digit *start, *ptr, *backwards, *sorted;
    int searchNum = 5;
    printf("Please enter a number: ");
    start = readNumber();
    printf("The number ");
    printNumber(start);
    if (divisibleByThree(start)) 
        printf("is divisible by 3.\n");
    else
        printf("is not divisible by 3.\n");
    ptr = searchNumber(start, searchNum);
    if (ptr!=NULL) {
        printf("Found digit %d at location %p.\n", searchNum, ptr);
    } else {
        printf("Digit %d not found.\n", searchNum);
    }
    printf("was modified in %d places.\n", changeThrees(start));
    printf("The new number is ");
    printNumber(start);
    backwards = reverseNumber(start);
    printNumber(backwards);
    sorted = sortedCopy(start);
    printNumber(sorted);
    freeNumber(sorted);
    freeNumber(start);
    freeNumber(backwards);
    
    return 0;
}

struct digit *createDigit(int dig) {
    struct digit *ptr;
    ptr = (struct digit *) malloc(sizeof(struct digit));
    ptr->num = dig;
    ptr->next = NULL;
    return ptr;
}

struct digit * append(struct digit * end, struct digit * newDigptr) {
    end->next = newDigptr;
    return(end->next);
}

void printNumber(struct digit *start) {
    struct digit * ptr = start;
    while (ptr!=NULL) {
        printf("%d", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

void freeNumber(struct digit *start) {
    struct digit * ptr = start;
    struct digit * tmp;
    while (ptr!=NULL) {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

struct digit * readNumber() {
    char c;
    int d;
    struct digit *start, *end, *newptr;
    start = NULL;
    scanf("%c", &c);
    while (c!='\n') {
        d = c - 48;
        newptr = createDigit(d);
        if (start==NULL) {
            start = newptr;
            end = start;
        } else {
            end = append(end, newptr);
        }
        scanf("%c", &c);
    }
    return start;
}

int divisibleByThree(struct digit * start) {
    struct digit * ptr = start;
    int sum = 0;
    while (ptr!=NULL) {
        sum += ptr->num;
        ptr = ptr->next;
    }
    if (sum%3==0) return 1;
    else return 0;
}

struct digit * searchNumber(struct digit * start, int number) {
    struct digit * ptr = start;
    while ((ptr!=NULL) && (ptr->num!=number)) {
        ptr = ptr->next;
    }
    return(ptr);
}

int changeThrees(struct digit * start) {
    struct digit * ptr = start;
    int count = 0;
    while (ptr!=NULL) {
        if (ptr->num==3) {
            ptr->num = 9;
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}

struct digit * insertAtFront(struct digit * start, struct digit * newptr) {
    newptr->next = start;
    return(newptr);
}

struct digit * reverseNumber(struct digit * start) {
    struct digit *ptr = start;
    struct digit *bstart = NULL;
    struct digit *newdigit;
    
    if (start!=NULL) {
        bstart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr != NULL) {
        newdigit = createDigit(ptr->num);
        bstart = insertAtFront(bstart, newdigit);
        ptr = ptr->next;
    }
    return(bstart);
}

struct digit * insertIntoSorted(struct digit *start, struct digit *newDig) {
    struct digit *ptr = start;
    struct digit *prev = NULL;
    while ((ptr!=NULL) && (ptr->num < newDig->num)) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev == NULL) {
        start = insertAtFront(start, newDig);
    } else {
        prev->next = newDig;
        newDig->next = ptr;
    }
    return(start);
}

struct digit * sortedCopy(struct digit * start) {
    struct digit *ptr = start;
    struct digit *sortedStart = NULL;
    struct digit *newDigit;
    
    if (start!=NULL) {
        sortedStart = createDigit(start->num);
        ptr = ptr->next;
    }
    while (ptr!=NULL) {
        newDigit = createDigit(ptr->num);
        sortedStart = insertIntoSorted(sortedStart, newDigit);
        ptr = ptr->next;
    }
    return(sortedStart);
}