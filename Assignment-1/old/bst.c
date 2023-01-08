/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: bst.c
    BST Implimentation functional module
     --> while loop to collect the user inputs

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/
# include <stdio.h>
#include <stdlib.h>


/* 
 * Function name: getChoice
 *  collects user choice to move forward with various inputs and process steps.
 * Input Args: None
 * return: integer choice
 */ 

int getBSTImpChoice ( void ) {
	int choice;
    printf("\t1. Input into BST from File\n");
	printf("\t2. Input into BST from command line\n");
	printf("\t3. Find element in BST\n");
	printf("\t4. Remove element From BST\n");
	printf("\t5. Print BST in order\n"); 
	printf("\t6. Press 0 to return main menu\n");	
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
 
void BSTImpMain (void) {
	int choice;
	
	do {
    mmenu:
		choice = getLLImpChoice();
		
		switch(choice) {
			case 1:
			case 2: 
			case 3: 
			case 4: 
			case 5: 
			case 6: 
			case 7: 
				printf("choice entered: %d\n", choice);
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
