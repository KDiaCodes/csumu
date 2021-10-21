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
int checkNeighbours(const int rows, const int cols, cell field[rows][cols], int currentRow, int currentCol);
void updateCurrent(const int rows, const int cols, cell field[rows][cols]);
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
  
  // defining a variable to keep our loop active for displaying future generations
  char ch;
  //defining a do while loop we want to keep running as long as the user asks for the next generation.
  do {
    
    // printing this generation and setting the next one
    printGame(rows, cols, field);
    nextGen(rows, cols, field);
    updateCurrent(rows, cols, field);
    
    // asking whether to print a next generation or not
    printf("Select one of the following options:\n");
    printf("(enter) Step\n");
    printf("(any) Exit\n");
    ch = (char)getchar();

  } while (ch == '\n');

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
  // looping through, printing every positions value along the row before going to the next row
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
 * Output:      The field array's next values are determined.
 */
void nextGen(const int rows, const int cols, cell field[rows][cols]){
  
  // defining a variable to keep track of how many neighbours are alive
  int liveNeighbours;
  // these two for loops are to go through our entire field position by position.
  for (int currentR = 0; currentR < rows; currentR++) {
    for (int currentC = 0; currentC < cols; currentC++) {

      
      liveNeighbours = checkNeighbours(rows, cols, field, currentR, currentC);
      
      // the conditions for whether to change the current square's value
      switch (liveNeighbours) {
        case 2:
          field[currentR][currentC].next = field[currentR][currentC].current;
          break;
        case 3:
          field[currentR][currentC].next = ALIVE;
          break;
        default:
          field[currentR][currentC].next = DEAD;
      }
    }
  }
}

/* Function:    checkNeighbours
 * Description: checks how many of the closest neighbours are alive
 *              and returns the amount to the nextGen funtction 
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 *              currentRow - the current positions row value
 *              currentCol - the current positions column value
 * Output:      The field array's current values change to the next generation's.
 */
int checkNeighbours(const int rows, const int cols, cell field[rows][cols], int currentRow, int currentCol){
  int liveNeighbours = 0;

  /* these two for loops check a 3x3 section in our array with k and l as the centre position
  *  the localR variable checks for the current row, above row and below row for the current position
  *  the localC variable checks for the current column, above column and below column for the current position
  */
  for (int localR = currentRow-1; localR <= (currentRow+1); localR++) {
    for (int localC = currentCol-1; localC <= (currentCol+1); localC++) {

      // if the square we are checking is outside the array or is the centre-piece we skip it
      if (localR < 0 || localC < 0 || localR >= rows || localC >= cols || (localR == currentRow && localC == currentCol)) continue;
      
      // if its a valid square and it is alive, add 1 to liveNeighbours
      if (field[localR][localC].current == ALIVE)liveNeighbours++;
    }
  }
  return liveNeighbours;
}

/* Function:    updateCurrent
 * Description: updates all the values of each position to the next generation's simultaneously
 * Input:       rows - the number of rows in the field
 *              cols - the number of columns in the field
 *              field - the field array
 * Output:      The field array's current values change to the next generation's.
 */
void updateCurrent(const int rows, const int cols, cell field[rows][cols]){
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      field[r][c].current = field[r][c].next;
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
  // shouldnt ch be a char?
  
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
  
  // declaration for the random number
  srand(time(NULL));

  // two for loops to go through each position in our array
  for (int p = 0; p < rows; p++) {
    for (int q = 0; q < cols; q++) {
      
      // resetting the random number and generating either the number 1 or 0    
      int state = (rand() & 1);

      // if the number is 1 set the position to ALIVE. Otherwise set to DEAD.
      if (state == 1) {
        field[p][q].current = ALIVE;
      } else {
        field[p][q].current = DEAD;
      }

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
