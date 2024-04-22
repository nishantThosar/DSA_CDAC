/*Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList */


#include<stdio.h>
#include<stdlib.h>
#include"node_add.h"// This library contains to the insert functions to linked list and structure of linked list
#include"node_delete.h"// This library contains the delete operations for the linked list.
#include"display_node.h"//This library contains the function declarations to display the values in list.
#include"list_operation.h"//This library contains declarations of reversing the list, sorting the list and reverse displaying the list.
#include"input_sort.h"//This library takes the input of the element and then evaluates it to insert it at end or in between or at the end.


int no_of_element = 0;// variable to store the element count.
int main()
{
    
    int choice;// to keep user input of switch case choice.
    struct node *head = NULL;//Structure pointer (head pointer).
    //Menu starts.
    while(1){
        printf("\n1-> Insert at \"End\"");
        printf("\n2-> Insert at \"Begining\"");
        printf("\n3-> Insert at \"Position\"");
        printf("\n4-> Display list");
        printf("\n5-> Count of node");
        printf("\n6-> Delete at \"END\"");
        printf("\n7-> Devoid delete_first_node(struct node **head)lete at \"Position\"");
        printf("\n8-> Delete at \"Begining\"");
        printf("\n9-> Reverse display");

        printf("\n\nEnter choice\t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0 :// to exit the program. 
                printf("Ending the program..");
                exit(0);   
                break;
        case 1 :// tp insert the node at end.
                printf("Adding node at end..");
                add_at_end(&head);// calling by refrence.
                ++no_of_element;
                exit(0);   
                break;
        case 2 :// To insert node at begning.
                insert_at_beg(&head);
                ++no_of_element;
                break;
        case 3 :// To insert node at position.
                insert_at_pos(&head);
                ++no_of_element;
                break;
        case 4 :// to display the elements.
                display_node(head);
                break; 
        default:
            break;
        }

    }// while ends
}//Main ends