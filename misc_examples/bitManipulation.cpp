/* Bit-Manipulation 
 * Important functions for usage
 * Date (Modified) : 03/01/17
 */

#include <cstdio>
#include <iostream>

using namespace std;

/* 
 * 1. check if given number is power of 2
 */

// method - 1 : normal   ==   Time  -  O(log n)
bool isPowerof2( int n )
{
	if (n == 0) {
		return  false;
	}
	else {
		while (n % 2 == 0)
			n /= 2;
		return (n == 1);
	}
}

// method - 2: bit manipulation
bool isPowerof2_bm( int n )
{
	// check if n == 0 and perform bit-AND to check if it returns 0
	return (n && !(n & (n-1)));
}


/* 
 * 2. count number of 1's in the binary representation of the given number
*/

// method - 1 : converting number into binary and traversing through binary representation - O(log n)

// method - 2 : time - O(k), where k is number of ones present in the binary representation, worst case - O(log n)
int count_ones_bm( int n )
{
	int count = 0;
	while (n) {
		n = (n & (n-1));
		count++;
	}
	return count;
}

/* 
 * 3. check if 'i' th bit is set or not
*/
bool isBitSet_bm( int n , int i)
{
	// AND the number with 2 ^ i ( 1 << i == 2 ^ i - left shift operator)
	if ( n & (1 << i)) { return true ;}
	else { return false; }
}

/* 
 * 4. Generate all possible subsets of a set
*/
void possibleSubsets ( char a[], int n )
{
	// all possible subsets of n-element set - max possible number = 2 ^ n; 
	for ( int i = 0; i < (1 << n); ++i) {
		// lopp through number of elements
		for (int j = 0; j < n; j++) {
			// check if jth bit is set in i
			if ( i & (1 << j) ) {
				cout << a[j] << " ";
			}
		}
		cout << endl;
	}
}

/* 
 * 5. find greatest power of 2 less than or equal to given number  
*/

// method for 16 bit integer
long greatestPowof2( long n ) 
{
	n = n | (n >> 1);
	n = n | (n >> 2);
	n = n | (n >> 4);
	n = n | (n >> 8);
	
	// now, number becomes (2 * x - 1), where x is the answer
	return (n + 1) >> 1 ;    // or return (n + 1) / 2;
}


/*  Important shortcuts:
 *  --------------------
 *  1. x ^ ( x & (x - 1)): returns rightmost 1 in binary representation of x
 * 
 *  2. x & (-x): returns rightmost 1 in binary representation of x
 * 
 * 	-> (-x) is 2's complement of x i.e.,  1's complement  + 1.
 * 
 *  3. x | (1 << n): returns the number x with nth bit set. 
 */



int main()
{
	char a[3] = {'a', 'b', 'c'};
	int n = 3;
	cout << "All possible subsets for given array : " << endl;
	possibleSubsets(a, n);
	cout << endl;
	
	int n1 = 15;
	cout << "Number of ones in binary representation of " << n1 << " is: " << count_ones_bm(n1) << endl << endl;
	
	int n2 = 33;
	cout << "Greatest power of 2 less than or equal to " << n2 << " is: " << greatestPowof2(n2) << endl << endl;
	
	return 0;
}









