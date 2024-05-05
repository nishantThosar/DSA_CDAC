/*
Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members of each element
*/

#include<stdio.h>
#include<stdlib.h>



int main()
{
	int *arr1[3];
	int (*arr2)[3];
	
	
	arr2=(int (*) [])malloc(sizeof(int)*9);
	printf("Array 2\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&arr2[i][j]);
		}
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("[%d][%d]:%d  ",i,j,arr2[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=0;i<3;i++)
		arr1[i]=(int *)malloc(sizeof(int)*3);
	
	printf("Array 1\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("[%d][%d]: ",i,j);
			scanf("%d",&arr1[i][j]);
		}
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("[%d][%d]:%d  ",i,j,arr1[i][j]);
			
		}
		printf("\n");
	}
	printf("\n");
}
