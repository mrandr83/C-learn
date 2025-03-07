#include <stdio.h>

int main(void){
    FILE *gradeFile;
    double myave =0.0, tempave=0.0;
    int num = 0;
    int highest = 0;

    gradeFile = fopen("gradeComparison.txt", "r"); 

    if (gradeFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(gradeFile, "%lf", &tempave) != EOF && highest == 0) {
        if (num == 0) {
            myave = tempave;
        } else {
            if (tempave > myave) {
                highest = num+1;
                myave = tempave;
            }
        }
        num++;
    }
    if (highest == 0) {
        printf("Yes");
    } else {
        printf("No %d", highest);
    }
    
    fclose(gradeFile);
    /*int grade,numgrades,i;
    double average, total = 0;
    
    gradeFile = fopen("studentGrades.txt", "r");
    if (gradeFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fscanf(gradeFile, "%d", &numgrades);
    for(i = 0; i<numgrades; i++){
        fscanf(gradeFile, "%d", &grade);
        total += grade;
    }
    
    average = total / numgrades;
    printf("%.2lf\n", average);
    
    fclose(gradeFile);*/
    return 0;
}