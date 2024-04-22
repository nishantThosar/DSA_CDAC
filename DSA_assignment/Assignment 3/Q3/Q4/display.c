/*Function definations to define the display function */
#include<stdio.h>
#include"insert.h"
#include<stdlib.h>

void display_list(struct student *head)
{
    struct student *trav = head;//Temp struct ptr to traverse.
    //Traversing till the trav pointer is not null.
    while (trav != NULL)
    {
        printf("Name of student is %s\n", trav->name);
        printf("PRN of student is %d\n\n", trav->prn);
        trav = trav->next;
        
    }//While ends
    
}//Display list ends.