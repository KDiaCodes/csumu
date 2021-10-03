#include <stdio.h>

int main (void) {
    int num1, num2;
    
    scanf("%d", &num1);
    scanf("%d", &num2);
    
    if (num1 == num2) {
        printf("bich \n");
    }
    else if (num1 > num2) {
        printf("emils a bich \n");
    }
    else {
        printf("Krijg de tyfus. \n");
    }
    system("PAUSE");
}