/* Title: Bubble sort in c++
 * Date:  02/ 06/ 2017
 * Author: Pratik Ramdasi
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// function to bubble sort the given array of integers
// adaptive implementation - for almost sorted array, O(n) implementation
// average and worst case time complexity - O(n^2)

void bubbleSort(int array[], int length)
{
	int temp, j = 0;
	bool swapped = true;  // check if elements are swapped
	
	while (swapped)
	{
		swapped = false;
		j++;	
		for (int i = 0; i < length - j; i++)  // loop for each iteration
		{
			if (array[i] > array[i+1]) // check the required sorting condition
			{
				// perform swap
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				swapped = true;  // set true if swapped
			}
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
	
	//bubble sort the array
    	bubbleSort(arr, 7);
	
	return 0;
}
