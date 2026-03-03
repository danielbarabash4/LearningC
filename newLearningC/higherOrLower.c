#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
 
  srand(time(NULL));

  int min = 1;
  int max = 100;
  int guess = 0;
  int tries = 0;
  int randNum = rand() % (max - min + 1) + min;

  do{
    printf("guess a number between %d and %d : ",min ,max);
    scanf("%d",&guess);
    tries++;

    if(guess == randNum){
      printf("good job\nit took you %d tries",tries);
    } else if(guess > randNum){
      printf("try lower\n");
    } else{
      printf("try higher\n");
    }
    
  }while(guess != randNum);

  return 0;
}