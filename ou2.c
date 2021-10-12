//namn: Samuel Kenrick
//cs-id: oi21skk

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

//function that returns an array of scores to main() 
float *readScores(float *arr, int nrJudges) {
  for (int i = 1; i <= (nrJudges); i++){
    printf("Score from judge %d? ", i);
    scanf("%f", &arr[i-1]);
  }
  return arr;
}

//function that prints out each judge's score
void printScores (float *n, int nrJudges) {
  printf("\nLoaded scores:\n");
  for (int i = 1; i <= (nrJudges); i++) {
    printf("Judge %d: %.1f \n", i, n[i-1]);
  }
}

//Bubble sort to sort the array in ascending order
float *sortArray (float *a, int nrJudges) {
  int i, j;
  float temp;
  int Swap = 1;
  while (j < nrJudges && Swap == 1){
    Swap = 0;
    for (i = 0; i < (nrJudges-1); i++){
      if (a[i] > a[i+1]) {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        Swap = 1;
      }
    }
    j++;
  }  
  return a;
}

//function to first aquire the total sum of the scores (not including the largest and smallest) and print the average
void averageWeight(float *p, int nrJudges) {
  printf("Highest judge score: %.1f\n", p[nrJudges-1]);
  printf("Lowest judge score: %.1f\n", p[0]);
  float sum = 0;
  for (int i = 1; i <= (nrJudges-2); i++) {
    sum = sum + p[i];
  } 
  printf("Final average score: %.1f \n", sum/(nrJudges-2));
}

int main (void) {
  int nrJudges;
  
  //calling the start function to print the beginning text
  start();

  //setting nrJudges to the return value of the JudgeQuery function
  nrJudges = judgeQuery();

  printf("\n");
  
  float *n;
  float arr[nrJudges];
  //setting the array n to the returning array from readScores
  n = readScores(arr, nrJudges);

  //printing the scores contained in n
  printScores(n, nrJudges);

  //sorting the array in ascending order -
  float *p;
  p = sortArray(n, nrJudges);
  
  printf("\nFinal result:\n");
  
  //calling for the average, not accounting for the largest and smallest scores
  averageWeight(p, nrJudges);

  //end main()
  return 0;

}
