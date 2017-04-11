/*
 * Author: Pratik Ramdasi
 * 
 * Date: 02/ 08/ 2017 
 * 
 * Title: Binary Search Tree Implementation in C++
 * 
 */

#include <iostream>
#include <cstddef>
#include <queue>
#include <cstdlib>


using namespace std;

// Node class
class Node {
	public:
		int data;
		Node *left;
		Node *right;
		Node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

class Operations {
	public:
		// insert a node into BST
		Node *addNode(Node *root, int data)
		{
			if (root == NULL) {
				return new Node(data);
			}
			else {
				if (data < root->data) {
					root->left = addNode(root->left, data); 
				}
				else {
					root->right = addNode(root->right, data);	
				}
				return root;
			}
		}
		
		// get height of the Tree - O(log n) when balanced , O(n) for unbalanced
		int getHeight(Node *root)
		{
			int rightHeight = 0;
			int leftHeight = 0;
			// if no tree
			if (root == NULL) return 0;
			// height of left subtree
			if (root->left != NULL)  {
				leftHeight = getHeight(root->left);
			}
			// height of right subtree
			if (root->right != NULL)  {
				rightHeight = getHeight(root->right);
			}
			// return max height
			return (max(leftHeight, rightHeight) + 1);
		
		}
		
		/* pre-order traversal in a tree */
		void preOrder(Node *root)
		{
			//print root element 
			if (root != NULL) { 
				cout << root->data << " ";
			}
			//print left subtree elements by recursion
			if (root->left != NULL) {
				preOrder(root->left);
			}
			//print right subtree elements by recursion
			if (root->right != NULL) {
				preOrder(root->right);
			}
		}
		
		// display BST
		void levelOrder(Node *root)
		{
			queue<Node *> q;
			while(root != NULL) {
				cout << root->data << " ";
				
				if (root->left != NULL) q.push(root->left);
				if (root->right != NULL) q.push(root->right);
				
				if (!q.empty()) {
					root = q.front();
					q.pop();
				}
				else {
					root = NULL;
				}
			}
			cout << endl;
		}
		
		// Find largest element in BST - Rightmost element - O(h) time complexity
		int findLargest(Node *root)
		{
			Node *largest = NULL;
			while (root != NULL) 
			{
				if (!root->right) 
				{
					largest = root;
				}
				root = root->right;
			}
			return largest->data;
		}
		
		// Find second largest element in the BST  -  O(h) time complexity, O(1) space complexity
		int findSecondLargest(Node *root)
		{
			while(root) {
				//case 1: righmost node has left subtree
				if (root->left && !root->right) {
					return findLargest(root->left);
				}
			
				//case 2: current (root) is parent of rightmost child - current is second largest
				if (root->right && !root->right->left && !root->right->right) {
					break;
				}
				
				// case 3: right subtree continues
				root = root->right;
			}
			return root->data;
		}
};

int main()
{
	Operations myTree;
	Node *root = NULL;
	
	root = myTree.addNode(root, 3);
	root = myTree.addNode(root, 5);
	root = myTree.addNode(root, 2);
	root = myTree.addNode(root, 1);
	root = myTree.addNode(root, 4);
	root = myTree.addNode(root, 6);
	root = myTree.addNode(root, 7);
	
	// display tree by levels
	myTree.levelOrder(root);
	
	// display tee height
	int height = myTree.getHeight(root);
	cout << "Height of BST is: " << height << endl;
	
	// Display largest element in the BST
	int largest = myTree.findLargest(root);
	cout << "Largest element in BST is: " << largest << endl;
	
	// Display second largest element in the BST
	int slargest = myTree.findSecondLargest(root);
	cout << "Second largest element in BST is: " << slargest << endl;	
	
	return 0;
}
		
