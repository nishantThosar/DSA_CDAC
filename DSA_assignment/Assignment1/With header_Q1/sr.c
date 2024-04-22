/*This file contains defination for 
1. Searching the elements.
2. Reversing the elements
3. Displaying the elements reverse.
4. Duplicate element.
*/

#include<stdio.h>
#include"display.h"

//Function to search the element inside array.
void search(int *ptr, int size)
{
    int ele_to_search;
    printf("\nEnter the element to search: ");
    scanf("%d", &ele_to_search);// user input to find the value of element
    
    // Traversing through array
    for(int i=0; i<size;i++){

        //Finding the element by linear search
        if( ptr[i] == ele_to_search){
                printf("Entered value foud at %d place of array", i+1);
        }// if ends

    }// for ends

}//search ends

// Function to print the array element reverse.
void reverse_print(int *ptr, int size)
{
    for(int i = size; i > 0 ; i--){
        printf("\n\n Array element[%d]: %d",i+1,ptr[i]);
    }// for ends
}// reverse print ends

//Function to reverse the array element.
void reverse_arr(int *ptr, int size)
{
    //For loop to traverse the array.
    for (int i = 0, j = (size-1); i < (size/2) || j>(size/2) ; i++, j--){
            int temp = ptr[i];
            ptr[i] = ptr[j];
            ptr[j] = temp;       
    }// for ends
    display(size,ptr);
    
}// Reverse array ends

//Function to find the duplicate element.
void duplicate(int *ptr, int size)
{
    int ele, count=0;
    printf("Enter the element to find the duplicate in ");
    for(int i=0; i<size;i++){
        if(ptr[i] == ele){
            printf("\n\nElement %d was found at %d position in array", ele, i+1);
            ++count;  
        }// if ends
    }// for ends
    printf(".The element was found %d times", count);
}//Duplicate ends