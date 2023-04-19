#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
char* decompose(long long n);
int findDecompose(long long num,long long maxTry,  char* answer);

int main (){
	
printf("%s \n", decompose(10));
	return 0;

}


char* decompose(long long n) {
    // your cod
	char *rStr = calloc(n, sizeof(char));
	memset(rStr+n-1, '\0',1);
	long long nSq = (n*n);
	findDecompose(nSq, n-1, rStr);
	//rStr[0]="1";
        //sprintf(rStr,"[%s]",temp);
	char *temp = calloc(strlen(rStr), sizeof(char));     
	memcpy (temp, rStr, strlen(rStr));
	sprintf(rStr,"[%s]",temp);
	free(temp);

	return rStr;
}


int findDecompose(long long num,long long maxTry,  char* answer){
	long long nSq =maxTry*maxTry;
	long long newNum = num-nSq;
	printf("%lli, %lli\n", newNum, maxTry);
	if (newNum == 0){
		
		sprintf(answer,"%lli", maxTry);
		printf("%s", answer);
		return 1;
	}
	if (newNum ==1){
		sprintf(answer,"%i,%lli", 1,maxTry);
                printf("%s\n", answer);
                return 1;
	}
	if (maxTry == 1)
		return 0;
	long long newSqrt = floor(sqrt(newNum));
	if (newSqrt >= maxTry)
		newSqrt = maxTry-1;
	printf("%lli, %lli-------\n", newSqrt, maxTry);
	for (int i = newSqrt; i>1; i--){
		
		if (findDecompose(newNum, i, answer)){
			char temp[20];
			sprintf(temp,",%lli", maxTry);
			strcat(answer, temp);
			printf("%s--------------\n", answer);
			return 1;
		}
	
	}
	return 0;
}

