/*This library contains the function for
1.Delete node at start
2.Delete node at end
3.Delete node at position
*/
#include"insert.h"
#include<stdio.h>
#include<ctype.h>


/*This is the functio which deletes the node at the start of the linked list*/
void del_at_beg(struct student **head)
{
    struct student *temp = head;
    *head = temp->next;//Shifting the head to next node.
    temp->next = NULL;//Breaking the link between the first node and next node.
    free(temp);//returning the memory to heap pool.
}//Delete at begining ends

/*In this function the traverse pointer traverse itself from head to the last node and then inserts NULL at the prevoius address of last node & then frees the last node.*/
void del_at_end(struct student **head)
{
    struct student *trav = head;
    

    //To traverse till the end of list.
    while(trav->next != NULL){
        trav = trav->next;
    }//while loop ends

    trav->prev->next = NULL; // assigns NULL to the next address of the previous node.
    trav->prev = NULL;//Assigns null to the previous address of current node.
    free(trav);//Returnes the memory to the heap pool.

}// delete at end ends


/*In this function first the position is evaluated if position given by user is 1 then delete at first function is called, while traversing if the last node is encountered
then the delete at end is called.(By default this function deletes the last node), if the privoius two conditions are false then the else loop is executed in which the node
on which the trav pointer is pointing is deleted.*/
void del_at_pos(struct student **head)
{
    int pos;//Temp var to store the position.
    struct student *trav = head;
    
    printf("Enter the position at which you want to delete the node: ");
    scanf("%d", &pos);
    
    //To check if the position entered by the user is numeric or not.
    if(isdigit(pos)){
        
        //if the position entered by user is 1 then call delete at start function.
        if(pos == 1){
            del_at_beg(head);//Calling delete at begning.
            return;
        }//if ends.
        
        //To traverse till the psition
        for(int i=0; i<pos; i++){
            trav = trav->next;
        }//for ends
        
        //After traversing if the next address of node is null then call delete at ends.
        if(trav->next = NULL){
            del_at_end(head);// calling delete at end.
        }// if ends
        
        /*If the position is not 1 nor the last node then the program will enter in this loop*/
        else{
            /*if current node is trav then, first inserting the next node address saved in the next of traverse is assigned to the previous next address*/
            trav->prev->next = trav->next;
            /*then the previous address of next node is assigned to the next node's privious address.*/
            trav->next->prev = trav->prev;

            //assigning NULL to both previous and next address in node.
            trav->prev = NULL;
            trav->next = NULL;
            free(trav);
        }//else ends

    }//if ends.
    else{
        printf("Error! you entered wrong input");
    }//else ends

}//delete at position ends