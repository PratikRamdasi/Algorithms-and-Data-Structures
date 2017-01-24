// binary tree implementation

#include <stdio.h>

typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node_t;

// insert element into bst
void insert(node_t * tree, int val)
{
    // insetion at root
    if (tree->val==NULL){
        tree->val = val;
    }
    // check left side
    else if (tree->val > val) {
        if (tree->left != NULL) {
            insert(tree->left, val);
        }
        else {
            tree->left = malloc(sizeof(node_t));
            tree->left->val = val;
        }
    }
    // check to the right
    else if (tree->val < val) {
        if (tree->right != NULL) {
            insert(tree->right, val);
        }
        else {
            tree->right = malloc(sizeof(node_t));
            tree->right->val = val;
        }
    }
}

// print the tree
void print_tree(node_t * current)
{
    if (current != NULL) printf("\n%d", current->val);
    if (current->left != NULL) printf("L%d", current->left->val);
    if (current->right != NULL) printf("R%d", current->right->val);
    
    if (current->left != NULL) print_tree(current->left);
    if (current->right != NULL) print_tree(current->right);
    
}

// print the tree in DFS manner
void printDFS(node_t * current)
{
    if (current->left != NULL) printDFS(current->left);
    if (current != NULL) printf("%d", current->val);
    if (current->right != NULL) printDFS(current->right);
    
}

int main(void) {
	
	node_t * tree = malloc(sizeof(node_t));
	
	insert( tree, 5 );
	insert( tree, 10 );
	insert( tree, 4 );
	insert( tree, 3 );
	insert( tree, 19 );
	
	//print_tree(tree);
	printDFS(tree);
	return 0;
}

