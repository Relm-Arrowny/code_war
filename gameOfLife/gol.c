#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void htmlize (int **, int, int);
int **get_generation (int **cells, int generations, int *rowptr, int *colptr);
void freeArray(int **, int);
int **updateInnerCell(int **cell, int *row, int *col);
int main(){

	int **cells;
	cells = malloc(3 * sizeof(int *));
	for (int i = 0; i < 3; i++) {
		*(cells + i) = malloc(3 * sizeof(int));
	}

	**cells = 1;
	*(*cells + 1) = 1;
	*(*cells + 2) = 1;
	**(cells + 1) = 0;
	*(*(cells + 1) + 1) = 0;
	*(*(cells + 1) + 2) = 0;
	**(cells + 2) = 0;
	*(*(cells + 2) + 1) = 0;
	*(*(cells + 2) + 2) = 0;

	htmlize(cells,3,3);
	printf("---------------\n");
	int row = 3;
	int col = 3;
	int **newCells = cells;
	printf("---------------\n");

	newCells = get_generation(newCells,3, &row, &col);
	htmlize(newCells,row,col);
	printf("-------Final---%d,%d-----\n",row,col);

	freeArray(newCells,row);
	//freeArray(cells,3);

}

void htmlize (int ** cell, int y, int x){
	
	for (int j = 0; j<y; ++j){
		for (int i = 0;  i<x; ++i){
			printf("%i ", cell[j][i]);
		}
		printf("\n"); 
	}
	printf("--------------------\n");

}
void freeArray(int **array, int row){

	for (int i = 0; i < row; i++){
                free(array[i]);
        }
        free(array);
}

int **get_generation (int **cells, int generations, int *rowptr, int *colptr)
{
  	
	int **newCells = cells;
        printf("---------------\n");
        for (int i = 0; i<generations; ++i){
		newCells = updateInnerCell(newCells,rowptr,colptr);
		htmlize(newCells,*rowptr,*colptr);
		printf("-------end---%d,%d-----\n",*rowptr,*colptr);
	}
	
	return newCells;
 

	
}

int **updateInnerCell(int **cell, int *row, int *col){
	int sum = 0;
	
	int ** newCells;
	
	newCells = calloc(*row+2,sizeof(int*));
	for (int i = 0; i < *row+2; i++) {
		*(newCells+i) = (int*)calloc(*col+2,sizeof(int)); 
	}
	htmlize(cell,*row,*col);
	int *flag = NULL;
	flag = calloc(4,1);
	for (int x = 0; x<*col; ++x){
		for (int y = 0; y<*row; ++y){
			//All the centre bits
			if (x>0  && y>0 && x<*col-1 && y<*row-1){
				sum =  cell[y-1][x-1]+cell[y-1][x]+cell[y-1][x+1]+
				       cell[y][x-1]+cell[y][x+1]+
				       cell[y+1][x-1]+cell[y+1][x]+cell[y+1][x+1];
			}
			//deal with single point
			else if(*col==1 && *row ==1);// do nothing and  there will be no life.
			//deal with 1d
			else if(*col ==1){
				if (y==0)
					sum = 0;
				else if(y==*row-1)
					sum = 0;
				else{
					sum = cell[y-1][0]+cell[y+1][0];
					 if  ((sum+cell[y][0]) ==3){
						newCells[y+1][0] = 1;
						newCells[y+1][2] =1;
	                                        *flag |= 1UL;
	                                        *flag |= 1UL<<1;
                                         }
				}
				printf("%d", sum);
			}
			else if(*row == 1){
                                if (x!=0 && x!= *col-1){
			                sum = cell[0][x-1]+cell[0][x+1];
                        	        if  ((sum+cell[0][x]) ==3){
					         newCells[0][x+1] = 1;
	                                         newCells[2][x+1] = 1;
	                                         *flag |= 1UL<<2;
		                                 *flag |= 1UL<<3;
                                        }
				}//else does nothing
		        }
			//top left corner
			else if (x==0 && y ==0){
				sum = cell[1][0]+cell[1][1]+cell[0][1];

			}
			//top right corner
                        else if (x==*col-1 && y ==0){
                                sum = cell[1][x]+cell[1][x-1]
				     +cell[0][x-1];

                        }
			//bottom left corner
			else if (x==0 && y == *row-1){
                                sum = cell[y-1][x]+cell[y-1][x+1]
                                     +cell[y][x+1];

                        }
			//bottom right corner
			else if (x==*col-1 && y ==*row-1){
                                sum = cell[y-1][x-1]+cell[y-1][x]+
				      cell[y][x-1];

                        }

			//left side without top/bottom row
			else if (x == 0 && y>0 && y<*row-1){
				sum =  cell[y-1][x]+cell[y-1][x+1]+
                                       cell[y][x+1]+
                                       cell[y+1][x]+cell[y+1][x+1];
				int lifeCounter = 0;
				for (int i = -1; i<2; ++i){
					lifeCounter += cell[y+i][x];
				}
				if  (lifeCounter ==3){
					newCells[y+1][x] = 1;
					*flag |= 1UL;
				}
			}

			//right side without top/bottom row
			else if (x == *col-1 && y>0  && y<*row-1){
                                sum =  cell[y-1][x]+cell[y-1][x-1]+
                                       cell[y][x-1]+
                                       cell[y+1][x]+cell[y+1][x-1];


				int lifeCounter = 0;
                                for (int i = -1; i<2; ++i){
                                        lifeCounter += cell[y+i][x];
                                }
                                if  (lifeCounter ==3){
					*flag |= 1UL<<1;
					newCells[y+1][x+2] = 1;
				}
                        }

			//Top row without left/right col
                        else if (y == 0 && x>0  && x<*col-1){
                                sum =  cell[y][x-1] + cell[y][x+1]+
                                       cell[y+1][x-1] + cell[y+1][x]+cell[y+1][x+1];

				int lifeCounter = 0;
                                for (int i = -1; i<2; ++i){
                                        lifeCounter += cell[y][x+i];
                                }
                                if  (lifeCounter ==3){
                                        *flag |= 1UL<<2;
					newCells[y][x+1] = 1;
				}

                        }
			//Bottow row without left/right col
                        else if (y == *row-1 && x>0  && x<*col-1){
                                sum =  cell[y][x-1] + cell[y][x+1]+
                                       cell[y-1][x-1] + cell[y-1][x]+cell[y-1][x+1];

				int lifeCounter = 0;
                                for (int i = -1; i<2; ++i){
                                        lifeCounter += cell[y][x+i];
                                }
                                if  (lifeCounter ==3){
                                        *flag |= 1UL<<3;
					newCells[y+2][x+1] = 1;

				}
                        }
			else
				printf("problem");
//----------------- this part deal with number of neighbour---------------------
			if (sum > 3 || sum<2)
				newCells [y+1][x+1] = 0;
			else if (sum ==3)
				newCells [y+1][x+1] = 1;
			else 
				newCells [y+1][x+1] = cell[y][x];

			//printf("%i---x = %i y = %i, flag = %x\n", sum,x,y, *flag &0b0001 ^ 0b0001);
			sum =0;
				
		}

	}
	//printf("new\n");
	printf("row = %i, col = %i\n", *row, *col);
	htmlize(newCells, *row+2,*col+2);
	//clean up roll/col with no life
        int colStart = 0;
        int colEnd = *col+2;
	int rowStart = 0;
	int rowEnd	= *row+2;
	int counter = 0;
	
// 4 bit  left right top bottom flag
	//left side
	char c;
	if(*flag &0b0001 ^ 0b0001){
		//scanf("%c",&c );
		colStart = 2;
		for (int i = 0; i<rowEnd; ++i){
			if (newCells[i][1] != 0){
				--colStart;
				break;
			}
		}
		printf("%d---!!!!!!!!\n", colStart);
	}
	
	//right side
	if(*flag&0b0010 ^0b0010){
                colEnd-=2;
                for (int i = 0; i<rowEnd; ++i){
                        if (newCells[i][colEnd] != 0){
                                ++colEnd;
                                break;
                        }
                }
                printf("%d---!!!!!!!!\n", colStart);
        }
	//top
	if(*flag&0b0100 ^0b0100){
                rowStart = 2;
                for (int i = 0; i<colEnd; ++i){
                        if (newCells[1][i] != 0){
                                --rowStart;
                                break;
                        }
                }
                printf("%d---!!!!!!!!\n", rowStart);
        }
        //bottom
        if(*flag&0b1000 ^0b1000){
                rowEnd -= 2;
                for (int i = 0; i<colEnd; ++i){
                        if (newCells[rowEnd][i] != 0){
                                ++rowEnd;
                                break;
                        }
                }
                printf("%d---!!!!!!!!\n", rowEnd);
        }



	*col = colEnd-colStart;
	*row = rowEnd -rowStart;
	printf("%i,%i,%i\n",*col,*row,colEnd);
	printf("\n");
        for (int i= 0; i<4; ++i){
                printf("%d", *flag>>i&1);
        }
        
	int** finCell = calloc((*row),sizeof(int*));
	
	for ( int i = 0; i < *row; ++i ){
    		finCell[i] = calloc((*col),sizeof(int));
	    	memcpy(*(finCell+i), *(newCells+rowStart+i)+colStart, (*col)*sizeof(int));
	}


	printf("\n");
	free(flag);
	free(newCells);
	return finCell;
}


/*
sudo code for game of life itself

cell 2d array input

new 2d array to store the new cell 
calculate the sum of neareaset  nearest neighbour
	starting with x =0 and y = 0 go to the end of the 2d array 

		sum = 0
		if  x>0 andd y>0
			sum x-1 to x+1 for y = y-1 to y+1
		elif x = 0 and y>1
			sum x to x+1 for y = y-1 to y+1
		elif  x = 0 and  y = 0 (this should go to bottom as it is less likely)
			sum x to x+1 for y = y to y+1
		elif x > 1 and y = 0
			sum x-1 to x+1 for y = y to y +1
		else 
			we have a problem
		if sum > 3 of sum <2
			 put  new cell x,y to 0
		else if sum == 3 
			put new cell x,y to 1
		else 
			do nothing
	
		
calculate if the size of the cell need to expland
	if the there are 3 life in a roll then there will be extra row/col
	2 row need to be check y=0 and y = max(y) for x 0 to max(x)-2
		sum of x to x+2 inc 1
			if sum  >2 new row needed
				life  is at x+1
	2 col  	 x= 0 and max(x)  for y = 0 to max(y)
		sum of y to y+2 inc 1
			if sum >2 new col needed
				life is at  y + 1

	if top row and no new col
		add extra  roll before old cell
	if bottom row
		add extra roll after
	if both row
		do both of the above
	do the same with coll

	if top row and col
		at filler at the  corners
	
put the new cell back together and return.
	copy the  new cell into the centre with explansion
	return

*/






