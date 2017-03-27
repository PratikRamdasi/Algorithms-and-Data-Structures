/*
 * Author: Pratik Ramdasi
 * Date: 01/ 25/ 2017 
 * Title: Check if the string is palindrome or not 
 */

#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution {
	public:
		stack <char> rev;
		queue <char> ori;
		
		// push element onto the stack
		void pushElement(char ch) {
			rev.push(ch);
		}
		// enqueue element
		void enqueueElement(char ch) {
			ori.push(ch);
		}
		// pop element from the stack
		char popElement() {
			char s = rev.top();
			rev.pop();
			return s;
		}
		// dequeue element 
		char dequeueElement() {
			char q = ori.front();
			ori.pop();
			return q;
		}
};

int main()
{
	// read the string s
	string s;
	getline(cin, s);
	
	// create solution class object
	Solution obj;
	
	// push/enqueue chars
	for (size_t i = 0; i < s.length(); i++) {
		obj.pushElement(s[i]);
		obj.enqueueElement(s[i]);
	}
	
	bool isPalindrome = true;
	
	// compare dequeued and removed from stack char
	for (size_t i = 0; i < s.length() / 2; i++) {
		if (obj.popElement() != obj.dequeueElement()) {
			isPalindrome = false;
			break;
		}
	}
	
	if (isPalindrome) { cout << "String is palindrome!" << endl; }
	else { cout << "String a not a palindrome!" << endl; }
	
	return 0;
}


