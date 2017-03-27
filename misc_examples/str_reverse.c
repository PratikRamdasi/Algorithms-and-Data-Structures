/*
 * Title: String reversal in C using different methods
 * 
 * Author : Pratik Ramdasi
 * 
 * Date : 03/ 01/ 17
 */ 

#include <stdio.h>
#include <string.h>

// Without using strrev function - O(n)
void method_1(char ip[])
{
	int len, i, j;
	char op[100];
	len = strlen(ip);
	for (i = 0, j = len-1; j >= 0; j--, i++) {
		op[j] = ip[i];
	}
	op[i] = '\0';
	printf("Reversed string is : %s\n", op);
}

// Using Pointers
void method_2(char *ip)
{
	int len, i;
	char *begin, *end, temp;
	
	len = strlen(ip);
	begin = ip;
	end = ip;
	// take end pointer at the end of the string
	for(i = 0; i < len-1; i++) {
		end++;
	}
	// swap characters 
	for (i = 0; i < len/2; i++) {
		temp = *end;
		*end = *begin;
		*begin = temp;
		
		begin++;
		end--;
	}
	printf("Reversed string is : %s\n", ip);
}

// XOR-SWAP method, Inplace Reverse
void method_3(char* ip)
{
	int begin = 0;
	int end = strlen(ip)-1;

	while(begin < end) {
		ip[begin] ^= ip[end]; 
		ip[end] ^= ip[begin]; 
		ip[begin] ^= ip[end];
		//printf("Begin %c - End %c\n", ip[begin], ip[end]);
		++begin;
		--end;
	}
	printf("Reversed string is : %s\n", ip);
}

int main()
{
	char ip[100];
	printf("Enter a string : ");
	fgets(ip, 100, stdin);
	
	//method_1(ip);
	//method_2(ip);
	method_3(ip);
	
	
	return 0;
}
