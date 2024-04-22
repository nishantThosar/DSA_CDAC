/*This file contains the defination of a function input_sort
The function takes input from user and by linear search finds the proper position and then inserts the node there.*/
#include<stdio.h>
#include"list_operation.h"
#include"node_add.h"

void input_sort(struct node **head)
{
    extern int no_of_ele;
    int val, pos = 0;//Temp var.
    printf("\n\nEnter the value of data: ");
    scanf("%d", &val);//user input of data.
    
    struct node *traverse = NULL;
    struct node *first = NULL;
    traverse = *head;
    first = traverse->next;
    while(traverse->next != NULL){
        //To find the position of element to insert.
        if(!(traverse->data<val && val<first->data)){
            pos++;// to get the position
            traverse = traverse->next;
        }//if ends.
        //If position is 1 then call add at positon.
        else if (pos == 1){
            insert_at_beg(head);
        }//if position is more than the no of elements.
        else if(pos>no_of_ele){
            add_at_end(head);
        }//else ends

    }//while ends

    //insert at position.
    struct node *temp = NULL;
    temp = node_maker();
    temp->data = val;
    temp->next = NULL;
    
    traverse = *head;

    //To traverse till the position
    for(int i=0; i<pos; i++){
        traverse = traverse->next;
    }//For loop ends    

    temp->next = traverse;
    traverse->next = temp;




}//input sort ends

/*This function does linear sort and returns the position*/