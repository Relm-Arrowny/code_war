#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool checkEnd(int rowsLow, int rowsHi, int colsLow, int colsHi);
int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols);
int main (int argc, char* argv [] ){
	size_t outsz = 0;
		
	const int mx[4][4] = { {1,2,3,1}, {4,5,6,4}, {7,8,9,7}, {7,8,9,7} };

	int **cells;
	
	cells = malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; i++) {
		*(cells + i) = malloc(3 * sizeof(int));
	}
	**cells = 1;
	*(*cells + 1) = 2;
	*(*cells + 2) = 3;
	*(*cells + 3) = 4;
	**(cells + 1) = 12;
	*(*(cells + 1) + 1) = 13;
	*(*(cells + 1) + 2) = 14;
	*(*(cells + 1) + 3) = 5;
	**(cells + 2) = 11;
	*(*(cells + 2) + 1) = 16;
	*(*(cells + 2) + 2) = 15;
	*(*(cells + 2) + 3) = 6;
        **(cells + 3) = 10;
        *(*(cells + 3) + 1) = 9;
        *(*(cells + 3) + 2) = 8;
        *(*(cells + 3) + 3) = 7;

	int *result;
	result = snail(&outsz, cells, 4,4);
	for (int i = 0; i<outsz; i++){
		printf("%d,", result[i]);
	}
	printf("%ld", outsz);
	return 0;
}


int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  // The numbers of rows and cols are passed separately for historical reasons
  // Return a heap allocated array, report the size in *outsz
	*outsz = rows*cols;
	int rowsLow = 0;
	int rowsHi  = rows-1;
	int colsLow = 0;
	int colsHi  = cols -1;
	int* result = calloc(*outsz, sizeof(int));
	memset(result, 0, sizeof(result));
	int ctr = 0;
	while(ctr < *outsz){
		for (int i = colsLow; i<=colsHi; i++){
			*(result+ctr) = mx[rowsLow][i];
			printf("%d", result[ctr]);
			++ctr;
		}
		printf("\n%d\n", ctr);
		++rowsLow;
		for (int i = rowsLow; i<=rowsHi; i++){
                        *(result+ctr) = mx[i][colsHi];
                        printf("%d", result[ctr]);
                        ++ctr;
                }
                --colsHi;

		for (int i = colsHi; i>=colsLow; --i){
                        *(result+ctr) = mx[rowsHi][i];
                        printf("%d", result[ctr]);
                        ++ctr;
                }
                printf("\n%d\n", ctr);
                --rowsHi;

                for (int i = rowsHi; i>=rowsLow; --i){
                        *(result+ctr) = mx[i][colsLow];
                        printf("%d", result[ctr]);
                        ++ctr;
                }
                ++colsLow;
	}
	
  	return result;
}



/*--------------sudo----------------------
rowsLow = 0
rowsHi  = rows-1
colsLow = 0
colsHi  = cols -1
output array with size  = rows*cols

while (rowsHi - rowsLow >=0 && colsHi -colsLow >= 0)

	going from top left to  top right add the roll to output
	starting from colsLow and end at colsHi
	increase  rowLow by 1
	check if  exsit condition

	going from top right to bottom right add all cols to output
	start from rowsLow to rolsHi
	decrease colsHi by 1
	check exist condition

	going from bottom right to   bottom left
	s colshi to colsLow
	decrease rowHi by 1
	check exist condition

	going from bottom left to top lef
	s rowsHi to rowsLow
	increase colsLow by 1

return output array

*/ 

