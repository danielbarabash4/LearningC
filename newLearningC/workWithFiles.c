#include <stdio.h>

int main(){
  
  FILE *pFile = fopen("output.txt", "w");

  char text[] = "new text\nstill Just a check";

  if(pFile == NULL){
    printf("Error");
    return 1;
  }

  fprintf(pFile,"%s",text);
  printf("written successfully\n");


  fclose(pFile);

  return 0;
}