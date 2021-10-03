#include <stdio.h>
#include <stdlib.h>

int main (void) {
    float forbruk, avstand1, avstand2;

    printf("Please enter how many liters were used up this year:\n");
    scanf("%f", &forbruk);

    printf("Please enter the distance on your dashboard from a year ago:\n");
    scanf("%f", &avstand1);

    printf("Please enter the distance on your dashboard now:\n");
    scanf("%f", &avstand2);

    printf("The distance you have traveled is: %5.3f kilometres. \n", avstand2 - avstand1);
    printf("The fuel usage is: %5.4f liters per kilometre. \n", forbruk/(avstand2-avstand1));

    system("PAUSE");
}