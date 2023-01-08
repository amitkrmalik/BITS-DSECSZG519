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
#include "queue_array_imp.h"

/*---------------------------------------------------------------------------
            Constant definitions section
-----------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
            Global variables and defintiions
-----------------------------------------------------------------------------*/


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
}


int search_element_QA(Queue *q, int value) {
    int i = 0;
    for (i = q->front; i <= q->rear; i++) {
        if (q->items[i] == value) {
            return (1);
        }
    }
    return (0);
}

void display_queue(Queue *q) {
    int i = 0;
    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d -> ", q->items[i]);
    }
    printf("\n");
}

#if 0    
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
#endif
