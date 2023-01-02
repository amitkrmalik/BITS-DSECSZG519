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
# include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ARRAY_LEN 10000

// A structure to represent a queue
struct QueueArray {
    int front;              // Front of the queue
    int rear;               // Rear of the queue
    int size;               // actual size of data
    unsigned capacity;      // Max capacity of queue
    int* array;             // Array pointer
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct QueueArray* CreateQueueArray(unsigned capacity)
{
    struct QueueArray* queue = (struct QueueArray*)malloc(
        						sizeof(struct QueueArray));
    queue->capacity = capacity;
    
    queue->front = -1;
    queue->rear = -1;
	queue->size = 0;
 
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}


// Queue is full when size becomes
// equal to the capacity
int isFull(struct QueueArray* queue)
{
    return (queue->rear == (queue->capacity - 1));
}
 
// Queue is empty when size is 0
int isEmpty(struct QueueArray* queue)
{
    return (queue->front == -1 || queue->front > queue->rear);
}


// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct QueueArray* queue, int item)
{
    if (isFull(queue)) {
		printf("queue if full: Overflow\n");
        return;
	}

	/* For first element 
	 * front = -1 and rear = -1 then set
     * front = 0 and rear = 0 otherwise increment rear alone
	 */
	if (queue->front == -1 && queue->rear== -1){
		queue->front = 0;
		queue->rear=0;
		queue->size == 0;
	} else {
	    queue->rear++;
		queue->size++;
	} 

	// Insert element at rear
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct QueueArray* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	} else {
		queue->front++;
		queue->size--;
	}
    return item;
}

int display_Array(struct QueueArray* queue)
{
    int i = 0;
	if (queue->front == -1) {
		printf ("queue is empty..\n");
		return;
	} else {
    	printf("Elements are:..\n");
		for(i = queue->front; i <= queue->rear; i++) {
			printf("%d, ",queue->array[i]);
		}
	}
	
}
/* 
 * Function name: getChoice
 *  collects user choice to move forward with various inputs and process steps.
 * Input Args: None
 * return: integer choice
 */ 

int getArrayImpChoice ( void ) {
	int choice;
    /*
	printf("\t1. Input into Array Queue from File (Multiple elements)\n");
	printf("\t2. Input into Array Queue from command line (Single Element)\n");
	printf("\t3. Remove element from Array Queue (Single Element)\n");
    */
	printf("\t1. add single element\n");
	printf("\t2. add elements using file\n");
	printf("\t3. delete element\n");
	printf("\t4. display\n");
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

}
