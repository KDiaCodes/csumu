#include <stdio.h>

void start(void) {
  printf("Program information\n");
  printf("The program reads in the number of judges and the score from each judge.\n");
  printf("Then it calculates the average score without regard to the lowest and\nhighest judge score. ");
  printf("Finally it prints the results (the highest, the\nlowest and the final average score).\n");
}

int choicenr(int nr_of_judges) {
  do {

    printf("Number of judges (min 3 and max 10 judges)? ");
    scanf("%d", &nr_of_judges);

  }while (nr_of_judges < 3 || nr_of_judges > 10);

  return (nr_of_judges);
}

void scores(int nr_of_judges, float n[nr_of_judges]) {
  int i;
  printf("\n");

  for ( i = 0 ; i < nr_of_judges;) {
    printf("Score from judge %d? ", i + 1);
    scanf("%f", &n[i]);
    i++;
  }
}


void printscores(int nr_of_judges, float n[nr_of_judges]) {
  int i;

  printf("\n");
  printf("Loaded scores:\n");
  for (i = 0 ; i < nr_of_judges;) {
    printf("Judge %d: %0.1f\n", i + 1, n[i] );
    i++;

  }
}

void summa(int nr_of_judges, float n[nr_of_judges]) {

  float min, max, sum, average;
  int i;
  float * pointer_max = &max;
  float * pointer_min = &min;
  float * pointer_avr = &average;

  min = max = n[0];

  for (i = 1; i < nr_of_judges; i++) {
    if (min > n[i]) {
      min = n[i];
    }
    if (max < n[i]) {
      max = n[i];
    }
  }

  for (i = 0; i < nr_of_judges;) {
    sum = sum + n[i];
    i++;
  }

  average = (sum - (max + min)) / (nr_of_judges - 2);

  printf("\nFinal result:");

  printf("\nHighest judge score: %0.1f", *pointer_max);
  printf("\nLowest judge score: %0.1f", *pointer_min);
  printf("\nFinal average score: %0.1f\n\n", *pointer_avr);


}

int main(void) {
  int nr_of_judges = 0;


  start();

  printf("\n");

  nr_of_judges = choicenr(nr_of_judges);


  float n[nr_of_judges];



  scores(nr_of_judges, n);
  printscores(nr_of_judges, n);


  summa(nr_of_judges, n);




  return 0;
}
