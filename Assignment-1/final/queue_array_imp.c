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
     --> Internal function list
      --> init_QA : Init the Queue via Array
      --> push_QA_internal : Push a key to queue
      --> push_QA : Push an unique element to the queue 
      --> pop_QA : pop an element
      --> is_empty_QA : is queue empty
      --> is_full_QA : is queue full
      --> size_QA : size of the queue
      --> search_elementQA : search an element in queue
      --> display_queue : display queue elements

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "queue_array_imp.h"

#define TIME_Push "time_qa_push.csv"
#define TIME_Pop "time_qa_pop.csv"
#define TIME_search "time_qa_ser.csv"


/* 
 * Function name: init_QA
 *  initialise the queue to start storing the data.
 * Input Args: None
 * return: Queue
 */ 
 
Queue* init_QA() {
    Queue *q = malloc(sizeof(Queue));
    q->front = 0;
    q->rear = MAX_ARRAY_SIZE - 1;
    return q;
}

/* Function: push_QA
 *   search the key in the queue, append if not in queue
 * Input:
 *  Queue
 *  Key
 * Return:
 *  None
 */
void push_QA(Queue *q, int value) {
    clock_t t;
    double time_taken;
    FILE *tp = fopen(TIME_Push, "a+");
    if (!search_elementQA(q, value)) {
        t = clock();
        push_QA_internal(q, value);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(tp,"%f,\n", time_taken);
        fclose(tp);
    } else {
        printf ("\nduplicate entry.. \n");
    }
}
/* Function: push_QA_internal
 *   Append the key to queue
 * Input:
 *  Queue
 *  Key
 * Return:
 *  None
 */ 
void push_QA_internal(Queue *q, int value) {
    if (q->rear == MAX_ARRAY_SIZE - 1) {
        q->rear = -1;
    }
    q->items[++q->rear] = value;
}
 
/* Function: pop_QA
 *   Remove the key from queue
 * Input:
 *  Queue
 * Return:
 *  Key
 */  
int pop_QA(Queue *q) {
    clock_t t;
    double time_taken;
    FILE *to = fopen(TIME_Pop, "a+");
    t = clock();
    int value = q->items[q->front++];
    if (q->front == MAX_ARRAY_SIZE) {
        q->front = 0;
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(to,"%f,\n", time_taken);
    fclose(to);
    return value;
}

/* Function: is_empty_QA
 *   Queue empty check
 * Input:
 *  Queue
 * Return:
 *  Int
 */   
int is_empty_QA(Queue *q) {
    return q->front > q->rear;
}
/* Function: is_full_QA
 *   Queue Full check
 * Input:
 *  Queue
 * Return:
 *  Int
 */    
int is_full_QA(Queue *q) {
    return q->rear - q->front == MAX_ARRAY_SIZE - 1;
}
/* Function: size_QA
 *   Size of Queue
 * Input:
 *  Queue
 * Return:
 *  Int
 */     
int size_QA(Queue *q) {
	return (q->rear - q->front);
}

 /* Function: search_elementQA
 *   search element in queue
 * Input:
 *  Queue
 *  key
 * Return:
 *  Int : 1 is found.
 *  0 if not found
 */      
int search_elementQA(Queue *q, int value) {
    int i = 0;
    clock_t t;
    double time_taken;
    FILE *ts = fopen(TIME_search, "a+");
    t = clock();
    for (i = q->front; i <= q->rear; i++) {
        if (q->items[i] == value) {
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            fprintf(ts,"%f,\n", time_taken);
            fclose(ts);
            return (1);
        }
    }             
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(ts,"%f,\n", time_taken);
    fclose(ts);

    return (0);
}

/* Function: display_queue
 *   display element in queue
 * Input:
 *  Queue
 * Return:
 *  Void
 */ 
void display_queue(Queue *q) {
    int i = 0;
    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d -> ", q->items[i]);
    }
    printf("\n");
}
