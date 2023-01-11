/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
    - AMIT KUMAR (2022cs04025)
    - NARESH KUMAR K S
    - RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: queue_ll_imp.h
    Queue Array Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output:
----------------------------------------------------------------------------
*/

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

typedef struct queue_ll {
    Node *front;
    Node *rear;
} QueueLL;

QueueLL* create_queueLL();

void enqueueLL(QueueLL *q, int value);
int dequeueLL(QueueLL *q);
int is_emptyLL(QueueLL *q);
void display_queueLL(QueueLL *q);
