/* Title: Merge Sort in c++
 * Date:  02/ 06/ 2017
 * Author: Pratik Ramdasi
 */

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

/* function to Merge the two sorted subarrays */
void merge(int array[], int p, int q, int r)
{
	int temp[7];  // temporary array to store merged elements 
	int k = 0;
	int j = q + 1;  // first element index in right subarray
	int i = p;      // first element index in left subarray
	
	// copy the smallest element 
	while (i <= q && j <= r) {
	
		if (array[i] < array[j]) {
			temp[k++] = array[i++];
		}
		else {
			temp[k++] = array[j++];
		}
	}
	// copy remaining elements from left side
	while (i <= q) {
		temp[k++] = array[i++];
	}
	// copy remaining elements from right side
	while (j <= r) {
		temp[k++] = array[j++];
	}
	
	// copy back the temp array elements into sorted array
	for (int j = r; j >= p; j--) {
		array[j] = temp[--k];
	}
}

/* Merge Sort main function */
/* time complexity - O(n * log(n)) average and worst case */
void mergeSort(int array[], int p, int r)
{
	int q;   // middle element in the array
	if (p < r) 
	{
		q = floor((p + r) / 2);
		mergeSort(array, p, q);  // recursive call to split left subarray 
		mergeSort(array, q+1, r); // recursive call to split right subarray 
		merge(array, p, q, r);  // merging subarrays
	}
}

int main()
{
	//input array of integers
	int arr[7] = {5, 4, 7, 2, 6, 1, 3}; 
	
	//selection sort the array
    mergeSort(arr, 0, 6);
     	
	//print sorted array
	for (int j = 0; j < 7; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
	
	return 0;
}
