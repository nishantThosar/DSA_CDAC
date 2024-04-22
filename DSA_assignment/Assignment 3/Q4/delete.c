/*This library contains the function for
1.Delete node at start
2.Delete node at end
3.Delete node at position
*/
#include"insert.h"
#include<stdio.h>


/*This is the functio which deletes the node at the start of the linked list*/
void del_at_beg(struct student **head)
{
    struct student *temp = head;
    *head = temp->next;//Shifting the head to next node.
    temp->next = NULL;//Breaking the link between the first node and next node.
    free(temp);//returning the memory to heap pool.
}//Delete at begining ends

/**/
void del_at_end(struct student **head)
{
    struct student *trav = head;

    //To traverse till the end of list.
    while(trav->next != NULL){
        trav = trav->next;
    }//while loop ends

    
}// delete at end ends