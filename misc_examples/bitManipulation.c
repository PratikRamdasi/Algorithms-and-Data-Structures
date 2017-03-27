/* Title: Bit-Manipulation practice - Important functions for usage
 * 
 * Date: 03/01/17
 * 
 * Author: Pratik Ramdasi
 */

#include <stdio.h>

// Check if given integer has alternate pattern - 010101...
void checkAlternatePattern(int n)
{
	int x, y;
	x = n << 1;
	y = x ^ n;
	printf("%s\n", y & (y+1) ? "False" : "True");
}

// Round an int to next lower multiple of 2
void lowerMultipleof2(int n)
{
	int x = 1; 
	// for positive numbers
	if (n > 0) {
		for (; x <= n >> 1;) {
			x = x << 1;
		}
		n = x;
	}
	// for negative numbers
	else {
		n = ~n;
		n += 1;   // 2's complement
		for (; x <= n >> 1;) {
			x = x << 1;
		}
		x = x << 1;
		x = ~x;
		x += 1;
		n = x;
	}
	
	printf("%d\n", n);
} 

// Find number of trailing zeros
void numTrailingZeros(int n)
{
	int count = 0;
	while (n != 0) {
		if ((n & 1) == 1) {
			break;
		}
		count ++;
		n = n >> 1;
	}
	printf("Trailing zeros are %d\n", count);
}


// Find the position of highest bit set in the number
void highestBitSet(int n)
{
	int count = 0;
	while (n >> 1 != 0) {
		count++;
		n = n >> 1;
	}
	printf("Position of highest bit set is %d\n", count);
}

// Find number of bits set to 0 in an integer
void numSetTozero(int n)
{
	int count = 0, sn, res, i;
	for (i = 0; i <= 8*sizeof(int); i++) 
	{
		sn = n >> i;
		res = sn & 1;
		if (res == 0)
			count++;
	}
	printf("Number of bits set to 0 is %d\n", count);
}

// Function takes bytes as integer abd returns number between the specified bit positions
void num_between_bit_positions(int num, int start_pos, int end_pos)
{
	int shift_num, res_val, result = 0, i, j;
	for (i = start_pos, j = 0; i <= end_pos; i++, j++)
	{
		shift_num = num >> i;
		res_val = shift_num & 1;
		res_val = res_val << j;
		result += res_val;
	}
	printf("Number between position %d and %d is %d\n", start_pos, end_pos, result);
}

// Find the position of string of 1-bits in a number for a given length
void pos_1bitString(int num, int len)
{
	int i = 0, count = 0, pos = 0; 
	// 32-bit number
	while(i <= 32) {
		if ((num & 1) == 1) {
			count++;
			pos = i;
			if (count == len) {
				 break;
			}
		}
		if ((num & 1) == 0) {
			count = 0;
		}
		num = num >> 1;
		i++;
	}
	printf("The position of 1 in the string is %d\n", pos);
		
}

// Check if number is Palindrome or not - 8 bit integer
void is_palindrome(int num)
{
	int num1 = 0, i = 0, j = 7, flag = 0;
	unsigned char c[8];
	num1 = num;
	while(num != 0) {
		c[j] = num & 1;
		j--;
		num = num >> 1; 
	}
	// display binary representation
	printf("Binary representation of the number %d is: ", num1);
	for (i = 0; i <= 7; i++) {
		printf("%d", c[i]);
	}
	// check if palindrome 
	char temp[7];
	for (i = 0, j = 7; i <= 7, j >= 0; i++, j--) {
		temp[j] = c[i];
	}
	for (i = 0; i <= 7; i++) {
		if (temp[i] != c[i]){
			flag = 1;
		}
	}
	
	if (flag == 0) { printf("\nNumber is Palindrome\n"); }
	else { printf("\nNumber is not palindrome\n"); }
}
			
int main()
{
	int n;
	printf("Enter the integer number: ");
	scanf("%d", &n);
	/*
	checkAlternatePattern(n);
	lowerMultipleof2(n);
	numTrailingZeros(n);
	highestBitSet(n);
	numSetTozero(n);
	
	int start, end;
	printf("Enter the starting and ending psition: ");
	scanf("%d %d", &start, &end);
	num_between_bit_positions(n, start, end);
	
	int len;
	printf("Enter the length of the 1bit string: ");
	scanf("%d", &len);
	pos_1bitString(n, len);
	*/
	is_palindrome(n);
	
	return 0;
}
