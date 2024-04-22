/*This is a self made library 
This library contains function for 
1. making array.
2. inserting the element at position.
3. deletion of element at position.
*/
#include<stdio.h>
#include<stdlib.h>
#include"display.h"//including the display library.
//Fuction for making the array
int* node_maker(int pos)
{
    int *temp = NULL;// local ptr
    temp = (int*)calloc(pos, sizeof(int));// calloc done
    // if calloc failed terminate the program.
    if ( temp == NULL)
    {
        perror("Malloc filed");
    }
    printf("\nArray of %d has made now you can insert elements\n", pos);
    return temp;// if calloc succedded then return the address of array.
}

void insert_atPos(int size, int *ptr)
{
    int pos, ele;//local var
    printf("\n\nEnter the value of element: ");
    scanf("%d", &ele);//user input of val of element
    printf("Enter the position: ");
    scanf("%d", &pos);// user input of position.
    
    //To check if there is already elemet at place
    if( ptr[pos] != 0){
		perror("Already element is prerent at element");
    }// if ends
    
    //to check if the position lies within the scope of array.
    if(size>=pos){
        ptr[pos-1] = ele;
	printf("in size>pos");// debugger
        display(size,ptr);
    }//if ends
    //if the position does not lies in array realloc the array by increasing the size.
    else{
    	printf("in size>pos");// debugger
        int *temp = NULL;
        temp = (int*)realloc(ptr, size);
	//realloc null check
	if (temp == NULL){
		perror("\nError in realloc");
	}
        //to insert zero explictly in the reallocked spaces.
        for(int i=pos; i>(pos-size); i--){
            temp[i] = 0;
    	}// for ends

        ptr = temp;//assign the new address to the ptr pointer.
        temp[pos-1] = ele;// assigning the value of element at the position -1 place.
        display(size,ptr);// calling display method.

    }//else if ends
}// insert at position ends.

//function to delete the element at position.
void delete_at_pos(int *size, int *ptr)
{
    if(size !=0){// to check if the size is zero, if zero the program will throw a error.
        int pos;// local var
        printf("\nEnter the position of element you want to delete: ");
        scanf("%d", &pos);//user input of position of element which he wants to delete.
        int *temp = NULL;// local ptr
        temp = ptr;//assigning the local ptr to the address of array.
        
	//To check that the value is in the scope of array.
        if(pos<=*size){
            for(int i=pos-1; i<*size; ++i){
                temp[i] = temp[i+1];// for shifting the elements one prior if we delete the element in between.
            }//for ends
	    --*size;
            temp = (int*)realloc(temp, sizeof(int)*(*size));// reallocating the array with size-1.
	    
	    // Null check of realloc
	    if(temp == NULL){
	    	perror("\nEttor in realloc");		
	    }

            ptr = temp;// assigning the new address of array to ptr pointer.
	    printf("\nAfter deletion of array\n");
            display(*size,ptr);// calling display method.
        }//if ends
        
	else{//if position is out of scope of array then program will throw an error.
            perror("\n\nThe position is out of scope of current array.\n");
        }//else ends
    }// outer if ends
    
    else{
        perror("\n\nArray does not exists therefore cannot delete element\n");
    }//outer else ends

}//delete at position ends.
