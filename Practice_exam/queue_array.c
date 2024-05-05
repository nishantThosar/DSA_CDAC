
#include<stdio.h>
#include<stdlib.h>

void enqueue(int *,int *, int *);
void dequeue(int *,int *,int *);
void peep(int *,int);
void display_queue(int *);
int queue_full(int );
int queue_empty(int);

int size;

int main()
{
	int *a,choice,i;
	int f=-1;
	int r=-1;
	printf("Enter Size of array: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
	{
		a[i]=-99;
	}
	
	while(1)
	{
	printf("Enter choice :\n1) add \n2) delete \n3) peep \n4) display queue \n5) Queue Full check \n6) Queue Empty check \n0)exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			enqueue(a,&f,&r);
			break;
		case 2:
			dequeue(a,&f,&r);
			break;
		case 3:
			peep(a,f);
			break;
		case 4:
			display_queue(a);
			break;
		case 5:
			i=queue_full(r);
			break;
		case 6:
			i=queue_empty(f);
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
int queue_full(int r)
{
	if(r==(size-1))
	{
		printf("Queue Full\n");
		return 1;
	}
	
	return 0;
}

int queue_empty(int f)
{
	if(f==-1)
	{
		printf("Queue Empty\n");
		return 1;
	}
	
	return 0;
}

void enqueue(int *a,int *f,int *r)
{
	if(queue_full(*r))
		return;
	
	int temp;
	printf("Enter element: ");
	scanf("%d",&temp);
	
	(*r)++;
	a[*r]=temp;
	if((*f)==-1)
		*f=0;

}

void dequeue(int *a,int *f,int *r)
{
	if(queue_empty(*f))
		return;
		
	int temp= a[*f];
	a[*f]=-99;
	
	if(*f==*r)
	{
		*f=-1;
		*r=-1;
	}
	else
	{
		(*f)++;
	
	}
	
}

void peep(int *a,int f)
{
	if(queue_empty(f))
		return;
		
	printf("current element %d\n",a[f]);
}
void display_queue(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
}
