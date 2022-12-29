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
# include <stdio.h>
#include <stdlib.h>
#include "queue_array_imp.h"
#include "queue_ll_imp.h"
#include "bst.h"

/*
 * choices to be implemented
 *
int getChoice ( void ) {
	int choice;
	printf("\t1. Input into Array Queue from File (Multiple elements)\n");
	printf("\t2. Input into Array Queue from command line (Single Element)\n");
	printf("\t3. Remove element from Array Queue (Single Element)\n");
	printf("\t4. Input into List Queue from File\n");
	printf("\t5. Input into List Queue from command line\n");
	printf("\t6. Remove element from List Queue\n");
	printf("\t7. Input into Sorted List from File\n");
	printf("\t8. Input into Sorted List from command line\n");
	printf("\t9. Find element in Sorted List\n");
	printf("\t10. Remove element in Sorted List\n");
	printf("\t11. Input into BST from File\n");
	printf("\t12. Input into BST from command line\n");
	printf("\t13. Find element in BST\n");
	printf("\t14. Remove element From BST\n");
	printf("\t15. Print BST in order\n");
	printf("\t16. Press 0 to exit\n");	
	printf("\nSelect an option: ");
    // read back user inputs
	scanf("%d", &choice);
	return choice;
}
*/

/* 
 * Function name: getChoice
 *  collects user choice to move forward with various inputs and process steps.
 * Input Args: None
 * return: integer choice
 */ 
 
int getMainChoice (void) {
	int choice;
	printf("\t1. Queue implementation using Array\n");
	printf("\t2. Queue implementation using Linked list\n");
	printf("\t3. BST\n");
	printf("\t4. Press 4 to exit\n");	
    
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
 
void main (void) {
	int choice;
	
	do {
		choice = getMainChoice();
		
		switch(choice) {
			case 1:
                ArrayImpMain();
                break;
			case 2:
               LLImpMain(); 
                break;
			case 3: 
                BSTImpMain();
				break;

			case 4: 
                printf("exit requested\n");
				break;

			default: 
				printf("Please enter a valid choice: moving back to main menu\n");
				break;
		}
		printf("\n");

	} while(choice != 4);
    printf("Exiting...\n");
    exit(0);
}
