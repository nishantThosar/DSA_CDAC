/*This library contains definations of function to free all nodes in the link list*/

#include<stdio.h>
#include"insert.h"

/*Function to free all nodes in the linked list
This function frees all nodes starting from first to the last*/
void free_all(struct student **head)
{
    struct student *trav = head;
    while (trav != NULL)
    {

        trav = trav->next;//Will traverse to the next node
        trav->prev = NULL;//inserting explictly null in the address pointer of next and pre
        trav->next = NULL;
        free(trav);// freeing the node
    }
    *head->next = NULL;//inserting explictly NULL in the next of head as head is remaining to be freed.
    free(head);//freeing the head.
    
}//free all ends
