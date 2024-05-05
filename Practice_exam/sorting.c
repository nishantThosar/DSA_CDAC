/*
Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Bubble Sort
(b) Selection Sort
(c) Insertion Sort
*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void bubble_sort(int *);
void selection_sort(int *);
void insertion_sort(int *);
void swap(void *,void *,int );
void display(int *);

int size;

int main()
{
	int *a,choice;
	printf("Enter Size of array: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
	{
		printf("Enter Element [%d]: ",i+1);
		scanf("%d",&a[i]);
	}
	while(1)
	{
	printf("Enter choice :\n[1] Bubble sort\n[2] Selection sort\n[3]Insertion Sort\n[4]display\n[0]exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			bubble_sort(a);
			break;
		case 2:
			selection_sort(a);
			break;
		case 3:
			insertion_sort(a);
			break;
		case 4:
			display(a);
			break;
		case 5:
			for(int i=0;i<size;i++)
			{
				printf("Enter Element [%d]: ",i+1);
				scanf("%d",&a[i]);
			}
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

void swap(void *a,void *b,int s)
{
	void *temp;
	temp=(void *)malloc(s);
	
	memcpy(temp,a,s);
	memcpy(a,b,s);
	memcpy(b,temp,s);
}

void display(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}

void bubble_sort(int *a)
{
	int flag=1,n=size;
	do
	{	
		flag=1;
		for(int i=0;(i+1)<n;i++)
		{
			if(a[i]>a[i+1])
			{
				swap(&a[i],&a[i+1],sizeof(a[i]));
				flag=0;
			}
			n--;
		}
	}while(flag==0);
}

void selection_sort(int *a)
{
	for(int i=0;i<(size-1);i++)
	{
		for(int j=(i+1);j<size;j++)
		{
			if(a[j]<a[i])
			{
				swap(&a[i],&a[j],sizeof(a[i]));
			}
		}
	}
}
void insertion_sort(int *a)
{
	int temp;
	for(int i=1;i<size;i++)
	{
		temp=a[i];
		int j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
			a[j+1]=temp;
	}
}
