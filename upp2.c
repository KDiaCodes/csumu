#include<stdio.h>

int main (void) {
    int ar;
    printf("please input a year \n");
    scanf("%d", &ar);
    if ((ar % 400) == 0) {
        printf("skottar \n");
        return 1;
    }
    else if (((ar % 4) == 0) && ((ar % 100) != 0)) {
        printf("skottar \n");
        return 1;

    } else {
        printf("vanligt ar \n");
    }
    return 0;
    
}