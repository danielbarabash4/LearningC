#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

typedef enum {
  OVERWORLD = 1,
  NETHER = 2,
  END = 3
}Biome;

typedef struct {
  Biome world;
  int xNum;
  int yNum;
  char description[SIZE];
} Coordinate;

const char* BiomeNames[] = {"", "OverWorld", "Nether", "End"};

Coordinate* getCoordinate();
void writeInFile(const char* fName);
void readFromFile(const char* fName);

int main() {
  const char* BiomeNames[] = {"", "OverWorld", "Nether", "End"};
  const char *fName = "minecraftCoordinates.bin";
  int choose = 0;

  do{
    printf("Choose an option:\n[1] add a new coordinate\n[2] read the coordinates\n[0] exit\nyour option: ");
    scanf(" %d", &choose);
    switch (choose){
      case 1:
      writeInFile(fName);
    break;
      case 2:
      printf("reading...\n");
      readFromFile(fName);
    break;
    default:
      break;
    }
  }while(choose != 0);
  

  // Coordinate* newCoor = getCoordinate();
  // const char *fName = "minecraftCoordinates.bin";
  // writeInFile(newCoor);

  // free(newCoor);
  // newCoor = NULL;

  return 0;
}

Coordinate* getCoordinate(){
  Coordinate *newCoor = malloc(sizeof(Coordinate));

  if(newCoor == NULL){
    printf("problem allocing memory");
    return NULL;
  }

  char desc[SIZE] = "\0";

  printf("1 - OverWorld\n2 - nether\n3 - end\nChoose biome: ");
  scanf(" %d",&newCoor->world);

  printf("Choose X coordinate: ");
  scanf(" %d",&newCoor->xNum);

  printf("Choose Y coordinate: ");
  scanf(" %d",&newCoor->yNum);

  getchar();
  printf("describe the place: ");
  fgets(desc,sizeof(desc),stdin);
  strcpy(newCoor->description,desc);

  return newCoor;
}

void writeInFile(const char* fName){
  Coordinate* Coor = getCoordinate();
  
  FILE *pFile = fopen(fName,"ab");

  if(pFile == NULL){
    printf("Error opening file");
    return;
  }

  fwrite(Coor,sizeof(Coordinate),1,pFile);
  fclose(pFile);

  free(Coor);
  Coor = NULL;
}

void readFromFile(const char* fName){
  FILE *pFile = fopen(fName,"rb");

  if (pFile == NULL){
    printf("Error opening file");
    return;
  }

  Coordinate temp;

  while(fread(&temp,sizeof(Coordinate),1,pFile) != 0){
    printf("%d,%d - %s, %s",temp.xNum,temp.yNum,BiomeNames[temp.world],temp.description);
  }
  fclose(pFile);
}