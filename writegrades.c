#include <stdio.h>

int main(void) {
    FILE *ifile;  
    int num,lastgrade;;
    
    scanf("%d", &num);

    ifile = fopen("myGrades.txt", "r");  
    if (ifile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }  
    while (fscanf(ifile, "%d", &lastgrade) != EOF); 
    fclose(ifile);
    
    if(lastgrade != num) {
        ifile = fopen("myGrades.txt", "a"); 
        fprintf(ifile, "\n%d", num);
        fclose(ifile);
    }
    ifile = fopen("myGrades.txt", "r");
    while (fscanf(ifile, "%d", &lastgrade) != EOF){
        printf("%d ", lastgrade);
    }
    fclose(ifile);
    return(0);
}