#include <stdlib.h>
#include <stdio.h>
#include "stack.c"
int count_change(int money, int n_coins, const int coins[n_coins]);

int main(int argc, char ** argv){
	int coins8 [] = {2,1,5,10,20,50,3,11,6,7,8,9};
	printf("count = %d\n", count_change(419, 5, coins8));
	return 0;

}
void printState(struct curState state){
	printf("coinP = %d, sum = %d\n", state.coinPos, state.curSum);
}
int count_change(int money, int n_coins, const int coins[n_coins]){
	int comboctr = 0;
	struct Stack* stack = createStack(money*2);
	struct curState newState;
	newState.coinPos = n_coins-1;
	newState.curSum = money;
	push(stack, newState);
	while (!isEmpty(stack)){
		struct curState cState= pop(stack);
		if (cState.curSum == 0)
			++comboctr;
		else if  (cState.curSum>0){
			if (cState.coinPos > 0){
				newState = cState;
				--newState.coinPos;
				push(stack, newState);
			}
			newState = cState;
			newState.curSum -= coins[cState.coinPos];
			push(stack, newState);
		}
	}
  	return comboctr;
}

/* -----------------sudo ---------------------------
problem work out the number of combo in coins to make up a sum

combo counter = 0

push the first state into the stack

while (stack is not empty)
	curState = pop the stack
	if  sum is 0
		incresese combo by 1
	else if sum is less than 0
		do nothing
	else
		if there are other coins to check
			push curState and shift coinPos by 1

		check if sum - current coin is > 0
			push new state to the stack with new sum


*/
