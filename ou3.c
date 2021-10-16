#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIVE 'X'
#define DEAD '.'

typedef struct {
  char current;
  char next;
} cell;

void initField (const int rows, const int cols, cell field[rows][cols]);
void clearField(const int rows, const int cols, cell field[rows][cols]);
void loadGlider(const int rows, const int cols, cell field[rows][cols]);
void loadSemaphore(const int rows, const int cols, cell field[rows][cols]);
void loadRandom(const int rows, const int cols, cell field[rows][cols]);
void loadCustom(const int rows, const int cols, cell field[rows][cols]);
char getStartStateChoice(void);

int main(void){
  int rows = 20;
  int cols = 20;
  cell field[rows][cols];
  initField(rows, cols, field);
  printf("Select one of the following options:");
  printf("(enter) Step\n");
  printf("(any) Exit\n");
  int ch = getchar();
  return 0;
}

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

void cleadField(const int rows, const int cols, cell field[rows][cols]){
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      field[r][c].current = DEAD;
    }
  }
}
void loadGlider(const int rows, const int cols, cell field[rows][cols]){
  field[0][1].current = ALIVE;
  field[1][2].current = ALIVE;
  field[2][0].current = ALIVE;
  field[2][1].current = ALIVE;
  field[2][2].current = ALIVE;
}
void loadSemaphore(const int rows, const int cols, cell field[rows][cols]){
  field[8][1].current = ALIVE;
  field[8][2].current = ALIVE;
  field[8][3].current = ALIVE;
}
void loadRandom(const int rows, const int cols, cell field[rows][cols]){
  
}
void loadCustom(const int rows, const int cols, cell field[rows][cols]){
  int r, c;
  
  printf("Give custom format string: ");
  do {
    scanf("%d,%d", &r, &c);
    field[r][c].current = ALIVE;
  } while (getchar() != '\n');
}
