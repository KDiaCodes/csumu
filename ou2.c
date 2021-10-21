#include <stdio.h>

//Start function that will say hello to the user. 
void start (void){
  printf("Program information\n");
  printf("The program reads in the number of judges and the score from each judge.\n");
  printf("Then it calculates the average score without regard to the lowest and \nhighest judge score. Finally it prints the results (the highest, the\nlowest and the final average score).\n\n");
}

//Function to ask the user how many judges they would like.
int judgeQuery (){
  int userInput;

  do{
    printf("Number of judges (min 3 and max 10 judges)? ");
    scanf("%d", &userInput);
  } while(userInput > 10 || userInput < 3);

  return userInput;
}

/*
function that returns an array of the scores to main() 
i use the array name "arr" to symbolise that im using
the array arr passed to the function.
 */
void readScores(float *arr, int nrJudges) {
  for (int i = 1; i <= (nrJudges); i++){
    printf("Score from judge %d? ", i);
    scanf("%f", &arr[i-1]);
  }
}

//function that prints out each judge's score
void printScores (float *arr, int nrJudges) {
  printf("\nLoaded scores:\n");

  for (int i = 1; i <= (nrJudges); i++) {
    printf("Judge %d: %.1f \n", i, arr[i-1]);
  }
}

//function to find the highest/lowest number and print the average (not accounting for largest or lowest)
void results(float *arr, int nrJudges, float *min, float *max, float *avg) {
  float sum;

  *min = arr[0];
  *max = arr[0];
  for (int i = 1; i < nrJudges; i++){
    if (arr[i]<*min) {
      *min = arr[i];
    }
    if (arr[i]>*max) {
      *max = arr[i];
    }
  }

  for (int i = 0; i < (nrJudges); i++) {
    sum = sum + arr[i];
  } 

  *avg = (sum - (*min + *max))/(nrJudges - 2); 
}

void printResults(float min, float max, float avg) {
  printf("\nFinal result:\n");
  printf("Highest judge score: %.1f\n", max);
  printf("Lowest judge score: %.1f\n", min);
  printf("Final average score: %.1f \n", avg);
}

int main (void) {
  int nrJudges;
  //calling the start function to print the beginning text
  start();
  //setting nrJudges to the return value of the JudgeQuery function
  nrJudges = judgeQuery();
  printf("\n"); 
  //float *n;
  float arr[nrJudges];
  //setting the array n to the returning array from readScores
  readScores(arr, nrJudges);

  //printing the scores contained in n
  printScores(arr, nrJudges);
  

  float min, max, avg;
  //calling for the average, not accounting for the largest and smallest scores
  results(arr, nrJudges, &min, &max, &avg);
  printResults(min, max, avg);

  //end main()
  return 0;
}
