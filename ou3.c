#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants, representation of states
#define ALIVE 'X'
#define DEAD '.'

// Declaration of data structure for our array field
typedef struct {
  char current;
  char next;
} cell;

// Declaration of functions
void initField(const int rows, const int cols, cell field[rows][cols]);
void printGame(const int rows, const int cols, cell field[rows][cols]);
void nextGen(const int rows, const int cols, cell field[rows][cols]);
void clearField(const int rows, const int cols, cell field[rows][cols]);
void loadGlider(const int rows, const int cols, cell field[rows][cols]);
void loadSemaphore(const int rows, const int cols, cell field[rows][cols]);
void loadRandom(const int rows, const int cols, cell field[rows][cols]);
void loadCustom(const int rows, const int cols, cell field[rows][cols]);
char getStartStateChoice(void);

/* Function:    main
 * Description: Start and run simulations, interact with the user.
 *              Lets the user choose initial structure and whether to step
 *              or exit. Writes information to the user, and the game field
 *              in each step.
 */

int main(void){
  
  // defining the field and field size
  int rows = 20;
  int cols = 20;
  cell field[rows][cols];

  // initiating the menu
  initField(rows, cols, field);
  
  /* defining a variable to keep
  our loop active for displaying future generations */
  int exit = 0;
  while (exit == 0) {
    
    // printing this generation and setting the next one
    printGame(rows, cols, field);
    nextGen(rows, cols, field);
    
    // asking whether to print a next generation or not
    printf("Select one of the following options:\n");
    printf("(enter) Step\n");
    printf("(any) Exit\n");
    char ch = (char)getchar();

    // checking if the person chose to continue or not
    if (ch != '\n'){
      exit = 1;
    }
  }

  return 0;
}

/* Function:    printGame
 * Description: prints the current generation of the structure 
 *              the user selected
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      Nothing outputed except text to screen.
 */
void printGame(const int rows, const int cols, cell field[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", field[i][j].current);
    }
    printf("\n");
  }
}

/* Function:    inextGen
 * Description: finds how many neighbours are alive and changes
 *              based off of that amount.
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array's current and next values change.
 */
void nextGen(const int rows, const int cols, cell field[rows][cols]){
  
  // defining a variable to keep track of how many neighbours are alive
  int liveNeighbours = 0;

  // first two for loops are for the square we are maybe looking to change
  for (int k = 0; k < rows; k++) {
    for (int l = 0; l < cols; l++) {

      // resetting
      liveNeighbours = 0;

      //these two for loops check a 3x3 section in our array
      for (int r = k-1; r <= (k+1); r++) {
        for (int c = l-1; c <= (l+1); c++) {

          //if the square we are checking is outside the array or is the centre-piece we skip it
          if (r < 0 || c < 0 || r >= rows || c >= cols || (r == k && c == l)) continue;

          // if its a valid square and it is alive, add 1 to liveNeighbours
          if (field[r][c].current == ALIVE)liveNeighbours++;
        }
      }
      
      // the conditions for whether to change the current square's value
      if (liveNeighbours <= 1) {
        field[k][l].next = DEAD;
      } else if ((liveNeighbours == 2) && (field[k][l].current == ALIVE)) {
        field[k][l].next = ALIVE;
      } else if ((liveNeighbours == 2) && (field[k][l].current == DEAD)) {
        field[k][l].next = DEAD;
      } else if (liveNeighbours == 3) {
        field[k][l].next = ALIVE;
      } else if (liveNeighbours >= 4) {
        field[k][l].next = DEAD;
      }
      
    }
  }

  //setting each square to its new value simultaneously
  for (int n = 0; n < rows; n++) {
    for (int m = 0; m < cols; m++) {
      field[n][m].current = field[n][m].next;
    }
  }



}

/* Function:    initField
 * Description: Loads a structure that the user selects
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated.
 */

void initField(const int rows, const int cols, cell field[rows][cols]) {
  char choice;
  clearField(rows, cols, field);
  choice = getStartStateChoice();
  
  switch (choice){
    case 'g':
    case 'G':
      loadGlider(rows, cols, field);
      break;
    case 's':
    case 'S':
      loadSemaphore(rows, cols, field);
      break;
    case 'r':
    case 'R':
      loadRandom(rows, cols, field);
      break;
    case 'c':
    case 'C':
    default:
      loadCustom(rows, cols, field);
      break;
  }
}

/* Function:    getStartStateChoice
 * Description: Lets the user choose starting state
 * Input:
 * Output:      The users choice. Should be one of the letters G,S,R or C.
 */
char getStartStateChoice(void){
  int ch;
  //shouldnt ch be a char?
  
  printf("Select field spec to load ([G]lider, [S]emaphore, [R]andom ");
  printf("or [C]ustom): ");
  
  ch = getchar();
  if (ch != '\n') {
    getchar();
  }
  return ch;
}

/* Function:    clearField
 * Description: Initialize all the cells in the field to dead
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated.
 */
void clearField(const int rows, const int cols, cell field[rows][cols]){
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      field[r][c].current = DEAD;
    }
  }
}

/* Function:    loadGlider
 * Description: Inserts a glider into the field.
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated.
 */
void loadGlider(const int rows, const int cols, cell field[rows][cols]){
  field[0][1].current = ALIVE;
  field[1][2].current = ALIVE;
  field[2][0].current = ALIVE;
  field[2][1].current = ALIVE;
  field[2][2].current = ALIVE;
}

/* Function:    loadSemaphore
 * Description: Inserts a semaphore into the field.
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated.
 */

void loadSemaphore(const int rows, const int cols, cell field[rows][cols]){
  field[8][1].current = ALIVE;
  field[8][2].current = ALIVE;
  field[8][3].current = ALIVE;
}

/* Function:    loadRandom
 * Description: Inserts a random structure into the field.
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated. There is a 50 % chance that a cell
 *              is alive.
 */
void loadRandom(const int rows, const int cols, cell field[rows][cols]){
  for (int p = 0; p < rows; p++) {
    for (int q = 0; q < cols; q++) {

    }
  }
}

/* Function:    loadCustom
 * Description: Lets the user specify a structure that then is inserted into
 *              the field.
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array is updated.
 */
void loadCustom(const int rows, const int cols, cell field[rows][cols]){
  int r, c;
  
  printf("Give custom format string: ");
  do {
    scanf("%d,%d", &r, &c);
    field[r][c].current = ALIVE;
  } while (getchar() != '\n');
}
