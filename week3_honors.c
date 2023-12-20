/*  This program contains an implementation of doubly linked lists as a standalone type in C. It includes basic
    functionalities for creating, reaching and removing nodes, and creating, counting, and sorting operations for
    the linked lists.  

    This program uses the second option for removing the duplicate data; that is, assigning a pointer node from the 
    beginning, removing the duplicates to the end of the pointer, and iterating the pointer until the end of the list.
    Nevertheless, this code provides a Bubble Sort implementation that can be used for the first duplicate removal
    algorithm. 

    Written by: Cemre Omer Ayna
*/

#include <stdio.h>
#include <time.h>

/* Initializing system constants */
#define RAND_LIST_SIZE 200
#define RAND_MAX_NUM 49

/* A doubly linked list node defined as its own data type. */
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

/* This function creates a new node. */
node* create_node(int new_data, node* prev_node, node* next_node){
    node* new_node = malloc(sizeof(node));          // Allocating memory chunk for the new node
    new_node -> data = new_data;
    new_node -> prev = prev_node;
    new_node -> next = next_node;
    return new_node;
}

/* This function returns a node at the given index from a linked list. */
node* fetch_node(node* head_node, int index){
    for(int iter=0; iter<index; iter++)             // Iterating forward through the list until the right index
        head_node = head_node -> next;
    return head_node;
}

/* This function removes a node from a linked list. */
node* remove_node(node* head_node, node* rm_node){
    /* We need to control both the previous and the next node. */
    node* next_node = rm_node -> next;
    node* prev_node = rm_node -> prev;
    if(next_node != NULL)                           // If there is a next node, change its previous node address.
        next_node -> prev = prev_node;
    if(prev_node != NULL)                           // If there is a previous node, change its next node address.
        prev_node -> next = next_node;
    else                                            // If none, we need to assign the next node as the head of the linked list.
        head_node = next_node;
    free(rm_node);
    return head_node;
}

/* This function prints the important variables regarding the node object. */
void print_node(node* node){
    printf("Node address: %p\n", node);
    printf("Node data value: %d\n", (node -> data));
    printf("Previous node's address: %p\n", (node-> prev));
    printf("Next node's address: %p\n\n", (node-> next));
}

/* This function creates a linked list with a given set of data. */
node* create_list(int data_list[], int size){
    node* head_node = create_node(data_list[0],     // The head node of the linked list
                        NULL,
                        NULL);
    node* init_node = head_node;
    for(int iter=1; iter<size; iter++){             // Iterating through the next node and adding new one until the size condition is met
        node* next_node = create_node(data_list[iter], 
                            init_node,
                            NULL);
        init_node -> next = next_node;
        init_node = next_node;
    }
    return head_node;
}

/* This function counts the number of the nodes in a doubly linked list and returns that number. */
int count_list(node* ll_list){
    int count = 1;                                  // Counter begins at 1 with the head node.
    while((ll_list -> next) != NULL){
        ll_list = (ll_list -> next);
        count++;
    }
    return count;
}

/*  This function applies Bubble Sort to a linked list.*/
void sort_list(node* head_list){
    node* init_node = head_list;                    // The pointer node
    while((init_node -> next) != NULL){
        node* next_node = init_node -> next;        // Iterator to the right of the pointer node
        while((next_node -> next) != NULL){         // Scanning throught the rest of the nodes connected to the current one

        /* If the node closer to head has a bigger value than the node closer to the tail, swap the values. */
            if((init_node -> data) > (next_node -> data)){ 
                int tmp = init_node -> data;
                init_node -> data = next_node -> data;
                next_node -> data = tmp;
            }
            next_node = next_node -> next;
        }
        init_node = init_node -> next;              // Iterating to the next node
    }
}

/* This function removes the duplicate data from a given linked list. */
node* remove_duplicates(node* random_list){
    node* init_node = random_list;                  // Pointer node
    node* head_node = random_list;
    while(init_node -> next != NULL){               // Iterating through the list
        int init_data = init_node -> data;
        node* next_node = init_node -> next;
        while(next_node -> next != NULL){           // Iterating through the list to the right side of the pointer node
            if((next_node -> data) == init_data)    // Removing the next node if it has the same data as the pointer node
                remove_node(next_node, next_node);
            else
                next_node = next_node -> next;
        }
        init_node = init_node -> next;
    }
    return head_node;
}

int main(void){
    srand(time(NULL));

    /* A small test node to control basic functions. 
    int test_list[] = {1,2,3,4,5};
    node* test_ll_list = create_list(test_list, 5);
    print_node(fetch_node(test_ll_list, 0));
    print_node(fetch_node(test_ll_list, 1));
    print_node(fetch_node(test_ll_list, 2));
    print_node(fetch_node(test_ll_list, 3));
    test_ll_list = remove_node(test_ll_list, fetch_node(test_ll_list, 4));
    print_node(fetch_node(test_ll_list, 4));

    /* Creating a list of size 200 of random integers between (0,49) */
    int rand_array[RAND_LIST_SIZE];
    for(int iter=0; iter<RAND_LIST_SIZE; iter++)
        rand_array[iter] = rand() % RAND_MAX_NUM;

    node* linked_list = create_list(rand_array, RAND_LIST_SIZE);

    /* Printing out the generated numbers. */
    printf("Number of nodes in the newly generated random linked list: %d\n", count_list(linked_list));
    printf("Random data list:\n");
    for(int iter=0; iter<RAND_LIST_SIZE; iter++)
        printf("%d\t", rand_array[iter]);

    /* Removing the duplicates in the linked list and printing out the new list */
    printf("\nRemoving nodes with duplicate data...\n");
    linked_list = remove_duplicates(linked_list);
    printf("\nNumber of nodes in the cleaned random linked list: %d\n", count_list(linked_list));
    int cleaned_rand_list[count_list(linked_list)];
    printf("Removed data list:\n");
    for(int iter=0; iter<count_list(linked_list); iter++){
        cleaned_rand_list[iter] = fetch_node(linked_list, iter) -> data;
        printf("%d\t", cleaned_rand_list[iter]);
    }
    return 0;
}