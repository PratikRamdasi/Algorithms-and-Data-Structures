/*
 * Author: Pratik Ramdasi
 * 
 * Date: 04/ 21/ 2017 
 * 
 * Title: Stack basic functions implementation in C++
 * 
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

/* A simple stack class with basic functionalities */

class Stack
{
	private:
		static const int max = 100;
		int arr[max]; 
		int top;
	public: 
		Stack() { top = -1; } // constructor
		bool isEmpty();
		bool isFull();
		int pop();        // pop element from stack
		void push(int x); // push element onto stack
		void display(); // display stack elements
};

/* Stack's member method to check if it's empty */
bool Stack::isEmpty()
{
	if (top == -1) {
		return true;
	}
	return false;
}

/* Stack's member method to check if it's full */
bool Stack::isFull()
{
	if (top == max - 1) {
		return true;
	}
	return false;
}

/* Stack's member method to remove element from the stack */
int Stack::pop()
{
	if (isEmpty()) {
		cout << "Stack underflow!" << endl;
		abort();
	}
	int x = arr[top];
	top--;
	return x;
}

/* Stack's member method to add element onto the stack */
void Stack::push(int x)
{
	if (isFull()) {
		cout << "Stack overflow!" << endl;
		abort();
	}
	top++;
	arr[top] = x;
}

/* Stack's member method to display elements */
void Stack::display()
{
	for (int i = 0; i <= top; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	// define stack object
	Stack s;
	// push elements into the stack
	s.push(10);
	s.push(20);
	s.push(40);
	s.push(35);
	s.display();
	// pop element from it
	s.pop();
	s.display();
	
	return 0;
}
	
	
