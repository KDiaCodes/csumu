#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIVE 'X'
#define DEAD '.'

typedef struct {
  char current;
  char next;
} cell;

void initField(const int rows, const int cols, cell field[rows][cols]);
void printGame(const int rows, const int cols, cell field[rows][cols]);
void nextGen(const int rows, const int cols, cell field[rows][cols]);
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
  int exit = 0;
  while (exit == 0) {
    
    printGame(rows, cols, field);
    nextGen(rows, cols, field);
    printf("Select one of the following options:\n");
    printf("(enter) Step\n");
    printf("(any) Exit\n");
    char ch = (char)getchar();
    if (ch != '\n'){
      exit = 1;
    } /*else {
      nextGen(rows, cols, field);
    }*/
  }

  return 0;
}

void printGame(const int rows, const int cols, cell field[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", field[i][j].current);
    }
    printf("\n");
  }
}
void nextGen(const int rows, const int cols, cell field[rows][cols]){
  int liveNeighbours = 0;
  for (int k = 0; k < rows; k++) {
    for (int l = 0; l < cols; l++) {
      liveNeighbours = 0;
      for (int r = k-1; r <= (k+1); r++) {
        for (int c = l-1; c <= (l+1); c++) {
          if (r == k && c == l) continue;
          if (r < 0 || c < 0 || r >= rows || c >= cols) continue;
          if (field[r][c].current == ALIVE)liveNeighbours++;
        }
      }
      
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
  for (int n = 0; n < rows; n++) {
    for (int m = 0; m < cols; m++) {
      field[n][m].current = field[n][m].next;
    }
  }



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

void clearField(const int rows, const int cols, cell field[rows][cols]){
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
