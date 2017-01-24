// Binary Search Tree in C++

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
				Node *cur;
				if (data < cur->data) {
					cur = addNode(root->left, data); 
					root->left = cur;
				}
				else {
					cur = addNode(root->right, data);
					root->right = cur;
				}
				return root;
			}
		}
		
		// get height of the BST
		int getHeight(Node *root)
		{
			int rightHeight = 0;
			int leftHeight = 0;
			
			if (root->left != NULL)  {
				leftHeight = getHeight(root->left) + 1;
			}
			
			if (root->right != NULL)  {
				rightHeight = getHeight(root->right) + 1;
			}
			
			return (leftHeight > rightHeight ? leftHeight : rightHeight);
		
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
	
	return 0;
}
		
