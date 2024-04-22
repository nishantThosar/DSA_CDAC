/* 
   library to perform arithematic operations on array.
 * This library contains finding the min, max and average of elements.
*/

#include<stdio.h>

//Function to calculate and print the average of array.
void average( int *ptr, int size)
{
	int total = 0;// local var for storing sum of elements of array.
	float avg;//local var for storing average of the elements of array.

	//for loop to iterate and add all the elements of array
	for(int i=0; i<size; i++){
		total = total + ptr[i];
	}// for loop ends.

	avg = total/size; //to get the average of whole elements of array.
       printf("\nAverage of elements: %d", avg);
       
}//average function ends.

// Function to find the minimum value element of array
void min (int *ptr, int size)
{
	int min = ptr[0]; // assigning the first value of array to min local variable.

	// Traversing the array & checking for minimum. 
	for(int i = 1; i<size; i++){
		if(ptr[i]<min){
			min = ptr[i];// if smaller value is found than ptr[0] then assign the value to minimum.
		}// if ends
		}// for ends

	printf("\n\nMimimum vlaue inside array is: %d", min);//printing the mimimum value.

}// min ends

//Function to find the maximum vlaue inside array.
void max (int *ptr, int size)
{
	int max = ptr[0]; // assigning the first value of array to min local variable.
	
	// Traversing the array & checking for minimum. 
	for(int i = 1; i<size; i++){
		if(ptr[i]>max){
			max = ptr[i];// if smaller value is found than ptr[0] then assign the value to minimum.
		}// if ends
	}// for ends
	
	printf("\n\nMimimum vlaue inside array is: %d", max);//printing the mimimum value.

}// max ends

