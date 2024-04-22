/*Self made library
This library contains the function to print the array.
*/
#include<stdio.h>
#include<stdlib.h>

void display(int size, int *ptr)
{
    int *temp = NULL;
    temp = ptr;
    for(int i=0; i<size; i++){
        printf("\n\nArr[%d]: %d", i+1, temp[i]);
    }//for ends
}