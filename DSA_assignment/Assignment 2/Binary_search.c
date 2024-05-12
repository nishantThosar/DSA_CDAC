/*
Q2. Write a C/C++ program to implement Binary Search. We need to check for duplicate element
inputs, if found any should not insert into the input array. The array should manage in sorted order.
Apply a duplicacy check on the element while inserting the element, if found duplicate then discards
the input. The input element should insert in the array at the right position( index). Appropriate
shifting can be applied in the array in order to insert the input element at the right position. An
appropriate condition check needs to apply for element not found scenario.

(a) Binary Search ( iterative approach)
(b) Binary Search ( recursion approach )
*/


#include <stdio.h>

int binary_search(int[], int, int); 				// binary search function
int binary_recursion(int[], int, int, int);				//binary search by recursion
int main(void)
{
	int target;
	int arr[] = {1,12,15,17,3};

	//printing the array.
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\t",arr[i]);
	}//for ends

	
	int size = 6;// (sizeof(arr)/sizeof(arr[0]));
	printf("%d\n", size);
	
	
	printf("\nAbove is the array\nEnter the element you want to search: ");
	scanf("%d", &target);

	int index = binary_search(arr,size,target);		//binary search function calling.

	if (index == -1)								//if func returns -1 then element is not in array.	
	{
		printf("\nElement not in array");
	}//if ends
	else											//if the element is in the array print the index at which it found.
	{
		printf("Element found at index: %d\n", index+1);
	}//else ends


	printf("From recursion\n");
	//for recursion
	int index2 = binary_recursion(arr,0, 5,target);

	if (index == -1)								//if func returns -1 then element is not in array.	
	{
		printf("\nElement not in array");
	}//if ends
	else											//if the element is in the array print the index at which it found.
	{
		printf("Element found at indes: %d\n", index+1);
	}//else ends

}//main ends


//binary function defination.
int binary_search(int arr[], int size, int target)
{
	int low = 0;
	int high = size -1;
	int mid;

	while(low <= high)
	{
		mid = low+(high-low)/2;
		if(arr[mid] == target)
		{
			return mid;								//if target is mid then return mid.
		}//if ends
		else if(arr[mid] < target)					//if target is grater than mid element then search in right side of mid.
		{
			low = mid +1;
		}//else if ends
		else 										//if target is less than mid element then search in the left side of mid.
		{
			high = mid -1;
		}
	}//while ends

	return -1;										//if element is not fount in the array.
}//binary search ends


int binary_recursion(int arr[], int low, int high, int target)
{
	/*both the cases below will be the base case of recursion
	if element is not found then the low will be more than the high
	if element at mid index of arr is target element then return the index*/


	if (low>high)									//if element is not found till the last then return -1.
	{
		return -1;
	}//if ends

	int mid = low + (high-low)/2;
	
	if (arr[mid] == target)							//if match then return the index (ie: mid)
	{
		return mid;
	}//if ends.
	else if(arr[mid] < target)						//if the current at index is grater than the target then find in right side of array.
	{	
		return binary_recursion(arr, mid+1, high, target);//changing low to mid +1.
	}//else if ends
	else											//if current element at index is less than the target elemeent then find in the left array
	{
		return binary_recursion(arr, low, mid-1, target);//changing low to mid -1.
	}//else if ends

}//binary recursion ends
