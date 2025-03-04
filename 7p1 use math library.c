#include <stdio.h>
#include <math.h> // to include math.h I had to add "-lm" in tasks.json under args

int main(void) {
    int input;
    double output;
    scanf("%d", &input);
    output = sqrt(input);
    printf("%.8lf\n", output);
    printf("%.10lf\n", exp(1));
    // this is what I have to use in the crappy "Weblinux" terminal
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra -lm -o .c\n");

    return 0;
}

/* activity "using the JPEG library
#include <stdio.h>

int main(void){
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra -ljpeg vizplus.c -o vizplus\n");
    return 0;
}
*/