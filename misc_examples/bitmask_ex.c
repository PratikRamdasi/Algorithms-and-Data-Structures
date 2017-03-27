/* 
 * Title: Bit Masking Practice Examples 
 * 
 * Date : 03/ 01/ 17
 * 
 * Author: Pratik Ramdasi
 * 
 */

#include <stdio.h>

// Function to double each odd number in an array
void double_odd_number(int arr[])
{
	int i;
	for (i = 0; i < 10; i++) {
		if ((arr[i] & 1) != 0) {   // Number is odd if and only if LSB is 1
			arr[i] = arr[i] << 1;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Function to find unique number in array of duplicates
void find_unique(int arr[])
{
	int value = 0, i;
	for (i = 0; i < 10; i++) {
		value = value ^ arr[i];   // simply XOR all the elements in an array
	}
	printf("Unique element in array is : %d\n", value);
}

// Function to find two unique numbers in array of duplicates
/*
int find_mask (int arr[])
{
	int combined = 0, i, mask;
	for (i = 0; i < 10; i++) {
		combined = combined ^ arr[i];   // simply XOR all the elements in an array, combination of J XOR K
	}
	mask = 1;
	while ((combined & mask) == 0) {
		mask = mask << 1;
	}
	return mask;
}
*/			
void find_two_unique(int arr[]) // Time : O(n) , space : O(1)
{
	int j = 0, k = 0, mask, i, combined;
	for (i = 0; i < 10; i++) {
		combined = combined ^ arr[i];   // simply XOR all the elements in an array, combination of J XOR K
	}
	//mask = find_mask(arr);
	mask = combined & ~(combined - 1);  // get rightmost set bit (1)
	
	for(i = 0; i < 10; i++) {
		if ((arr[i] & mask) == 0) {
			j = j ^ arr[i];
		}
		else {
			k = k ^ arr[i];
		}
	}
	printf("Unique elements in array are %d and %d\n", j, k);
}

	
int main()
{
	int arr[10] = {3, 5, 4, 6, 9, 4, 3, 9, 5, 7};
	double_odd_number(arr);
	//find_unique(arr);
	//find_two_unique(arr);
	
	return 0;
}

