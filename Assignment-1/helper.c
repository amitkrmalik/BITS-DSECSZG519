/*
----------------------------------------------------------------------------
 BITS WLIP : Data Science
 Data Structures and Algorithms Design (S1-22_DSECSZG519)
 DSAD Group 05
 	- AMIT KUMAR (2022cs04025)
 	- NARESH KUMAR K S
 	- RAJASEKHARUNI KRISHNA ARUN
----------------------------------------------------------------------------
 File Name: helper.c
    helper functions to be defined here and to be used under assignment.

 Input: cmd line inputs from user
 Output: 
----------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_array_imp.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Invalid arguments\nUsage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    /*
     * Initialise various methods here
     */
    Queue *q = init_QA();

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* field = strtok(line, ",");
        int i = atoi(field);
        // printf("string: %s: decimal : %d\n", field,i);
        push_QA(q, i);
    }
    // display_queue(q);
    printf("element 652876767: %d\n", search_element_QA(q, 652876767));

    fclose(file);
    return 0;
}