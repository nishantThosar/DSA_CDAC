/*
Q4. Count Duplicate Elements
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


#include<stdio.h>
#include<stdlib.h>

//function declarations


void all_input(int *,int );
int duplicate_ele(int *,int ) ;



int main()
{
	int size;
	
	printf("Enter size of array: ");
	scanf("%d",&size);
	
	int *arr;
	
	arr=NULL;

	arr=(int *)calloc(size,sizeof(int));		//dynamic memory allocation
	
	if(arr==NULL)					//check if dynamic memory allocated or not
	{
		printf("array is empty\n");
		exit(0);
	}
	
	all_input(arr,size);				//function call
	
	printf("\n");
	
	int count=duplicate_ele(arr,size);
	printf("%d non-unique elements are present in array\n",count);
	
	return 0;
	
}
	







void all_input(int *arr,int n)
{
	printf("Input.................................................\n");
	printf("Enter elements of array: \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter element %d :",i+1);
		scanf("%d",&arr[i]);
	}
	
}





int duplicate_ele(int *arr,int n)
{	
	int dupli_arr[n];
	int count=0,flag,temp,c;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{	
				//temp=arr[j];
				flag=1;
				for(int k=0;k<count;k++)
				{
					if(arr[j]==dupli_arr[k])
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					dupli_arr[count]=arr[j];
					count++;
				}
			}
		}
	}
	
	for(int i=0;i<count;i++)
	{
		c=0;
		for(int j=0;j<n;j++)
		{
			if(dupli_arr[i]==arr[j])
			{
				c++;
			}
		}
		printf("%d is present %d times\n",dupli_arr[i],c);
	}
	
	return count;
	
}

/*
int t_arr[n];
	
	int temp,flag,count=0,kount=0,c=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)		//[1, 3, 3, 4, 4, 4]
		{
			if(arr[i]==arr[j])
			{
				temp=arr[j];
				flag=1;
				for(int k=0;k<count;k++)
				{
					if(t_arr[k]==temp)
						flag=0;
				}
				if(flag==1)
				{
					t_arr[count]=temp;
					count++;
				}
			}
		}
	}
	
	int c_arr[count];
	for(int k=0;k<count;k++)
	{
		c=0;
		for(int i=0;i<n;i++)
		{
			if(t_arr[k]==arr[i])
			{
				c_arr[kount]=++c;
			}
		}
		if(c!=0)
			kount++;
	}
	
	
	for(int k=0;k<count;k++)
	{
		printf("Element %d is present in array %d time\n",t_arr[k],c_arr[k]);
	}
*/

