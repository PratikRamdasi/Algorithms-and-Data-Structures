/*
 * Author: Pratik Ramdasi
 * Date: 02/ 28/ 2017 
 * Title: ASCII to integer and integer to ASCII C function
 */
 
#include <stdio.h>

int ascii_int(char c)
{
	return (c - '0');
}

char int_ascii(int n)
{
	return (n + '0');
}

int main()
{
	/*
	 * // works only for single characters
	char c = '5';
	int val = ascii_int(c);
	printf(" Integer value for char c is %d \n", val);
	
	int n = 9;
	int ascii = int_ascii(n);
	printf(" ASCII value for n is %c \n", ascii);
	*/
	
	//16 bit int to ascii
	int msg = 'A';
	char *ptr = (char *)&msg;
	msg = msg << 8;
	msg |= 'B';
	
	printf("First byte of the msg : %c\n", ptr[0]);
	printf("Second byte of the msg : %c\n", ptr[1]);
	
	return 0;	
}
	
	
