#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *range_extraction(const int *args, size_t n);


int main(){
	int input[] =  { -3 };
	printf("%s", range_extraction(input, 1ul));
	return 0;

}


char *range_extraction(const int *args, size_t n)
{
	char * rStr = calloc(n*2+1, sizeof(char));
	int consec = 0;
	char temp[5];
	for(int i = 0; i < n-1; i++){
		if (consec == 0){
			sprintf(temp, "%i", args[i]);
			strcat(rStr, temp); 
			consec++;

		}
		
		while(consec > 0 && i < n-1){
			printf("%s -----%i\n", rStr, consec);
			if(abs( args[i] - args[i+1]) == 1){
				consec++;
				i++;
			}
			else {
				if (consec == 1){
					printf("%i \n", args[i+1]);
				 	sprintf(temp, ",");
                        	 	strcat(rStr, temp);
					consec = 0;
				}
				else if(consec == 2){
					sprintf(temp, ",%i,", args[i]);
                                        strcat(rStr, temp);
					consec = 0;
				}
				else{
                                        sprintf(temp, "-%i,", args[i]);
                                        strcat(rStr, temp);
                                        consec = 0;
				}
			}
		}
	}
	if (n==1)
		sprintf(temp, "%i", args[n-1]);
	else
		consec >2? sprintf(temp, "-%i", args[n-1]):sprintf(temp, ",%i", args[n-1]);
        strcat(rStr, temp);
    	return rStr;
}

