

#include<stdio.h>
#include<stdlib.h>

void push(int *, int *);
int pop(int *,int *);
int peep(int *,int );
void display_stack(int *);
int is_stack_full(int);
int is_stack_empty(int);


int size;

int main()
{
	int *a;
	int choice,top=-1,ele;
	
	printf("Enter array size: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
		a[i]=-99;
	
	while(1)
	{
	printf("Enter choice :\n1) push \n2) pop \n3) peep \n4) displayStack \n5) Stack Full check \n6) Stack Empty check \n0)exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			push(a,&top);
			break;
		case 2:
			ele=pop(a,&top);
			if(ele)
				printf("Poped element %d\n",ele);
			break;
		case 3:
			ele=peep(a,top);
			if(ele)
				printf("Top element %d\n",ele);
			break;
		case 4:
			display_stack(a);
			break;
		case 5:
			is_stack_full(top);
			break;
		case 6:
			is_stack_empty(top);	
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
int is_stack_full(int top)
{
	if(top==(size-1))
	{
		printf("Stack full\n");
		return 1;
	}
	
	printf("Stack not full\n");	
	return 0;
}

int is_stack_empty(int top)
{
	if(top==-1)
	{
		printf("Stack empty\n");
		return 1;
	}
	
	printf("%d elements present in Stack\n",top);
	return 0;
}


void push(int *a, int *top)
{
	if(is_stack_full(*top))
		return;
		
	int ele;
	
	printf("Enter Element: ");
	scanf("%d",&ele);	
	*top+=1;
	a[*top]= ele;

	
}

int pop(int *a, int *top)
{
	if(is_stack_empty(*top))
		return 0;
	
	int temp=a[*top];
	a[*top]=-99;
	
	*top-=1;
	return temp;
}

int peep(int *a,int top)
{
	if(is_stack_empty(top))
		return 0;
		
	return a[top];
}

void display_stack(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
}
