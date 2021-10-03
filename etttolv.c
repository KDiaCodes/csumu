#include <stdio.h>

int main (void) {
    float usage, dist1, dist2;

    printf("Please enter the distance on your dashboard a year ago: \n");
    scanf("%f", &dist1);

    printf("Please enter the distance on your dashboard now: \n");
    scanf("%f", &dist2);

    printf("Please enter how many litres you've used this year: \n");
    scanf("%f", &usage);

    printf("You've drive %f kilometres this year. \n", dist2-dist1);
    printf("Your fuel usage has been %f litres per kilometre. \n", usage/(dist2-dist1));
    system("PAUSE");

}