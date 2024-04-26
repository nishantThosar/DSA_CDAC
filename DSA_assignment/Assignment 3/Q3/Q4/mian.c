/*Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode*/

/*This program is for doubly linked list*/

#include<stdio.h>
#include<stdlib.h>
#include"insert.h"// Library for insertion of node.
#include"display.h"// library for displaying the nodes.
//#include"delete.h"// library for all deletion operations in list.
#include"insert_sort.h"//To sort the user input.

int main()
{
    struct student *head = NULL;
    ip_sort(&head);
/*
    first_node(&head);// for testing purpose
    display_list(head);// for testing.
    insert_at_end(&head);// for testing.
    display_list(head);// for testing.
*/
    free(head);
}// Main ends
