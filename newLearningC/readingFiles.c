#include <stdio.h>

int main(){
  
  FILE *pFile = fopen("output.txt", "r");

  if(pFile == NULL){
    printf("Error");
    return 1;
  }

  char buffer[1024] = {0};

  while(fgets(buffer,sizeof(buffer),pFile) != NULL){
    printf("%s", buffer);
  }

  printf("\nread successfully\n");


  fclose(pFile);

  return 0;
}