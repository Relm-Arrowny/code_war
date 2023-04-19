#include <stdio.h>

void build_tower(unsigned n, char tower[n][2 * n - 1]);
int main(){
	int n = 3;
	char tower[n][2*n-1];
	build_tower(n, tower);
	for (int i= 0; i<n; i++){
		for (int j= 0; j<2*n-1; j++){
			printf("%c", tower[i][j]);
		}
		printf("\n");
	}
 
  return 0;
}

void build_tower(unsigned n, char tower[n][2 * n - 1])
{
	int counter = 0;
	int numStar = 2 * n - 2;

	for (int i = n-1; i >= 0; i--){
		for (int j = numStar; j>=0; j--){
			if (j<counter || j>numStar-counter){
				tower[i][j] = *" ";
			}
			else
				tower[i][j] = *"*";
			 //printf("%c\n", tower[0][0]);
		}
		counter++;

	}

}
