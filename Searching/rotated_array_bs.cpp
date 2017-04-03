/*
 * Author: Pratik Ramdasi
 * Date: 4/ 2/ 2017
 * Title: Rotated Array Binary Search
 */
 
// Problem Statement - Given the sorted and rotated array, find the position of target element in the array.
 
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// Rotated Array Binary Search function - O(log n) Time complexity, O(1) - space somplexity
int rotated_search(vector<int>& a, int left, int right, int key) 
{
	// Check if array is empty
	if (a.size() == 0) 
		return -1;
	// If array contains only 1 element
	if (left == right) {
		if (a[left] == key) {
			return left;
		} 
		else 
			return -1;
	}
	// Check if middle element is same as target
	int mid = (left + right) / 2;
	if (a[mid] == key) {
		return mid;
	}
	// If pivot element is at the right of middle element
	if (a[left] <= a[mid]) {
		if (key >= a[left] && key <= a[mid]) {
			return rotated_search(a, left, mid-1, key);
		}
		else
			return rotated_search(a, mid+1, right, key);
	}
	// If pivot element is at the left of middle element
	if (key >= a[mid] && key <= a[right]) {
		return rotated_search(a, mid + 1, right, key);
	}
	else
		return rotated_search(a, left, mid-1, key);
		
	return -1;
}
	

int main()
{
	int n, val;
	cout << "Enter number of array elements: ";
	cin >> n;
	
	// Enter array elements 
	cout << "Enter the elements: ";
	vector<int> elements;
	for (int i = 0; i < n; i++) {
		cin >> val;
		elements.push_back(val);
	}
	// Find the position of input element in an array
	int key;
	cout << "Enter element to be searched: ";
	cin >> key;
	int ans = rotated_search(elements, 0, n-1, key);
	if (ans == -1) {
		cout << "Element not found!" << endl;
	}
	else {
		cout << "Element found at position " << ans << endl;
	}
	return 0;
}

