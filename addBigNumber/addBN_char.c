#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *strsum(const char *a, const char *b);

int main(){
	char * answer = strsum("3530743336443537693030440985766854","6228266898916465459860035972929674044878153981659961216383014361927642012583937532134906225048301812406");
	printf("%s\n", answer);

	return 0;
}

char *strsum(const char *a, const char *b)
{
    int carry = 0;
    int alen = strlen(a), blen = strlen(b);
    int longStr = alen>blen? alen:blen;
    char *tempA = calloc(longStr, sizeof(char));
    memset(tempA, 48, sizeof(char)*longStr);
    memcpy(tempA + (longStr-alen), a,alen);
    char *tempB = calloc(longStr, sizeof(char));
    memset(tempB, 48, sizeof(char)*longStr);
    memcpy(tempB + (longStr-blen), b,blen);
    printf("%s\n%s\n", tempA, tempB);
    char *rStr = calloc(alen, sizeof(char));
    for (int i = (longStr-1); i>=0; i--){
	char tempC = tempA[i]+tempB[i] - 48 + carry;
        if (tempC>=58){
        	tempC-=10;
        	carry = 1;
	}
	else
		carry = 0;
	rStr[i] = tempC;
     }

    int y = 0;
    while (rStr[y] == 48 && (strlen(rStr)-y>1)){
      y++;
      printf("y = %i\n" ,y);
    }/*
    while(rStr[0] == 48 && strlen(rStr)>1)
        rStr++;
    memset(tempA, 0, sizeof(char)*(longStr));
      */
    sprintf(tempA,"%s", rStr+y);
    return (tempA);
    //rStr[0] = tempC;
    //sprintf(rStr,"%c", tempC);
   // return rStr;
}
