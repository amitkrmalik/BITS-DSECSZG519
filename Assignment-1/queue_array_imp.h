/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: queue_array_imp.h
    Queue Array Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/
#define MAX_ARRAY_SIZE 10000 // Max array length supported


typedef struct queue {
    int items[MAX_ARRAY_SIZE];  // array where data shall be stored.
    int front; // Front element of the queue
	int rear;  // end element of the queue
} Queue;



Queue* init_QA();
void push_QA(Queue *q, int value);
int pop_QA(Queue *q);
int is_empty_QA(Queue *q);
int is_full_QA(Queue *q);
int size_QA(Queue *q);
void display_queue(Queue *q);
