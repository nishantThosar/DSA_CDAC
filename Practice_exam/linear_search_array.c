#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void linear_search(int *);
int rec_linear_search(int *,int,int);
void display(int *);
void rec_display(int *,int);
void reverse_display(int *);
void rec_reverse_display(int *a,int i);

int size;

int main()
{
	int *a,choice,i=0,ele;
	int f=0;
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
	printf("Enter choice :\n[1] Linear Seach\n[2] Recurssive Linear search\n[3]Display\n[4]recurssive display\n[5]reverse display\n[6]recurssive reverse display\n[0]exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			linear_search(a);
			break;
		case 2:
			printf("Enter element: ");
			scanf("%d",&ele);
			f=rec_linear_search(a,ele,i);
			if(f==-1)
			{
				printf("Element not found\n");
			}
			else
				printf("Element found at pos %d\n",f+1);
			i=0;
			break;
		case 3:
			display(a);
			break;
		case 4:
			rec_display(a,i);
			i=0;
			break;
		case 5:
			reverse_display(a);
			break;
		case 6:
			rec_reverse_display(a,i);
			i=0;
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

void display(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}

void rec_display(int *a,int i)
{
	
	if(i==size)
	return ;
	
	printf("Element [%d]: %d\n",i+1,a[i]);
	rec_display(a,++i);
	
}

void linear_search(int *a)
{
	int ele;
	printf("Enter element: ");
	scanf("%d",&ele);
	int i=0;
	for(;i<size;i++)
	{
		if(a[i]==ele)
			printf("%d fount at pos: %d\n",ele,i+1);
	}
	i=0;
	while(i<size && a[i]!=ele)
	{
		i++;
	}
	printf("%d fount at pos: %d\n",ele,i+1);	
}
int rec_linear_search(int *a,int ele,int i)
{
	if(i==size)
		return -1;
	if(a[i]==ele)
		return i;
	else
		rec_linear_search(a,ele,i+1);
}

void reverse_display(int *a)
{
	for(int i=size-1;i>=0;i--)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}

void rec_reverse_display(int *a,int i)
{
	if(i==size)
		return;
	rec_reverse_display(a,i+1);
	printf("a[%d]:%d\n",i+1,a[i]);
}
