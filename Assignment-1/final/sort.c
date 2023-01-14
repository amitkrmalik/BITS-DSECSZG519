 /*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: main.c
    Main functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024


struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;
    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    temp->prev = q->rear;
    q->rear = temp;
}

void insertionSort(struct Queue *q) {
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
}

void displayQueue(struct Queue *q) {
    if(q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *current = q->front;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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

int getSize(struct Queue *q) {
    int size = 0;
    struct Node *current = q->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

int binarySearch(struct Queue *q, int key) {
    if (q->front == NULL) {
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
            return mid;
        } else if (current->data > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int removeFromSortedList(struct Queue *q, int key) {
    int index = binarySearch(q, key);
    if (index == -1) {
        printf("Key not found\n");
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
    return value;
}

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
