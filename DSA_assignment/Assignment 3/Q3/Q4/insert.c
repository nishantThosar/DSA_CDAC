/*This library contains all the functions to 
1. Insert At end
2. Insert at begning
3. Insert at position
4. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"insert.h"
#include"display.h"
/*Function to make node, this function also does a null check and terminates the program if calloc returns null.*/
struct student* node_maker(void)
{
    struct student *stu= NULL;
    stu = (struct student*)calloc(1, sizeof(struct student));
    //Null check.
    if(stu == NULL){
        perror("Memory allocation failed");
        exit(1);
    }//If ends
    else{
        return stu;
    }//else ends
    
}//node maker ends.

/*To insert the name at the heap I have done calloc the name for efficiently allocating the memory in the heap.*/
char* name_memory()
{
    char buff[100];// for buffer.
    printf("\n\nEnter the name of student: ");
    scanf(" %[^\n]s", buff);
    int size = strlen(buff);

    char *t = (char*)calloc(size, sizeof(char));
    //NULL check
    if (t == NULL)
    {
        perror("\nName memory allocation failed");
        exit(1);
    }//if ends
    else{
            
        strcpy(t,buff);// to copy the name to the heap memory.
        return t;
    }//Else ends    
}


/*This function makes first node in the list*/
void first_node(struct student **head)
{
    int prn;// Temp int var.
    char *name_ptr = NULL;// Temp ptr var
    struct student *temp = NULL; // made a local pointer to struct.
    temp = node_maker();  //To make a node. 
    name_ptr = name_memory();// allocating the name dynamically.
    //Assigning next and prev of the node NULL, as it is the first node.
    temp->prev = NULL;
    temp->next = NULL;
    temp->name = name_ptr;//Assigning the returned address to string to char ptr in structure.
    printf("\nEnter the PRN of student: ");
    scanf("%d", &prn);//User input of PRN.
    temp->prn = prn;//Asigning to struct.
    printf("\n\nFirst node inserted.\n");
    *head = temp; 
}//first node function ends.

/*This function checks first if the list is empty, if its empty then inserts first node*/
void insert_at_begining(struct student **head)
{
    //If the first node is not made then making the first node.
    if(*head == NULL){
        printf("\n\nThe list is not started yet, making first node...");
        first_node(head);
    }// if ends
    else
    {
        int prn;
        char *name_ptr = NULL;// char ptr to store the return address of string from name_memory function.
        struct student *temp = NULL;//Temp struct ptr.
        name_ptr = name_memory();//user input of name.
        temp = node_maker();
        (*head)->prev = temp; // assigning the previous address of the first node to the prev address.
        temp->next = *head;//Assigning the head address to the next.
        *head = temp;//moving the head ptr to privious node.
        temp->prev = NULL;// Assigning the prev of temp to null as it is the first node of list.    
    }//else ends
    
}// insert at begning ends

/*This function is to insert student information at the start of list*/
void insert_at_end(struct student **head)
{
    //if the linked list is empty then call first node function.
    if(*head == NULL){
            first_node(head);
    }// if ends
    //if list is already avaliable then traverse to the last node then attach the node to it & keep the next address NULL.
   else
   {
        int prn;
        char *ch = NULL;
        struct student *trav = *head;
        //To traverse till the last of list.
        while (trav->next != NULL)
        {
            trav = trav->next;
        }// while ends

        struct student *temp = node_maker();
        trav->next = temp;
        temp->prev = trav;
        printf("Enter the PRN of student: ");
        scanf("%d", &temp->prn);
        temp->name = name_memory();
   }//else ends
   

}// Insert at end ends

/*Enter the node at position*/
void insert_at_pos(struct student **head)
{
    // checking if the first node is made or not if the first node is not made then make the first node.
    if (*head == NULL)
    {
        first_node(head);
    }//if ends.
    //If the first node is made.
    else
    {
        int pos;
        printf("\nEnter the position at which you want to enter the student: ");
        scanf("%d", &pos);
        //if the user inputs 1st position then call insert at begining.
        if(pos ==1){
            insert_at_begining(head);
            return;
        }
        struct student *trav = head;
        //To traverse the pointer till the position -1.
        for(int i=0 ; i<pos; i++){
            trav = trav->next;
        }// for ends
     
        struct student *temp = node_maker();//Making a new node.
        temp->name = name_memory();//inserting the name in the node
        printf("\nEnter PRN of student: ");
        scanf("%d", &temp->prn);//inserting the prn.

        /*In the below 4 line of code the new node is inserted at the position by breaking the link between the existing nodes
        and making new links in between new node.*/
        temp->prev = trav;
        temp->next = trav->next;
        trav->next->prev = temp;
        trav->next = temp;
        
    }//else ends
}//insert at pos ends