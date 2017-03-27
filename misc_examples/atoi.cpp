/*
 * Author: Pratik Ramdasi
 * Date: 02/ 07/ 2017 
 * Title: string to integer converter C++ function
 */
 
#include <iostream>
#include <stdio.h>
#include <string>
#include <climits>

using namespace std;

int atoi(string s)
{
	// check if given string is empty
	if (s.empty()) {
		return 0;
	}
	
	int i = 0;  // for current index in the string
	int result = 0; // resulting int value 
	int sign = 1;  // to handle -ve signs
	
	// remove whitespace characters
	while (s[i] == ' ') {
		i++;
	}
	// handling negative signs
	if (s[i] == '-' || s[i] == '+') {
		sign = 1 - 2 * (s[i] == '-');
	}
	// handle overflow
	while (s[i] >= '0' && s[i] <= '9') {
		if (result > INT_MAX / 10 || ( result == INT_MAX / 10 && s[i] - '0' > 7)) {
			if (sign == 1) return INT_MAX;
			else return INT_MIN;
		}
		result = (result * 10) + (s[i++] - '0');
	}

	return result * sign;
}

int main()
{
	// read the input string
	string s;
	getline(cin, s);
	
	// convert string to integer
	int n;
	n = atoi(s);
	
	// display result
	cout << "integer value: " << n << endl;
	
	return 0;
}
	
