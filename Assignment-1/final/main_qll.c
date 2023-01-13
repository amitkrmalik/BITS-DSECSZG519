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
#include "queue_ll_imp.h"

#define MAX_LINE_LENGTH 1024

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
    QueueLL *qLL = create_queueLL();

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
                
                if (!search_elementLL(qLL, i)) {
                    enqueueLL(qLL, i);
                }
            }    
        }
    }
   
	do {
   	
        choice = getArrayImpChoice();
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &key );
                enqueueLL(qLL, key);
                break;
			case 2:
                printf("Delete an element is :%d\n", dequeueLL(qLL));
                break;
			case 3:
				printf("\ndisplay elements of queue:\n");
                display_queueLL(qLL);
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
    free(qLL);
    exit(0);

    return (0);
}  
