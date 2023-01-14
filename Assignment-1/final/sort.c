 /*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: sort.c
    -> Structure definetion
    -> Function:
     --> createQueue : Init the list
     --> enqueue : Enqueue element to list
     --> insertionSort : sort the list
     --> displayQueue : display the list elements
     --> search : search an element in list
     --> insertBefore : Insert an element before
     --> insertAfter : Insert an element after
     --> getSize : size of the list
     --> binarySearch : binary search an element
     --> removeFromSortedList : remove from sorted list
     --> main : main driver function


----------------------------------------------------------------------------
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Max string length for file input */
#define MAX_LINE_LENGTH 1024

#define TIME_Push "time_sort_push.csv"
#define TIME_Pop "time_sort_pop.csv"
#define TIME_search "time_sort_ser.csv"
#define TIME_sort "time_sort_sort.csv"


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

/* 
 * Function name: createQueue
 *  initialise the Linked list to start storing the elements.
 * Input Args: None
 * return: Queue
 */ 
struct Queue *createQueue(void) {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

/* 
 * Function name: enqueue
 *  enqueue an unsorted element to the linked list
 * Input Args: 
 *  Queue
 *  Key
 * return: 
 *  Void
 */ 
void enqueue(struct Queue *q, int value) {
    clock_t t;
    double time_taken;
    FILE *tp = fopen(TIME_Push, "a+");
    t = clock();
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = temp;
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(tp,"%f,\n", time_taken);
        fclose(tp);
        return;
    }
    q->rear->next = temp;
    temp->prev = q->rear;
    q->rear = temp;
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(tp,"%f,\n", time_taken);
    fclose(tp);
}

/* 
 * Function name: insertionSort
 *  sort the elements in assending order of a given queue
 * Input Args: 
 *  Queue
 * return: 
 *  Void
 */ 
void insertionSort(struct Queue *q) {
    clock_t t;
    double time_taken;
    FILE *ti = fopen(TIME_sort, "a+");
    t = clock();
    if (q->front == q->rear) return;
    struct Node *current, *iter;
    for (current = q->front->next; current != NULL; current = current->next) {
        int temp = current->data;
        for (iter = current->prev; iter != NULL && iter->data > temp; iter = iter->prev) {
            iter->next->data = iter->data;
        }
        if (iter != NULL) iter->next->data = temp;
        else q->front->data = temp;
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(ti,"%f,\n", time_taken);
    fclose(ti);
}

/* 
 * Function name: displayQueue
 *  display elements of list
 * Input Args: 
 *  Queue
 * return: 
 *  Void
 */  
void displayQueue(struct Queue *q) {
    if(q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *current = q->front;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* 
 * Function name: search
 *  search element in a list
 * Input Args: 
 *  Queue
 *  key
 * return: 
 *  index of element
 */   
int search(struct Queue *q, int key) {
    if(q->front == NULL) {
        return -1;
    }
    struct Node *current = q->front;
    int index = 0;
    while(current != NULL) {
        if (current->data == key) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

/* 
 * Function name: insertBefore
 *  insert the element before the key
 * Input Args: 
 *  Queue
 *  search key
 *  key
 * return: 
 *  void
 */    
void insertBefore(struct Queue *q, int key, int value) {
    int index = search(q, key);
    if (index == -1) {
        printf("Element not found\n");
        return;
    }
    struct Node *current = q->front;
    int i;
    for (i = 0; i < index; i++) {
        current = current->next;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = current->prev;
    temp->next = current;
    current->prev->next = temp;
    current->prev = temp;
}
/* 
 * Function name: insertAfter
 *  insert the element after the key
 * Input Args: 
 *  Queue
 *  search key
 *  key
 * return: 
 *  void
 */     
void insertAfter(struct Queue *q, int key, int value) {
    int index = search(q, key);
    if (index == -1) {
        printf("Element not found\n");
        return;
    }
    struct Node *current = q->front;
    int i;
    for (i = 0; i <= index; i++) {
        current = current->next;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = current;
    temp->next = current->next;
    current->next->prev = temp;
    current->next = temp;
}

/* 
 * Function name: getSize
 *  size of the linked list
 * Input Args: 
 *  Queue
 * return: 
 *  int size
 */ 
int getSize(struct Queue *q) {
    int size = 0;
    struct Node *current = q->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

/* 
 * Function name: binarySearch
 *  search key in linked list
 * Input Args: 
 *  Queue
 *  key
 * return: 
 *  int index.
 */  
int binarySearch(struct Queue *q, int key) {
    clock_t t;
    double time_taken;
    FILE *ts = fopen(TIME_search, "a+");
    t = clock();
    if (q->front == NULL) {
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(ts,"%f,\n", time_taken);
        fclose(ts);
        return -1;
    }
    int left = 0;
    int right = getSize(q) - 1;
    struct Node *current = q->front;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int i;
        current = q->front;
        for (i = 0 ; i < mid; i++) {
            current = current->next;
            printf ("data : %d -> ", current->data);
        }
        if (current->data == key) {
            t = clock() - t;
            time_taken = ((double)t)/CLOCKS_PER_SEC;
            fprintf(ts,"%f,\n", time_taken);
            fclose(ts);
            return mid;
        } else if (current->data > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(ts,"%f,\n", time_taken);
    fclose(ts);
    return -1;
}

/* 
 * Function name: removeFromSortedList
 *  remove element from a sorted list
 * Input Args: 
 *  Queue
 *  key to be removed
 * return: 
 *  int key value.
 */   
int removeFromSortedList(struct Queue *q, int key) {
    clock_t t;
    double time_taken;
    FILE *to = fopen(TIME_Pop, "a+");
    t = clock();
    int index = binarySearch(q, key);
    if (index == -1) {
        printf("Key not found\n");
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(to,"%f,\n", time_taken);
        fclose(to);
        return -1;
    }
    struct Node *current = q->front;
    int i;
    for (i = 0; i < index; i++) {
        current = current->next;
    }
    if (current->prev == NULL) {
        q->front = current->next;
    } else {
        current->prev->next = current->next;
    }
    if (current->next == NULL) {
        q->rear = current->prev;
    } else {
        current->next->prev = current->prev;
    }
    int value = current->data;
    free(current);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(to,"%f,\n", time_taken);
    fclose(to);
    return value;
}

/* Function: 
 *  getArrayImpChoice
 * Input: 
 *  None
 * Return:
 *  Int : choice based on user inputs
 */     
int getArrayImpChoice ( void ) {
	int choice;

	printf("\t1. push element\n");
	printf("\t2. pop element\n");
	printf("\t3. display\n");
	printf("\t4. exit\n");
    
    // read back user inputs
	printf("\nSelect an option: ");
	scanf("%d", &choice);
	return choice;
}
/* 
 * Function:
 *  main
 * Input: 
 *  filename for inputs [optional]
 * return:
 *  Int: exit status
 */     
int main (int argc, char* argv[]) {
	int choice;
    int key;
    struct Queue *SL = createQueue();

    if (argc > 2) {
        fprintf(stderr, "Error: Invalid arguments\n\tUsage: %s\n\tUsage: %s <filename>\n", argv[0],argv[0]);
        return (1);
    } else if (argc == 2) {

        FILE* file = fopen(argv[1], "r");
        if (file == NULL) {
            fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
            return 1;
        } else {

            char line[MAX_LINE_LENGTH];
            while (fgets(line, MAX_LINE_LENGTH, file)) {
                char* field = strtok(line, ",");
                int i = atoi(field);
                
                enqueue(SL, i);
            }    
            insertionSort(SL);
        }
    }
   
	do {
   	
        choice = getArrayImpChoice();
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &key );
                enqueue(SL, key);
                insertionSort(SL);
                break;
			case 2:
                printf("\ncurrent queue is :\n");
				displayQueue(SL);
                printf("\nEnter the Key to be removed : ");
                scanf("%d", &key );
				removeFromSortedList(SL, key);
                break;
			case 3:
				printf("\ndisplay elements of queue:\n");
                insertionSort(SL);
                displayQueue(SL);
				break;
			case 4:
                printf("exit requested\n");
				break;
			default:
				printf("Please enter a valid choice\n");
				break;
		}
		printf("\n");

	} while(choice != 4);
    free(SL);
    exit(0);

    return (0);
}  
