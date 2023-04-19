#include <stddef.h> // NULL
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char* solution(const char *camelCase);

int main(){
  char* test = "toLocaleLowerCA dfsd SEDFGSFGSF";
  char* reVal;
  //test = solution (test);
  reVal = solution (test);
  printf("%s \n", reVal);
  free (reVal);
  return 0;
}



//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
  char * reStr = malloc(sizeof(char)*strlen(camelCase));
  for (int i = 0; i<strlen(camelCase); i++){
    if(isupper(camelCase[i])){
      strcat(reStr, " ");
      strncat(reStr, &camelCase[i], 1);
    }
    else{
      char temp = camelCase[i];
      strncat(reStr, &camelCase[i], 1);
    }
  }

  return reStr;
}
