#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COLS 5

void printMatInLine(int* mat, int size);
void printStringLine(char* mat, int rows, int cols);

int main() {
  int data[][COLS] = {{12, 45, 67, 89, 21},
                      {34, 11, 5, 78, 90},
                      {6, 100, 43, 2, 55},
                      {19, 8, 33, 47, 10},
                      {0, 25, 71, 14, 62}};

  // printMatInLine(*data,sizeof(data)/sizeof(data[0][0]));

  // printf("\n");

  int values[4][4] = {
      {-5, 10, 0, -1}, {0, -20, 15, 8}, {30, 4, -2, 0}, {-1, 0, 0, 100}};

  // printMatInLine(*values,sizeof(values)/sizeof(values[0][0]));

  char maze[6][6] = {
      {'W', 'W', 'W', 'W', 'W', 'W'}, {'W', 'S', ' ', 'W', ' ', 'W'},
      {'W', ' ', 'W', 'W', ' ', 'W'}, {'W', ' ', ' ', ' ', ' ', 'W'},
      {'W', 'W', ' ', 'W', 'E', 'W'}, {'W', 'W', 'W', 'W', 'W', 'W'}};

  printStringLine(*maze, sizeof(maze) / sizeof(maze[0]), sizeof(maze[0]));

  char students[7][20] = {"Daniel", "Yossi", "Noa", "Amit",
                          "Galit",  "Itay",  "Maya"};

  printStringLine(*students, sizeof(students) / sizeof(students[0]),
                  sizeof(students[0]));
  return 0;
}

void printMatInLine(int* mat, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    printf("%d ", mat[i]);
  }
  printf("\n");
}

void printStringLine(char* mat, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    int count = 0;
    char* currentRow = mat + (i * cols);
    while (currentRow[count] != '\0' && count < cols) {
      printf("%c", currentRow[count]);
      count++;
    }
  }
  printf("\n");
}