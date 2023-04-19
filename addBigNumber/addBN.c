#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
char *add(const char *a, const char *b);

int main(){
	
  	char *str;
	str = add("8451673704713145838580976",
			"89");

	printf("%s\n8451673704713145838581065",str);
	return 0;
}


char *add(const char *a, const char *b) {
	
  	int alen =  strlen(a);		//get string size
  	int blen = strlen(b);  
	int retStrlen = 0;
	retStrlen = alen>blen ?  alen : blen ;    //set the size of the Str
	char * rStr = calloc (retStrlen,sizeof(char));	//set aside mem
	char * tempStr = calloc(17, sizeof(char));
	char *str1 = calloc(17, sizeof(char));
        char *str2 = calloc(17, sizeof(char));
        char *eptr = NULL;                     //pointer needed for str to long long
        int base;                       //base elemeent for str to long long
	float cPerRead = 17.0;
	int carry = 0;

	for (int i = 1; i<=(int) ceil(retStrlen/cPerRead); i++){
		memset(str1, 0, 17);
		memset(str2, 0, 17);
		memset(tempStr,0,17);
		if (floor(alen/cPerRead)>=i){
			memcpy(str1, a + (alen-i*(int)cPerRead), sizeof(char)*cPerRead);
		}
		else if ((int)floor(alen/cPerRead)-i == -1){
			memcpy(str1, a, sizeof(char)*alen-(int)(floor(alen/cPerRead)*cPerRead));
		}
		else 
			memset(str1, 0, sizeof(char)*cPerRead);


                if (floor(blen/cPerRead)>=i){
                        memcpy(str2, b + (blen-i*(int)cPerRead), sizeof(char)*cPerRead);
                }
                else if ((int)floor(blen/cPerRead)-i == -1){
                        memcpy(str2, b, sizeof(char)*blen-(floor(blen/cPerRead)*cPerRead));
                }
                else
                        memset(str2, 0, sizeof(char)*cPerRead);
		
		int cA = 0;
		while(*(str1+cA) == 0x30){
			printf("%x \n", *str1);	
			cA++;
		}
                int cB = 0;
                while(*(str2+cA) == 0x30){
                        printf("%x \n", *str2);
                        cB++;
                }
		unsigned long long v = strtoull(str1+cA, &eptr, base);
        	unsigned long long y = strtoull(str2+cB, &eptr, base);
                printf("%llu + %llu  %llu \n", v,  y,  v+y);
		v = v + y;
		if (carry){
			v = v +1;
			carry = 0;
			tempStr = strdup(rStr+1);
		}
		else
			 tempStr = strdup(rStr);
		
		if (v >= 1e17 && i!= (int) ceil(retStrlen/cPerRead)){
			carry = 1;
			//v = v;// - 1e17;
		}
		
		char temp[3] = "";
		if(strlen(str1)!=strlen(str2)){
			for(int j = 0; j<(cA>cB? cA:cB); j++){
				strcat(temp, "0");
			}
		}
                //tempStr = strdup(rStr+1);
		sprintf(rStr,"%s%llu",temp, v);
		strcat(rStr, tempStr);
		printf("%s\n", rStr);
	}
	free(tempStr);
        free(str1);
        free(str2);
  return rStr;
}
