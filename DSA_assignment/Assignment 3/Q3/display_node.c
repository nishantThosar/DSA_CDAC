/*This library contains the function definations to print the node value*/
#include<stdio.h>
#include"node_add.h"

void display_node(struct node *head)
{
    struct node *traverse = NULL;
    traverse = head;//assigning the head address to local pointer.
    printf("Printing list ");
    
    //Traverse the linked list.
    while (traverse != NULL)
    {
        printf("-->%d", traverse->data);// to print the value stored in each node.
    }//while ends.    

    printf("Done printing\n");

}// display node ends