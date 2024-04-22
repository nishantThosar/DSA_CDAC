/*
This is user defined library for adding node operations like
1. Adding a new node
2. Inserting node at position.
3. Inserting node at end.
*/
 

#include<stdio.h>
#include<stdlib.h>
#include"node_add.h"// header file in which the structure is defined
/*This function makes node, does the null check and returns the node address to the calling function*/
struct node* node_maker(void)
{
   struct node *temp = NULL;
   
   temp = (struct node*)calloc(1,sizeof(struct node)); 
   //Null check.
   if(temp != NULL){
        perror("Memory allocation failed");
        exit(1);
   }// if ends
   else
    return temp;// returns the adress of the new node to the calling function.
}//Node maker ends

/*This function checks if the head is empty or not.
1. If the head is empty it calls the first node function & makes the first node of the list
2. If the head is not empty then the function makes a new node and then assigns the node to the privious of the current node.
*/
void insert_at_beg(struct node **head)
{
    //if head is null then call the first node function to make first node in the list.
    if(*head == NULL){
        first_node(head);//calling first node function.
        return;//after makin the first node return to the calling function (ie: main in this program).
    }//if ends.
    //if the node is not first then need to add the node at the begning
    else{
        int val;
        struct node *temp = NULL;
        temp = node_maker();
        printf("Enter the value to be stored in the node: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = *head; //Assigning the address to the next of new node
        *head = temp;       // changing the address stored in head so as to make the new node as the first node.
    }//else ends
}//insert at begining ends


/*This function makes the first node of the list and if the list is available already then to ask him at which place 
he wants to add the node*/
void first_node(struct node **head)
{
    if(head == NULL){
        printf("\n\nMaking First node...");
        int val;
        struct node *temp = NULL;

        temp = node_maker();//calling node maker
        printf("Enter the value to be stored in the first node: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = NULL;
        printf("\n\nFirst node made.");
    }
    /*If the list is already made then the options must be given to the user to
    1.Insert node at begining
    2.Insert node at end.
    3.Insert node at position
    The following code does the same*/
    else{
        int choice = 0;// Temp variable to hold choice value.
        printf("\n\nLink list is already made please enter the choice to make the node: ");
        printf("\n\n1. To make node at begning of list");
        printf("\n\n2. To insert node at end");
        printf("\n\n3. To insert node at position");
        printf("\n\n Enter the numerical choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: insert_at_beg(head);
            break;

            case2: add_at_end(head);
            break;

            case 3: insert_at_pos(head);
            break;
        }// switch ends
    }
}//first node ends


/*This function adds the node at the last of the list and also checks:
1. If the first node is made(if not then makes the first node)
2. If node is not first then traverse to the end of linked list by a temp ptr named "traverse" & then adds the node to last
*/
void add_at_end(struct node **head)
{
    //If head is null then it will call the first node function to make new node.
    if(head == NULL){
        first_node(head);
        return;
    }
    //In the else portion the node will be made and added in the last.
    else{
        struct node *traverse = NULL;// temp local ptr to  traverse.
        struct node *temp = NULL;
        traverse = *head;
        temp = node_maker();
        
        while(traverse->next != NULL){
            traverse = traverse->next;
        }// while ends
        traverse->next = temp;// when the traverse ptr is at last node then it will insert the node value at the next.
        temp->next = NULL;// inserting the null in the next of temp.
        int val;//Temporary variable for holding the value to be inserted at the data in the node.
        printf("Enter the data you want to store in the node: ");
        scanf("%d", &val);
        temp->data = val;
    }

}//Function Add at end ends.

/*This function inserts the node at the position, also exits the program if the position entered is out of scope of list.*/
void insert_at_pos(struct node **head)
{
    int val, pos;// pos to store the position at which the node is to be entered.
    struct node *temp = NULL;
    temp = node_maker();
    printf("\n\nEnter the data to be entered in node: ");
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;
    struct node *traverse = NULL;//Making a temp ptr to traverse to list.
    traverse = *head;

    //To traverse till the position
    for(int i=0; i<pos; i++){

        traverse = traverse->next;
        
        // If the traversing is done till the last node then call last node insertion function
        if(traverse->next = NULL){
            perror("\n\nThe scope is out of range of list");
            exit(0);
        }

    }//For loop ends    

    temp->next = traverse;
    traverse->next = temp;

}//Insert at position ends

/*Lbrary ends*/