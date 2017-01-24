// Linked List implementation

#include <stdio.h>
#include <stdlib.h>

// define node structure
typedef struct node {
	int val;
	struct node * next;   //define struct in recursive manner
} node_t;

//function to print the list
void print_list(node_t * head) {
	node_t * current  = head;
	
	while(current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

//add item to the end of the list
void push_end(node_t * head, int val)
{
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

//add item at the beginning of the list
void push_start(node_t ** head, int val)
{
    node_t * new_node;
    new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    new_node->next = *head;
    *head = new_node;
}

//remove first item from the list
int pop_first(node_t ** head)
{
    int ret_val = -1;
    node_t * next_node = NULL;
    
    if (*head == NULL) {
        return -1;
    }
    
    next_node = (*head)->next;
    ret_val = (*head)->val;
    free(*head);
    *head = next_node;
    
    return ret_val;
    //printf("item removed is %d\n",ret_val);
}

//remove last item from the list
void pop_last(node_t * head)
{
    int retval = 0;
    // if list has only 1 element, remove it
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        printf("Removed item is: %d\n", retval);
    }
    
    // else go to the end of the list
    node_t * current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    
    // remove last element
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    
    printf("Removed item is: %d\n", retval);
}

//removing spacific item from the list by index
void remove_by_index(node_t ** head, int n)
{
    int i;
    int retval;
    node_t * current = *head;
    node_t * temp_node = NULL;
    
    if (n==0) {
        printf("Element removed at index %d is : %d\n", n, pop_first(head));
    }
    
    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    
    // remove last element
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    
    printf("Element removed at index %d is : %d\n", n, retval);
    
}

//removing spacific item from the list by value
int remove_by_value(node_t ** head, int val)
{
    int i;
    int retval;
    node_t * current = *head;
    node_t * temp_node = NULL;
    
    if (n==0) {
        return pop_first(head));
    }
    
    // iterate through nodes
    while (current->next->val != val){
        if (current->next->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    
    // remove last element
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);
    
    return(retval);
    
}

int main()
{
	node_t * list = malloc(sizeof(node_t)); 
	
	//add nodes in the LL
	list->val = 1;
	list->next = malloc(sizeof(node_t));
	list->next->val = 2;
	list->next->next = malloc(sizeof(node_t));
	list->next->next->val = 3;
	list->next->next->next = NULL;
	
	// print the list
	//print_list(list);
	// push element at the back of list
	push_end(list, 4);
	// print list again
	print_list(list);
	// pop first element in the list
	//pop_first(&list);
	// print list again
	//print_list(list);
	// pop last element in the list
	//pop_last(list);
	// remove element at index 2
	remove_by_index(&list, 2);
	// print list
	print_list(list);
	
	
	
	return 0;
}

