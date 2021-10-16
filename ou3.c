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
