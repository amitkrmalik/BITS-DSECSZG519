
#include <stdio.h>
#include <stdlib.h>


// Structure to create a Node 
struct node {
    int key;
    struct node *left, *right;
};
 
// Structure for Tree Node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Print Tree in inorder method 
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 
/* Insert Element to BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}


// Finding the min value node to replace element in deletion 
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Finding an element in BST

int findElement(struct node* node,int value)
{
        struct node* current = node;
        if(node->key==value)
        {
            return 1;
        }
        while(current!=NULL)
        {
            if(current->key>value)
            {
                current=current->left;
            }
            if(current->key==value)
            {
                return 1;
            }
            if(current->key<value)
            {
            current=current->right;

            }
        }
        return -1;
    
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


int main(int argc,char* argv[]) {
    struct node* root = NULL;
    printf("BST Implementation \n");
    printf("Press -1 to Exit Menu\n");
    int choice=0;
    while(choice!=-1)
    {
    printf("Menu\n 1. Insert elements from Command line \n 2.Insert elements from File \n 3. Delete an Element \n 4.Print Tree Inorder \n 5.Exit\n");
    scanf("%d",&choice);
    printf("Input : %d\n",choice);
    switch(choice)
    {
        case 1:
        printf("Inserting Elements from Command Line ");
        if(argc==1){
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
        }
        if(argc>=2)
        {
        printf("\nNumber Of Arguments Passed: %d",argc);
        printf("\n----Following Are The Command Line Arguments Passed----");
        int counter;
        for(counter=1;counter<argc;counter++)
        {
            printf("\nargv[%d]: %s",counter,argv[counter]);
            int value=atoi(argv[counter]);
        
            if(root==NULL)
            {
            root = insert(root,value);

            }
            else
            {
                insert(root,value);
            }
        }
        }
        
        printf("Exiting Insertion from Command Line ");
        break;
        
        case 2:
        /*
        FILE* ptr;
        char ch;
        prinf("File Name : %s ",argv[1]);
        // Opening file in reading mode
        ptr = fopen(argv[1], "r");
 
        if (NULL == ptr) {
        printf("file can't be opened \n");
        break;
        }
 
        printf("content of this file are \n");
 
    // Printing what is written in file
    // character by character using loop.
        printf("\nNumbers:\n");
        while ( (num = getw(fptr)) != EOF ) {
        printf("%d\n", num);
        
        if(root==NULL)
        {
        root = insert(root,num);

        }
        else
        {
        insert(root,num);
        }
        
        }
        */
        break;

        
        
        case 3:
        printf("Enter an element to be deleted \n");
        int element;
        scanf("%d",&element);
        if(root==NULL)
        {
            printf("Empty Tree");
        }
        else
        {
            
        deleteNode(root,element);
        printf("Node Deleted Sucessfully \n");
        printf("Tree Post Deletion \n");
        inorder(root);
        }
        break;
        
        case 4:
        printf("Inorder for the BST \n");
        inorder(root);
        break;
        
        case 5:
        printf("Exit");
        choice=-1;
        break;
        
        
    }
    
        
    }


    return 0;
}