/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: sorted_list.c
    Sorted List Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/
# include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

// EnqueueLL() operation on a queue
void enqueueLL(int value) {
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;
    } else {
        rear -> next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
}

// dequeueLL() operation on a queue
int dequeueLL() {
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    } else {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        return temp_data;
    }
}

// displayLL all elements of the queue
void displayLL() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        temp = front;
        while (temp) {
            printf("%d--->", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n\n");
    }
}

/* 
 * Function name: getChoice
 *  collects user choice to move forward with various inputs and process steps.
 * Input Args: None
 * return: integer choice
 */ 

int getLLImpChoice ( void ) {
	int choice;
    /*
 	printf("\t1. Input into List Queue from File\n");
	printf("\t2. Input into List Queue from command line\n");
	printf("\t3. Remove element from List Queue\n");
	printf("\t4. Input into Sorted List from File\n");
	printf("\t5. Input into Sorted List from command line\n");
	printf("\t6. Find element in Sorted List\n");
	printf("\t7. Remove element in Sorted List\n");    
	printf("\t8. Press 0 to return main menu\n");	
    */
    printf("New menu list-----------\n");
 	printf("\t1. add single element\n");
	printf("\t2. add elements using file\n");
	printf("\t3. delete element\n");
	printf("\t4. displayLL\n");
	printf("\t5. Press 0 to return main menu\n");	
 
    // read back user inputs
	printf("\nSelect an option: ");
	scanf("%d", &choice);
	return choice;
}
 
/* 
 * Function name: main
 *  Iterate over the user choice to move the program
 * Input Args: None
 * return: None
 */ 
 
void LLImpMain (void) {
	int choice;
	int value;

	do {
		choice = getLLImpChoice();
		
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueueLL(value);
                break;
			case 2: 
			case 3: 
                value = dequeueLL();
                printf("popped value: %d\n", value);
				break;
			case 4: 
				displayLL();
				break;
			case d: 
			caiec6: 
			case 7: 
				printf("choice entered: %d\n", choice);
				break;

			case 0: 
                printf("moving back to main menu\n");
				break;

			default: 
				printf("Please enter a valid choice\n");
				break;
		}
		printf("\n");

	} while(choice != 0);
}
