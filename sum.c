#include <stdio.h>

int main(){
  int a, sum = 0;  
  
  printf("Please enter a number:\n");
  scanf("%d", &a);

  sum = a + 3;
  
  printf("%d\n", sum);
  return(0);
}