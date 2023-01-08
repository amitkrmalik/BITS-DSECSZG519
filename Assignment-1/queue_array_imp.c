/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: queue_array_imp.c
    Queue Array Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/

/*---------------------------------------------------------------------------
            Headers section
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*---------------------------------------------------------------------------
            Constant definitions section
-----------------------------------------------------------------------------*/
#define MAX_ARRAY_SIZE 10000 // Max array length supported


/*---------------------------------------------------------------------------
            Global variables and defintiions
-----------------------------------------------------------------------------*/
typedef struct queue {
    int items[MAX_ARRAY_SIZE];  // array where data shall be stored.
    int front; // Front element of the queue
	int rear;  // end element of the queue
} Queue;


/* 
 * Function name: init_QA
 *  initialise the queue to start storing the data.
 * Input Args: None
 * return: None
 */ 
 
Queue* init_QA() {
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->rear = MAX_ARRAY_SIZE - 1;
    return q;
}

void push_QA(Queue *q, int value) {
    if (q->rear == MAX_ARRAY_SIZE - 1) {
        q->rear = -1;
    }
    q->items[++q->rear] = value;
}

int pop_QA(Queue *q) {
    int value = q->items[q->front++];
    if (q->front == MAX_ARRAY_SIZE) {
        q->front = 0;
    }
    return value;
}

int is_empty_QA(Queue *q) {
    return q->front > q->rear;
}

int is_full_QA(Queue *q) {
    return q->rear - q->front == MAX_ARRAY_SIZE - 1;
}

int size_QA(Queue *q) {
	return (q->rear - q->front);
/* 
 * Function name: main
 *  Iterate over the user choice to move the program
 * Input Args: None
 * return: None
 */ 
 
void ArrayImpMain (void) {
	int choice;
    int value;
    struct QueueArray* queue = CreateQueueArray(MAX_ARRAY_LEN);
   
	do {
   	
        choice = getArrayImpChoice();
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(queue, value);
                break;
			case 2: 
                printf("\nEnter the filename to insert elements: TBD");
                break;
			case 3:
                printf("Delete an element is :%d\n", dequeue(queue));
                break;
			case 4:
				printf("\ndisplay elements of queue:\n");
                display_Array(queue);
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
	// Free up the allocations done during the program
    free (q);
}
