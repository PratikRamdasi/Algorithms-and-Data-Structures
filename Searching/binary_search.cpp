/*
 * Title:  Binary Search algorithm
 * Author: Pratik Ramdasi
 * Date: 03/ 30/ 2017
 * 
 */

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// Binary search for element - O(log n)
// only when input vector is already sorted
int binary_search(vector<int>& a, int left, int right, int key)
{
	if(left <= right) 
	{
		int mid = (left + right) / 2;
		if (a[mid] == key) {
			return mid;
		}
		if(key < a[mid])
			return binary_search(a, left, mid-1, key);	
		return binary_search(a, mid+1, right, key);
	}
	return -1;
}
		
int main()
{
	int n, val;
	cout << "Enter number of array elements: ";
	cin >> n;
	
	// Enter array elements 
	cout << "Enter the elements: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}
	// Find the position of input element in an array
	int key;
	cout << "Enter element to be searched: ";
	cin >> key;
	int ans = binary_search(arr, 0, n-1, key);
	if (ans == -1) {
		cout << "Element not found!" << endl;
	}
	else {
		cout << "Element found at position " << ans << endl;
	}
	return 0;
}
