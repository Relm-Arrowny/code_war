#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE  20000

//---------- making a min heap ----------------------------
int parent(int i) {
        return (i - 1) / 2;
}

// return the index of the left child 
int left_child(int i) {
        return 2 * i + 1;
}

// return the index of the right child 
int right_child(int i) {
        return 2 * i + 2;
}

void swap(uint64_t * x, uint64_t * y) {
        uint64_t temp = * x;
        * x = * y;
        * y = temp;
}

// insert the item at the appropriate position
void enqueue(uint64_t a[], uint64_t data, int * n) {
        if ( * n >= MAX_SIZE) {
                printf("%s\n", "The heap is full. Cannot insert");
                return;
        }
        // first insert the time at the last position of the array 
        // and move it up
        a[ * n] = data;
        * n = * n + 1;

        // move up until the heap property satisfies
        int i = * n - 1;
        while (i != 0 && a[parent(i)] > a[i]) {
                swap( & a[parent(i)], & a[i]);
                i = parent(i);
        }
}

void min_heapify(uint64_t a[], int i, int n) {
        // find left child node
        int left = left_child(i);

        // find right child node
        int right = right_child(i);

        // find the smallest among 3 nodes
        int smallest = i;

        // check if the left node is smaller than the current node
        if (left <= n && a[left] < a[smallest]) {
                smallest = left;
        }

        // check if the right node is smaller than the current node
        if (right <= n && a[right] < a[smallest]) {
                smallest = right;
        }

        // swap the smallest node with the current node 
        // and repeat this process until the current node is smaller than 
        // the right and the left node
        if (smallest != i) {
                uint64_t temp = a[i];
                a[i] = a[smallest];
                a[smallest] = temp;
                min_heapify(a, smallest, n);
        }

}

// returns the  minimum item of the heap
uint64_t get_min(uint64_t a[]) {
        return a[0];
}

uint64_t dequeue(uint64_t a[], int * n) {
        uint64_t min_item = a[0];

        // replace the first item with the last item
        a[0] = a[ * n - 1];
        * n = * n - 1;

        // maintain the heap property by heapifying the 
        // first item
        min_heapify(a, 0, * n);
        return min_item;
}

// prints the heap
void print_heap(uint64_t a[], int n) {
        int i;
        for (i = 0; i < n; i++) {
                printf("%ld\n", a[i]);
        }
        printf("\n");
}


uint64_t hamber(int n)
{	int cHn = 0;
	uint64_t nowHn ;
	uint64_t front[n];
	int heapSize = 0;
	enqueue(front, 1, &heapSize);

	while (cHn != n){
		nowHn = dequeue(front,&heapSize);
		cHn++;
		if (cHn == n)
			return nowHn;

		uint64_t temp = nowHn <<1;
		if ( temp>>1 == nowHn) 
			enqueue(front, nowHn<<1, &heapSize);
		temp = nowHn *3;
		if ( temp/3 == nowHn)
			enqueue(front, nowHn*3, &heapSize);
		temp = nowHn *5;
		if ( temp/5 == nowHn)
			enqueue(front, nowHn*5, &heapSize);
		
		while (get_min(front) == nowHn)
			dequeue(front,&heapSize);
		//print_heap(front, heapSize);
		//printf("%li ,%i\n", nowHn, heapSize);
	}
    return nowHn;
}

int main(int argc, char *argv[]){
	char *p;
	int conv = 5;
	printf("%li\n", hamber(conv));
        return 0;
}



//---------------------------------------------------------------








/* sudo code
	goal is to return the nth smallest Hamming number
	
	the first number is 1
	
	for each hamming number HM there are 3  new number HM*2, HM*3, HM*5
	
	current cHM = 1
	counter nHum = 0;
	a priority queue to store all the head ---PQ
	while(nHum ! = nth)
		expland cHM and put it in PQ
			if it is already in the queue drop it
		cHM =  to of the priority queue 
		nHum++

	return cHM
*/
