/*This library is for sorting while inserting the element*/

#include<stdio.h>
#include<stdlib.h>
#include"insert.h"
#include"display.h"


void ip_sort(struct student **head)
{
    struct student *temp = NULL;
    temp = *head;
    int ele, count = 0;
    printf("Enter element to insert in the linked list: ");
    scanf("%d", &ele);

    while(temp->next != NULL){
        if( ele > temp->prn){
            ++count; 
        }//if ends
    }//if ends
    insert_at_pos(head,count);
    
    display_list(head);


}//input sort ends
