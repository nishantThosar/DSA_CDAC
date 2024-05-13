/*Q4. Count Duplicate Elements
Given an integer array, numbers, count the number of elements that occur more than once.
Example numbers = [1, 3, 3, 4, 4, 4]

There are two non-unique elements: 3 and 4.

Function Description:
Complete the function countDuplicate in the editor below.
countDuplicate has the following parameter(s):
int numbers[n]: an array of integers
Returns:
int: an integer that denotes the number of non-unique values in the numbers array
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countDuplicate(int [], int);						//funcion to find the duplicate in array by recursion.

int main(void)
{
	system("cls");
	int count = 0;//count var for keeping the count. 
	int arr[5];

	for (int k = 0; k < 5; ++k)
	{
		printf("\nEnter the %d element:",k);
		scanf("%d", &arr[k]);
	}//for ends

	//for finding the duplicate element.
	for (int i = 0; i < 5; ++i)
	{
		for (int j = i+1; j < 5; ++j)
		{
			if (arr[i] == arr[j])//if the element is repeated
			{
				count ++;
				if (count == 1)// if count is equal to 1 then the element is repeated
				{
					printf("\n\tElement %d is duplicate \n", arr[i]);
					count = 0;
				}//nested if ends
			}//if ends.
		}//nested for ends.
	}//for ends.

	printf("\n");
	int size = ((sizeof(arr)/sizeof(arr[0])));
	countDuplicate(arr,size);
	return 0;
}//main ends

void countDuplicate(int arr[], int max_index)			//function to find duplicate by recursion.
{
	int count = 0;
	if (max_index == -1)
	{
		return;
	}//if ends.

	if (arr[max_index] == arr[max_index+1])
	{
		printf("Duplicate %d\n", arr[max_index+1]);
	}
	countDuplicate(arr,max_index-1);

}//count duplicate ends
