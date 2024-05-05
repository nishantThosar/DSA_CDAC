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

#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void binary_search(int *);
int rec_binary_search(int *,int,int,int);
void display(int *);
void input(int *);

int size;

int main()
{
	int *a,choice,i=0,ele;
	int f=0;
	printf("Enter Size of array: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	int mid;
	while(1)
	{
	printf("Enter choice :\n[1] Binary Seach\n[2] Recurssive binary search\n[3]Display\n[4]Input\n[0]exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			binary_search(a);
			break;
		case 2:
			printf("Enter element: ");
			scanf("%d",&ele);
			mid=rec_binary_search(a,0,(size-1),ele);
			if(mid==-1)
				printf("Element not found\n");
			printf("%d is at index %d\n",ele,mid+1);
			
			break;  
		case 3:
			display(a);
			break;
		case 4:
			input(a);
			break;
		case 0:
			free(a);
			exit(0);
		default:
			printf("Invalid Choice");
			break;
	}
	
	}
	
}

void input(int *a)
{
	int ele,flag=0,j,k,z;
	for(int i=0;i<size;)
	{
		printf("Enter Element : ");
		scanf("%d",&ele);
		
		for(j=0;j<i;j++)
		{
			if(a[j]==ele)
			{
				printf("Element already exist\n");
				flag=1;
				break;	
			}
			
		}
		if(flag==0)
		{
			
			j=i-1;
			while((j>=0)&&a[j]>ele)
			{
				a[j+1]=a[j];
				j--;
			}
				
			a[j+1]=ele;
			i++;	
		}
		flag=0;
		
	}
}

void display(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}

void binary_search(int *a)
{
	int start=0,end=size-1,mid,ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	
	while(start<=end)
	{
		//printf("high\n");
		mid=(start+end)/2;
		//printf("mid:%d,start%d,end:%d\n",mid,start,end);
		if(ele==a[mid])
		{
			//printf("mid:%d,start%d,end:%d\n",mid,start,end);
			printf("%d found at pos: %d\n",ele,mid+1);
			return;
		}
		
		else if(ele<a[mid])
			end=mid-1;
			
		else if(ele>a[mid])
			start=mid+1;
	}
	if(start>end)
		printf("Element not found\n");
}

int rec_binary_search(int *a,int start,int end,int ele)
{
	
	if(start>end)
		return -1;
	int mid=(start+end)/2;
	
	if(ele==a[mid])
		return mid;
	else if(ele>a[mid])
		return rec_binary_search(a,mid+1,end,ele);
	else if(ele<a[mid])
		return rec_binary_search(a,start,mid-1,ele);
}
