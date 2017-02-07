/* Title: Selection Sort in c++
 * Date:  02/ 06/ 2017
 * Author: Pratik Ramdasi
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// function to selection sort the given array of integers
// time complexity - O(n^2) average and worst case

void selectionSort(int array[], int length)
{
	int temp, pos_min; // pos_min is position of the minimum value
	for (int i = 0; i < length; i++)
	{
		pos_min = i; // set pos_min to current index of array
		
		// get min element position after the iteration to update pos_min
		for (int j = i + 1; j < length; j++)
		{
			if (array[j] < array[pos_min]) {
				pos_min = j;
			}
		}
		// swap elements if pos_min is not equal to i as smaller value is found 
		if (pos_min != i)
		{
			temp = array[i];
			array[i] = array[pos_min];
			array[pos_min] = temp;
		}
	} 
}

int main()
{
	//input array of integers
	int arr[7] = {5, 4, 7, 2, 6, 1, 3}; 
	
	//selection sort the array
    	selectionSort(arr, 7);
     	
	//print sorted array
	for (int j = 0; j < 7; j++)
	{
		cout << arr[j] << " ";
	}
	cout << endl;
	
	return 0;
}
