/*

insertion sort not the best but certainly better than the rest(bubble n selection)!
			sorted | unsorted 
simple sorting algorithm that works the way we SORT PLAYING CARDS in our hands.


*/
 // C program for insertion sort 
#include <stdio.h> 
#include <math.h> 

/* 


 


11, 12,| 13, 5, 6


11, 12, 13,| 5, 6


5, 11, 12, 13,| 6


5, 6, 11, 12, 13



 insertion sort*/


//array,length

void insertionSort(int arr[], int n) 
{ 
int wall, key, j; 
//wall set at 2nd selement  12 | 11, 13, 5, 6
// jo key se bada hai use ek step agey kar do.... wall ke becche hi reh ke kaam karo

//for loop: wall (key is at wall pos)
//while loop till wall
for (wall = 1; wall < n; wall++) 
{ 
	key = arr[wall]; 
	j = wall-1; 

	/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
	while (j >= 0 && arr[j] > key) 
	{ 
		arr[j+1] = arr[j]; 
		j = j-1; 
	} 
	arr[j+1] = key; 
}
} 

// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
int i; 
for (i=0; i < n; i++) 
	printf("%d ", arr[i]); 
printf("\n"); 
} 



/* Driver program to test insertion sort */
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	insertionSort(arr, n); 
	printArray(arr, n); 

	return 0; 
} 
