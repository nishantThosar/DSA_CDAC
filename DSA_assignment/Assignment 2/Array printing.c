/*Array printing
Q1. Write a C/C++ program to implement Linear Search. We need to check for duplicate inputs. If the
duplicate element is allowed then a linear search algo needs to implement accordingly. An
appropriate condition check needs to apply for element not found scenario.

(d) Print Input array ( recursion approach )
(e) Print Input array reverse order ( iterative approach )
(f) Print Input array reverse order ( recursion approach )
*/

#include<stdio.h>

void print_reverse(int [], int);						//function to print the array reverse.
void print_(int [], int);								//function to print the array by recursion.
int linear_search(int[], int);							//for searching the element in the array by linear search.
void iter_print(int []);								//for printing the array iteratively.


int main(void)
{
	int temp ,flag =0;;

	int arr[5] = {0,0,0,0,0};

	//for taking input in the array
	for (int i = 0; i < 5; ++i)		
		{
			do{
				printf("Enter the %d element: \t",i);
				if((scanf("%d", &temp)) &&(linear_search(arr, temp)))
				{
					printf("\nElement present in array");
					flag = 1;
				}//if ends
				else
				{
					arr[i] = temp;
					flag = 0;
				}
			}while(flag == 1);
		}//for ends.

	printf("\n");
	printf("Iterative print:\t");									//Calling the iterative function
	iter_print(arr);
	printf("\nReverse:      	\t");							
	print_reverse(arr,0);											//calling the reverse printing function.
	printf("\nFront:        	\t");
	print_(arr,4);													//calling the print_ fuction.
	printf("\n");
}//main ends

//for pinting the array iteratively
void iter_print(int arr[])
{
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\t",arr[i]);
	}//for ends

}//iter print ends

//for reverse printing of array bu recursion.
void print_reverse(int arr[], int index)
{

	if (index == 5)
	{
		return;
	}//if ends
	else
	{
		print_reverse(arr,index+1);
		printf("%d\t",arr[index]);
	}//else ends


}//print reverse ends


//for printing the array.
void print_(int arr[], int index)
{

	if (index == -1)
	{
		return;
	}
	else
	{
		print_(arr,index-1);
		printf("%d\t",arr[index]);
	}


}//print_ ends

//to search if the element is in the array or not.
int linear_search(int arr[], int target)
{

	for (int i = 0; i < 5; ++i)
	{
		if (arr[i] == target)
		{
			return 1;
		}//if ends
		else
		{
			return 0;
		}// else ends
	}//for ends

}//linear search ends