// Linked List class implementation in c++

#include<iostream>
#include<cstddef>

using namespace std;

// Node class
class Node {
	public:
		int data;
		Node *next;
		Node(int d) {
			data = d;
			next = NULL;
		}
};

class Operations {
	public:
		// insert a node in the linked list
		Node * insert(Node * head, int data) 
		{
			if (head == NULL) {
				return new Node(data);
			}
			else if (head->next == NULL) {
				head->next = new Node(data);
			}
			else {
				insert(head->next, data);
			}
			return head;
		}
		
		// insert a node in front
		Node * insertFront(Node ** head, int data)
		{
			Node * new_node = new Node(data);
			new_node->next = *head;
			*head = new_node;
			return *head;
		}
		
		// remove first node from the list
		Node * removeFirst(Node ** head)
		{
			Node *temp = *head;
			*head = temp->next;
			delete temp;
			return *head;
			
		}
		
		// remove given node from LL
		void removeGiven(Node ** head, Node *del)
		{
			Node * temp = *head;
			// if first node to be deleted
			if (del == *head) {
				*head = temp->next;
				delete del;
				//return *head;
			}
			// loop through others till found
			while (temp) {
				if (temp->next == del) {
					temp->next = del->next;
					delete del;
				}
				temp = temp->next;
			}
			//return *head;
		}
					
		
		// search node in the linked list
		Node * searchNode(Node *head, int n)
		{
			Node *start = head;
			while (start) {
				if (start->data == n) { return start; }
				start = start->next;
			}
			cout << "No node " << n << " in the list." << endl;
			return start;
		}
		
		// remove duplicate node: No buffer allowed
		void removeDuplicate(Node ** head)
		{
			Node * start = *head;
			Node * iter;
			if (start->next == NULL) return;
			while (start) {
				iter = start->next;
				while (iter) {
					if (start->data == iter->data) {
						removeGiven(head, iter);
					}
					iter = iter->next;
				}
				start = start->next;
			}
			return;		
		}
			
		// print the linked list
		void display(Node *head)
		{
			Node *start = head;
			while (start) {
				cout << start->data << " ";
				start = start->next;
			}
			cout << endl;
		}
		 
};

int main()
{
	Node* head = NULL;
	Operations myList;
	int data[8] = {2,3,4,1,5,7,10,6};
	for (int i = 0; i < 8; i++) {
		head = myList.insert(head, data[i]);
	}
	
	// display LL
	myList.display(head);
	// remove first node from the list
	head = myList.removeFirst(&head);
	// display LL
	myList.display(head);
	// insert new node at front in the LL
	head = myList.insertFront(&head, 5);
	// display LL
	myList.display(head);
	// search for node 10 and remove it
	Node *del = myList.searchNode(head, 10);
	myList.removeGiven(&head, del);
	// display LL
	myList.display(head);
	// remove duplicate node
	myList.removeDuplicate(&head);
	// display LL
	myList.display(head);
	
}
