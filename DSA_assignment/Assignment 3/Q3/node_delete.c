/*This library is for deleting operations on linked list also can free all nodes*/
#include<stdio.h>
#include<stdlib.h>
#include"node_add.h"

void delete_at_end(struct node *head)
{
    struct node *delete = NULL;// delete ptr will traverse in the list.
    delete = head;
    struct node *backup = NULL;
    
    //To traverse till the last node of linked list
    while (delete->next !=NULL){ 
        backup = delete;  
        delete = delete->next;
    }// while ends
    
    backup->next = NULL;
    delete->data = 0;
    free(delete);

}//Delete at end ends

/*This function deletes the node at the position if the position inserted by user is 1 then it calls delete at first function*/
void delete_at_pos(struct node *head)
{
    int pos;
    printf("Enter the position which you want to delete: ");
    scanf("%d", &pos);
    //Is user enters 1 as position then the  program must call delete at first position.
    if(pos != 1){
        struct node *traverse = NULL;
        struct node *backup = NULL;
        traverse = head;
        for(int i=0; i<pos;i++){
            traverse = traverse->next;
        }// for ends
        backup->next = traverse->next;// assigning the next address to the previous node of list.
        traverse->next = NULL;
        traverse->data = 0;
    }
    else{
        delete_first_node(&head);// calling the delete at first if position =1
        return;
    }//Else ends
}//delete at position ends

void delete_first_node(struct node **head)
{
    struct node *delete = NULL;
    struct node *temp = NULL;
    delete = *head;
    *head = (*head)->next;
    delete->next = NULL;
    delete->data = 0;
    free(delete);
}// Delete first node


/*To free all nodes*/
void free_all(struct node **head)
{
    struct node *traverse = NULL;
    struct node *backup = NULL;
    traverse = *head;
    while(traverse){
        backup = traverse;
        traverse = traverse->next;
        free(backup);
    }//While ends
    free(*head);

}//free all ends

/*This function first finds the element and then deletes the node*/
void delete_from_element( struct node **head)
{
    int target;// local var to store the target element.
    printf("\nEnter the element to find: ");
    scanf("%d", &target);
    struct node *traverse = NULL;
    struct node *back = NULL;
    traverse = *head;
    
    while(traverse->next != NULL){
        back = traverse;
        traverse = traverse->next;
        
        //to find the element and free the node.
        if(traverse->data == target){
            back->next = traverse->next;
            traverse->data = 0;// Inplictly putting 0 so as to avoide any data leak.
            traverse->next = NULL;// to nullify the next node data in the node.
            free(traverse);// to freee the node
        }//if ends
    }// while ends

    
}//delete from element