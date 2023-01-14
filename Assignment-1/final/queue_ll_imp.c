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
    Queue List Implimentation functional module
     --> Internal function list
      --> create_queueLL: Init the queue List
      --> enqueueLL_internal: enqueue a key to the list
      --> enqueueLL: enqueue a unique key to the list
      --> dequeueLL : pop an element
      --> is_emptyLL : is queue empty
      --> display_queueLL : display elements of queue
      --> search_elementLL : search element in queue

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
#include "queue_ll_imp.h"


QueueLL* create_queueLL() {
    QueueLL *q = malloc(sizeof(QueueLL));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueueLL_internal(QueueLL *q, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        new_node->prev = q->rear;
        q->rear = new_node;
    }
}

void enqueueLL(QueueLL *q, int value) {
    if (!search_elementLL(q, value)) {
        enqueueLL_internal(q, value);
    } else {
        printf ("duplicate entry\n");
    }
}
 
int dequeueLL(QueueLL *q) {
    if (q->front == NULL) {
        fprintf(stderr, "Error: Queue is empty\n");
        exit(1);
    }

    int value = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }
    free(temp);
    return value;
}

int is_emptyLL(QueueLL *q) {
    return q->front == NULL;
}

void display_queueLL(QueueLL *q) {
    printf("Queue: ");
    Node *curr = q->front;
    while (curr != NULL) {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int search_elementLL(QueueLL *q, int value) {
    Node *curr = q->front;
    if (q->front == NULL) {
        return (0);
    }
    while ((curr != NULL) && (curr->next != NULL)) {
        curr = curr->next;
        if (curr->data == value) {
            return (1);
        }
    }
    return(0);
}
