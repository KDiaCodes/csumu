//unfinished

#include <stdio.h>

void start(void) {
  printf("Program information\n");
  printf("The program reads in the number of judges and the score from each judge.\n");
  printf("Then it calculates the average score without regard to the lowest and highest judge score.");
  printf("Finally it prints the results (the highest, the lowest and the final average score).\n\n");
}

int choicenr(int nr_of_judges) {
  do {

    printf("Number of judges (min 3 and max 10 judges)? ");
    scanf("%d", &nr_of_judges);

  }while (nr_of_judges < 3 || nr_of_judges > 10);
  return (nr_of_judges);
}

void scores(float score, int nr_of_judges, float n[nr_of_judges]) {
  int i;

  for ( i = 1 ; i <= nr_of_judges;) {
    printf("Score from judge %d? ", i);
    scanf("%f", &score);
    n[ i ] = score;
    i++;

  }

}

int main(void) {
  int nr_of_judges;

  start();
  nr_of_judges = choicenr(nr_of_judges);

  float score;
  float n[nr_of_judges];

  scores(score, nr_of_judges, n);




  return 0;
}
