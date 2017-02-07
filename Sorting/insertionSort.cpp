/* Title: Insertion sort in c++
 * Date:  02/ 06/ 2017
 * Author: Pratik Ramdasi
 */

#include <iostream>
#include <stdio.h>

using namespace std;

//function to insertion sort the given array of integers  -  O(n^2) algorithm
void insertionSort(int array[], int length)
{
	int temp, j; // temporary variables
	for (int i = 0; i < length; i++) 
	{
		j = i;  // initilize j = i
		while (j > 0 && array[j] < array[j-1]) 
		{
			// perform the swap
			temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;
			
			// decrement the counter
			j--;
		}
	}
	
	//print sorted array
	for (int j=0; j < length; j++)
	{
	    cout << array[j] << " ";
	}
	cout << endl;
}

int main()
{
	//input array of integers
	int arr[7] = {5, 4, 7, 2, 6, 1, 3}; 
	
	//insertion sort the array
    	insertionSort (arr, 7);
	
	return 0;
}
