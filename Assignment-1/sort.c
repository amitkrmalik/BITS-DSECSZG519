#include <stdio.h>
#include <stdlib.h>

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
/*
void display_Queue(struct Queue *q) {
    printf("Queue: ");
    Node *curr = q->front;
    while (curr != NULL) {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
*/
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

/*
int search_element(struct Queue *q, int value) {
    Node *curr = q->front;
    while (curr != NULL) {
        curr = curr->next;
        if (curr->data == value) {
            return (1);
        }
    }
    return(0);
}
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

struct Node* middle(struct Node* start, struct Node* last) {
	if (start == NULL)
		return NULL;

	struct Node* slow = start;
	struct Node* fast = start -> next;

	while (fast != last)
	{
		fast = fast -> next;
		if (fast != last)
		{
			slow = slow -> next;
			fast = fast -> next;
		}
	}

	return slow;
}

struct Node* binarySearchiNew(struct Queue *q, int key) {
	struct Node *start = q->front;
    struct Node* last = NULL;
    if (q->front == NULL) {
        return NULL;
    }

	do 
	{
		struct Node* mid = middle(start, last);
		if (mid == NULL)
            return NULL;

		if (mid -> data == key)
            return mid;

		else if (mid -> data < key)
            start = mid -> next;

		else
            last = mid;
	} while ((last == NULL) || (last != start));
}



int main() {
    struct Queue *q = createQueue();
	int index;
    enqueue(q, 3);
    enqueue(q, 1);
    enqueue(q, 2);
    displayQueue(q);
    insertionSort(q);
    displayQueue(q);
	insertBefore(q,2,5);
    displayQueue(q);
	insertAfter(q, 5, 10);
    displayQueue(q);
    insertionSort(q);
    displayQueue(q);
	index = binarySearch(q, 5);
	printf("index at %d\n", index);
	
	if (binarySearchiNew(q,5) == NULL) {
		printf ("key not found\n");
	} else {
		printf ("Key present\n");
	}

    //printing sorted queue
    struct Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    return 0;
}

