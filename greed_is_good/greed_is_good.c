#include <stdio.h>
int score(const int dice[5]) ;
int main(){
	
	const int input[5] = {4,4,4,3,3};
	printf("%d", score(input));
	return 0;
}


int score(const int dice[5]) {
    int score = 0;
    int roll[6] = {0};
    for (int i = 0; i<5; i++){
      printf("%d, %d \n", roll[i] ,roll[dice[i]-1]++);
    }
    for (int i = 0; i<6; i++){
	if(roll[i]>=3){
		if (i == 0){
			score += 1000;
			roll[i] = roll[i]-3;
		}
		else{
			score += (i+1)*100;
			roll[i] = roll[i]-3;
		}
	}
	if (i == 0)
		score += roll[i]*100;
	if (i == 4)
		score += roll[i]*50;
	
    }
    //  <----  hajime!
    return score;
}

