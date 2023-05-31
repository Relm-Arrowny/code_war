#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE  10000


//---------- making a min/max heap ----------------------------
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

void swap(int * x, int * y) {
        int temp = * x;
        * x = * y;
        * y = temp;
}

// insert the item at the appropriate position
void enqueue(int a[], int data, int * n) {
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
        while (i != 0 && a[parent(i)] < a[i]) {
                swap( & a[parent(i)], & a[i]);
                i = parent(i);
        }
}

void max_heapify(int a[], int i, int n) {
        // find left child node
        int left = left_child(i);

        // find right child node
        int right = right_child(i);

        // find the biggest among 3 nodes
        int biggest = i;

        // check if the left node is bigger than the current node
        if (left <= n && a[left] > a[biggest]) {
                biggest = left;
        }

        // check if the right node is bigger than the current node
        if (right <= n && a[right] > a[biggest]) {
                biggest = right;
        }

        // swap the biggest node with the current node
        // and repeat this process until the current node is bigger than
        // the right and the left node
        if (biggest != i) {
                int temp = a[i];
                a[i] = a[biggest];
                a[biggest] = temp;
                max_heapify(a, biggest, n);
        }

}

// returns the  minimum item of the heap
int get_max(int a[]) {
        return a[0];
}

int dequeue(int a[], int * n) {
        int max_item = a[0];

        // replace the first item with the last item
        a[0] = a[ * n - 1];
        * n = * n - 1;

        // maintain the heap property by heapifying the
        // first item
        max_heapify(a, 0, * n);
        return max_item;
}

// prints the heap
void print_heap(int a[], int n) {
        int i;
        for (i = 0; i < n; i++) {
                printf("%d\n", a[i]);
        }
        printf("\n");
}

int smallest_possible_sum(size_t n, const int array[n]) {

	int front[n];
	int heapSize = 0;
	int smallest = array[0];
	for (int i = 1; i<n; i++){
		if (array[i] < smallest)
			smallest = array[i];
	}
	enqueue(front, smallest, &heapSize);
	for (int i = 0; i<n; i++){
                if (array[i]%smallest != 0)
                        enqueue(front, array[i], &heapSize);
        }

	
	while (heapSize>0) {
		smallest = dequeue(front, &heapSize);
		int diff = smallest - get_max(front);
		if (diff > 0 ){
			enqueue(front, diff, &heapSize);
		}

	}
	return n*smallest;
}


int main(int argc, char *argv[]){
	
	const int array[3] = {24, 4, 16};

	printf("%d",smallest_possible_sum(3, array));

	return 0;
} 








