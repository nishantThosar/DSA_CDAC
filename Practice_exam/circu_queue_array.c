
#include<stdio.h>
#include<stdlib.h>

void enqueue(int *,int *, int *);
int dequeue(int *,int *,int *);
int peep(int *,int);
void display_queue(int *);
int queue_full(int ,int );
int queue_empty(int);

int size;

int main()
{
	int *a,choice,ele;
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
			ele=dequeue(a,&f,&r);
			if(ele)
				printf("Dequeued element %d\n",ele);
			break;
		case 3:
			ele=peep(a,f);
			if(ele)
				printf("Dequeued element %d\n",ele);
			break;
		case 4:
			display_queue(a);
			break;
		case 5:
			queue_full(r,f);
			break;
		case 6:
			queue_empty(f);
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
int queue_full(int r,int f)
{
	if((r==size-1 && f==0)||(r==f-1))
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
		printf("Queue empty\n");
		return 1;
	}
	return 0;
}

void enqueue(int *a,int *f,int *r)
{
	if(queue_full(*r,*f))
		return;
	int ele;
	printf("Enter Element: ");
	scanf("%d",&ele);
	
	if((*r==size-1 && *f!=0))
		*r=0;
	else
		*r+=1;
	
	a[*r]=ele;
	
	if(*f==-1)
		*f=0;

}

int dequeue(int *a,int *f,int *r)
{
	if(queue_empty(*f))
		return 0;
	
	int temp=a[*f];
	a[*f]=-99;
	
	if(*f==*r)
		*f=*r=-1;
	else
	{	if(*f==size-1)
			*f=0;
		else
			*f+=1;
	}
	
	return temp;
	
}

int peep(int *a,int f)
{
	if(queue_empty(f))
		return 0;
		
	return a[f];
}
void display_queue(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
}
