/* Title: Quick sort in c++
 * Date:  02/ 06/ 2017
 * Author: Pratik Ramdasi
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// function to quick sort the given array of integers
// adaptive implementation - for almost sorted array, O(n) implementation
// time complexity - O(n * log(n)), worst case - O(n^2) 

void quickSort(int array[], int left, int right)
{
	int i = left; // starting index of array
	int j = right; // final index of array
	int pivot = array[(left + right) / 2]; // pivot element
	
	int temp;
	
	// partition step
	while (i <= j)
	{
		// increment till greater than pivot element is found
		while (array[i] < pivot) {
			i++;
		}
		// decrement till smaller than pivot element is found
		while (array[j] > pivot) {
			j--;
		}
		if (i <= j)
		{
			// perform swapping
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	
	// recursion on left and right subarray
	if (left < j) {
		quickSort(array, left, j);
	}
	if (i < right) {
		quickSort(array, i, right);
	}
}

int main()
{
	//input array of integers
	int arr[7] = {5, 4, 7, 2, 6, 1, 3}; 
	
	//quick sort the array
    	quickSort(arr, 0, 6);
     	
	//print sorted array
	for (int j = 0; j < 7; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
	
	return 0;
}
