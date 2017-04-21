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

/* A class supporting all stack operations and additional operation getMin() that returns the minimum
 * element from stack at any time. This class inherits from stack class and uses auxiliary stack to store min
 * elements 
 */
class SpecialStack: public Stack
{
	Stack min; // auxiliary stack
	public:  
		int pop();         // pop element from stack
		void push(int x);  // push element onto stack
		int getMin();	   // get minimum element from stack
};

/* Special stack's member function to insert element into it. Minimum stack is also updated with appropriate values */
void SpecialStack::push(int x)
{
	// push element into original and auxiliary stack
	if (isEmpty() == true) {
		Stack::push(x);
		min.push(x);
	}
	else {
		Stack::push(x);
		int y = min.pop();
		min.push(y);
		// push incoming element into auxiliary stack only if its lesser than or equal to y 
		if (x <= y) {
			min.push(x);
		}
	}
}

/* Special stack's member function to remove element from it. Top element from minimum stack is also removed */
int SpecialStack::pop()
{
	int x = Stack::pop();
	int y = min.pop();
	// push only when y is not equal to x
	if (y != x) {
		min.push(y);
	}
	return x;
}

/* Special stack's member method to get min element from it */
int SpecialStack::getMin()
{
	int x = min.pop();
	min.push(x);
	return x;
}


int main()
{
	/* Define original stack object */
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
	
	/* Special stack - get minimum element */
	SpecialStack s1;
	// push elements into the stack
	s1.push(10);
	s1.push(20);
	s1.push(40);
	s1.push(35);
	cout << "Min element in the stack is - " << s1.getMin() << endl;
	s1.push(5);
	cout << "Min element in the updated stack is - " << s1.getMin() << endl;
	
	return 0;
}
	
	
