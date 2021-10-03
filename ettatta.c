#include <stdio.h>
#include <stdlib.h>

int main (void) {
    float num1, num2;
    printf(" Please input a number: \n");
    scanf("%f %f", &num1, &num2);

    printf("The sum is: %f \n", num1 + num2);
    printf("The difference is: %f \n", num1 - num2);
    printf("The product is: %f \n", num1 * num2);
    printf("The ratio is: %f \n", num1/num2);

    printf("The rest is: %d \n", (int)num1%(int)num2);
    system("PAUSE");
}