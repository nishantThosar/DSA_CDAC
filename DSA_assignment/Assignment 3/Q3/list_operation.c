/*This library contains defination to 
1.Reverse display
2.Reverse the linked list
3.Sort the linked list*/

#include<stdio.h>
#include"node_add.h"
void reverse_display(struct node *head)
{
    int count = 0;// to store the count.
    int *temp = NULL; // temp local ptr to store the return address of calloc.
    struct node *trav = NULL;
    trav = head;

    while (trav->next != NULL){
        trav = trav->next;
        ++count;    
    }//while ends

    temp = (int*)calloc(count, sizeof(struct node));
    //Null check
    if(temp == NULL){
        perror("\nError in allocating memory.");
    }
    trav = head;
    int i=0;
    while(trav != NULL){
        temp[i] = trav->data;
        i++;
    }// while ends
    for (int j = i; j >= 0 ; j--){
        printf("%d<--", temp[j]);
    }//for ends

    free(temp);
}// reverse list ends

//Function to reverse the linked list reverse
void reverse_list(struct node **head)
{
    struct node *first = NULL;
    struct node *prev = NULL;
    struct node *current = NULL;

    first = prev = current = *head;// assigning all pointers to head
    
    //To reverse the nodes.
    while (first != NULL){
        first  = first->next;
        current = current->next;
        prev->next = NULL;

        first = first->next;
        current->next = prev;

        prev = current;
        current = first;
        current->next = prev;
        
        first = first->next;

    }// while ends
    head = current;
}//reverse list ends

/*This function first assigns the local pointers to head and next to head nodes, then compares it if the data in the first node
is greater then it swapps it*/
void sort_node(struct node **head)
{
    struct node *temp = NULL;
    struct node *first = NULL;
    temp = *head;
    first = (*head)->next;
    int count = 0 ;
    int inner_count;
    do{
        inner_count = 0;
        while(first->next){
            //Swapping the lists.
            if(temp->data > first->data){
                int tempData = temp->data;
                temp->data = first->data;
                first->data = temp;
            }//if ends
            temp = temp->next;
            first = first->next;
            inner_count++;
        }//while ends
        count++;        
    }while(count< inner_count);// do while ends
}//sort node ends

