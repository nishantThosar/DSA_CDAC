/*THis file contains the insertion operations on the linked list*/
#include "linked _list_insertion.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/*This function inserts node in the sorted manner in the linked list*/
void insert_at_pos(stu **head)
{
    stu *temp = NULL;// temp pointer to student structure.
    temp = node_maker();//making a new node.
    char buff[100];// buffer for name
    /*User input for data*/
    printf("\n\n-----------------------Enter the Details of student-----------------------");
    printf("\nEnter name: ");
    scanf(" %[^\n]s", buff);
    printf("\nEnter PRN: ");
    scanf();

}//insert at position ends

stu* node_maker(void)
{
    stu *temp = NULL;
    temp = (stu*) calloc(1, sizeof(stu));// making the new node in the heap.
    if(temp){
        return temp;
    }//if ends
    else{
        perror{"\n\t\rMemory allocation failed for new node\n\nPROGRAM TERMINATON"};
        exit(0);
    }

}//node maker ends

/*Function for checking the name input given by user
1. The name mult be of max 100 char
2. The name must not include any numeric value.*/
void user_ip(stu *)
{
    bool char_100 = false;//to limit only 100 characters user input.
    bool name_char = false;// to check if the user has input only characters in name
     char buff[101];// buffer for name
    /*User input for data*/
    printf("\n\n-----------------------Enter the Details of student-----------------------");
    do{
        printf("\nEnter name(till 100 characters): ");
        // scanf(" %[^\n]s", buff);
        // for(int i=0; buff[i] != '\0'; i++){
        //     if(isalpha(buff[i]))(
        //         name_ok = false;
        //     )//if ends
        //     else
        //     {
        //         name_ok = true;
        //         printf("\n\nWrong INPUT \nDO NOT ENTER SPECIAL CHARACTERS OR NUMBER IN NAME\nONLY CHARACTERS ARE ALLOWED");
        //     }
            
        // }//for ends
    /*To check if the user has input  100 char */
    do{
        if (fgets(buff, 100, stdin) != NULL) {
            // Check if the newline character was included in the input
                if (buff[strcspn(buff, "\n")] == '\0') {
                    // Remove the newline character if present (optional)
                    buff[strcspn(buff, "\n")] = '\0';
                }
                printf("You entered: %s\n", buff);
        }//if ends.
        else {
            printf("\nENTER ONLY 100 CHARACTERS\n");
            char_100 = true;
        }//else ends
        
    }while(char_100 = true);


    }while(name_char = true)
    
    printf("\nEnter PRN: ");
    scanf();

}//user input

/*
bool char_100 = false;//to limit only 100 characters user input.
do{

    if (fgets(buff, 100, stdin) != NULL) {
        // Check if the newline character was included in the input
            if (input[strcspn(input, "\n")] == '\0') {
                // Remove the newline character if present (optional)
                input[strcspn(input, "\n")] = '\0';
            }
            printf("You entered: %s\n", input);
    } 
            else {
                printf("Error reading input.\n");
                char_100 = true;
            }
}while(char_100 = true);
*/