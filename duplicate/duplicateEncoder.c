#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *DuplicateEncoder(char * str);

int main(){

  printf("%s\n", DuplicateEncoder("Peeeeeppeee"));
  return 0;
}

char *DuplicateEncoder(char * str){
  char *uniqueChar = calloc(strlen(str), sizeof(char));
  int numUniqueChar = 0;
  char *reStr = calloc(strlen(str), sizeof(char));
  int *uniqueLoc = calloc(strlen(str), sizeof(int));
  strcat(reStr, "(" );
  uniqueChar[0] = tolower(str[0]);	
  uniqueLoc[0] = 0; 
  numUniqueChar ++;
  for (int i = 1; i < strlen(str); i++){
    int flag = 0;
    char test = tolower(str[i]);

    for (int j = 0; j < numUniqueChar; j++){
      printf("%c,%c\n", uniqueChar[j], test);       
      if (uniqueChar[j] == test){
        flag = 1;
	reStr[uniqueLoc[j]] = *")";
	printf("%s,%d,%d\n", uniqueChar,uniqueLoc[j],numUniqueChar);
        break;
      }
    }
    //flag == 1 ? strcat(reStr, ")"):strcat(reStr, "(");
    if (flag == 0){
      strncat(uniqueChar, &test,1);
      strcat(reStr, "(");
      numUniqueChar++;
      printf("%d-------------\n", i);
      uniqueLoc[numUniqueChar-1] = i;

    }
    else{
      strcat(reStr, ")");
    }
  }

  return reStr;

}
