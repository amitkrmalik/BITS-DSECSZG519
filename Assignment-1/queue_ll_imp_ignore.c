/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: queue_ll_imp.c
    Queue Linked List Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/
# include <stdio.h>
#include <stdlib.h>


//Linked Linked [LL] Node
struct QNode {
    int key;
    struct QNode* next;
};

struct Queue {
    struct QNode *front, *rear;
};

struct QNode* newNode(int k)
{
    struct QNode* temp
        = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
 
// A utility function to create an empty queue
struct Queue* createQueue()
{
    struct Queue* q
        = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(struct Queue* q, int k)
{
    // Create a new LL node
    struct QNode* temp = newNode(k);
 
    // If queue is empty, then new node is front and rear
    // both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
// Function to remove a key from given queue q
void deQueue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
 
    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;
 
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

int display_queue(struct Queue* q)
{
    struct Queue* last = NULL;

	while (q != NULL) {
		printf("%d->", q->key);
		last = q;
		q = q->next;
	}
	if (q == NULL)
		printf("NULL\n");
   
}
/
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
 
void LLImpMain (void) {
	int choice;
	int value;
	struct Queue* q = createQueue();

	do {
		choice = getLLImpChoice();
		
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(q, value);
                break;
			case 2: 
			case 3: 
				break;
			case 4: 
				display_queue(q);
				break;
			case 5: 
			case 6: 
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
