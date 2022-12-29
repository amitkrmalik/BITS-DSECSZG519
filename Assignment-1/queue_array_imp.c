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

int getArrayImpChoice ( void ) {
	int choice;
	printf("\t1. Input into Array Queue from File (Multiple elements)\n");
	printf("\t2. Input into Array Queue from command line (Single Element)\n");
	printf("\t3. Remove element from Array Queue (Single Element)\n");
	printf("\t4. Press 0 to return main menu\n");	
    
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
 
void ArrayImpMain (void) {
	int choice;
	
	do {
    mmenu:
		choice = getArrayImpChoice();
		
		switch(choice) {
			case 1:
			case 2: 
			case 3: 
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
