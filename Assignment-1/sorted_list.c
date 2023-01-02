/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: sorted_list.c
    Sortel list implemenation
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/
# include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/* 
 * Function name: getChoice
 *  collects user choice to move forward with various inputs and process steps.
 * Input Args: None
 * return: integer choice
 */ 

int SortedLLImpChoice ( void ) {
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
 
void SortedLLImpMain (void) {
	int choice;
    int value;
    
	do {
   	
        choice = SortedLLImpChoice();
		switch(choice) {
			case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                break;
			case 2: 
                printf("\nEnter the filename to insert elements: TBD");
                break;
			case 3:
                printf("Delete an element is :%d\n", dequeue(queue));
                break;
			case 4:
				printf("\ndisplay elements of queue:\n");
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
