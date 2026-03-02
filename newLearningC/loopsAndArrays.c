#include <stdio.h>

int main(){

int nums[5] = {0};

  for(int i = 0 ; i < 5; i++){
    printf("Choose an number: ");
    scanf("%d", &nums[i]);
  }

  for(int i = 0; i < 5; i++){
    printf("%d\n",nums[i]);
  }

  return 0;
}