/*Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode*/

#include<stdio.h>
#include<stdlib.h>
#include"insert.h"
#include"display.h"
int main()
{
    struct student *head = NULL;
    first_node(&head);// for testing purpose
    display_list(head);// for testing.
    insert_at_end(&head);// for testing.
    display_list(head);// for testing.

    free(head);
}// Main ends