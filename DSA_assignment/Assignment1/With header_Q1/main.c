/*This is the main file of the program.
 * Before execution please ensure all the header files and defination of files must be in same folder in which main is located.
 * Q1. Write a C/C++ program that declares an array of length N
	containing integers between 1 and N. Implement menu driven
	program using switch case for below mentioned functionalities.
	(a) insert element at index
	(b) delete element at index
	(c) find min val
	(d) find max val
	(e) display array element ()
	(f) reverse display array element ()
	(g) search element in array  ()
	(h) array element count ()
	(i) avg of all array element
	(j) determine if array contains any duplicates. ()
	(k) reverse array element ()
*/

#include<stdio.h>
#include<stdlib.h>
#include"mem_alloc.h"//user defined library for creating, insertion and deletion operations of array.
#include"arr_arthematic.h"//user defined library for arithematic operations of array like min, max, average.
#include "display.h"// user defined library  for displaying the array.
#include"sr.h"// user defined library contains search, duplicate and reverse functions for array.



int main()
{
    int size , *ptr, pos;
    int no_of_ele = 0;
    int choice;
    printf("\nThere is no array currently in system\nPlease input 1 as choice to create an array\n");
    while(1){
	    printf("\n\n======================= MENU =======================================\n");
	    printf("\n\n1. For making the array");
	    printf("\n\n2. For inserting element at array");
	    printf("\n\n3. For deletion at position");
	    printf("\n\n4. To print the average of current elements present in array");
		printf("\n\n5. To find the mimimum value of element in array");
		printf("\n\n6. To find the maximum value of element in array");
		printf("\n\n7. To find the element inside array");
		printf("\n\n8. To print the array in reverse order");
		printf("\n\n9. To reverse the array");
		printf("\n\n10.To display the array");
		printf("\n\n0. To exit\n");

	    printf("\n\n Enter a neumerical choice: ");
	    scanf("%d", &choice);

		//Switch case for choosing the program
	    switch(choice){

		    case 0: // Case for exiting when user input is 0.
			    	printf("\n\nExiting .. ");
			    	exit(0);

		    case 1: //Case for inserting the size of array.
			    	printf("\n\nEnter the size of array: ");
    			    scanf("%d", &size);// User input to get the size ofarray.
			    	ptr = node_maker(size);
			    	break;

		    case 2://Case to insert the element at position in array.
			   		insert_atPos(size, ptr);
					++no_of_ele;
			   		break;
			
		    case 3:// Case to delete the element at position in array 
			   		delete_at_pos(&size,ptr);
					--no_of_ele;
			   		break;

		    case 4:// Case for printing the average of all elements inside arraya
			   		average (ptr, size);
					break;
			
			case 5: //To print min value inside array.
					min(ptr, size);
					break;
			
			case 6: //To print max value in array.
					max(ptr, size);
					break;
			case 7: // To search the elements inside array.
					search(ptr, size);
					break;
			
			case 8: //To print the array reverse.
					reverse_print(ptr,size);
					break;
			case 9: //To find the duplicate element in array
					reverse_arr(ptr,size);
					printf("\nNow the array has been reversed");
					break;
			case 10: //To display the elements of array.
					display(size, ptr);
					break;


	    }//switch ends
    }//switch ends
}

