/*
Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList
*/

#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
	
struct node *head;
int kount=0;

void insert_at_end(int);
void insert_at_beg(int);
void insert_at_pos(int,int);
void display();
int list_node_count();
void delete_at_end();
void delete_at_beg();
void delete_from_pos(int);
void delete_by_element(int);
void sorted_list();
void reverse_list();
void free_all_node();
void reverse_display(struct node *);





int main()
{
	int choice,x,ind,count;
	struct node *t,*t1;

	head=NULL;

	if (head==NULL)
	{
		printf("linkedlist is empty\n");
	}
	else{
		printf("linked is not empty\n");
	}
	
	while(1)
	{

	printf("1: Insert at End \n2: Insert at Beg  \n3: Insert at positon  \n4: Display \n5: Count elements\n6: Detele at End\n7: Delete from beg\n8: Delete From Position\n9: Delete by element\n10: Reverse Display\n11: Free all node\n12: Reverse list\n13: Sorted List\n0: Exit \n");
	printf("Enter choice :\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Enter element\n");
			scanf("%d",&x);
			
			insert_at_end(x);
			break;
		case 2:
			printf("Enter element\n");
			scanf("%d",&x);
			
			insert_at_beg(x);
			break;
		case 3:
			printf("Enter element\n");
			scanf("%d",&x);
			printf("Enter Index\n");
			scanf("%d",&ind);
			
			insert_at_pos(x,ind);
			break;
		case 4:
			display();
			break;
		case 5:
			count=list_node_count();
			if(count==-1)
				printf("Linkedlist is empty\n");
			else
				printf("count is %d: \n",count);
			break;
		case 6:
			delete_at_end();
			break;
		case 7:
			delete_at_beg();
			break;
		case 8:
			printf("Enter Index\n");
			scanf("%d",&ind);
			delete_from_pos(ind);
			break;
		case 9:
			printf("Enter element\n");
			scanf("%d",&x);
			delete_by_element(x);
			break;
		case 10:
			t1=head;
			reverse_display(t1);
			printf("\n==================================================================\n");
			printf("\n");
			break;
		case 11: 
			free_all_node();
			break;
		case 12:
			reverse_list();
			break;
		case 13:
			sorted_list();
			break;
		case 0:
			while(head!=NULL)
			{	
				t=head->next;
				free(head);
				head=t;
			}
			head=NULL;
			exit(0);
		default:
			printf("Invalid Choice\n");
			break;
	}

	}

}

//a) insertAtEnd

void insert_at_end(int x)
{
	struct node *temp,*t1=head;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp;
	}
}

//b) insertAtBeg 

void insert_at_beg(int x)
{
	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

//c) insertAtPos 

void insert_at_pos(int x,int ind)
{

	if(head==NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	
	int count=list_node_count();
	
	if((ind<1)||(ind>(count+1)))
	{
		printf("Index Invalid\n");
		return;
	}
	
	if(ind==1)
	{
		insert_at_beg(x);
		return;
	}
	else if(ind==(count+1))
	{
		insert_at_end(x);
		return;
	}
	
	int i=1;
	
	struct node *temp,*t1=head;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	
	while(i<(ind-1))
	{
		t1=t1->next;
		i++;
	}
	
	temp->next=t1->next;	
	t1->next=temp;

	
	
}

//d) displayList
                                          
void display()
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		struct node *t1=head;
		
		while(t1!=NULL)
		{
			printf("%d->",t1->data);
			t1=t1->next;
		}
	}
	printf("\n==================================================================\n");
}

//e) listNodeCount 

int list_node_count()
{
	if(head==NULL)
		return -1;
		
		
	int count=0;
	struct node *t1=head;
	while(t1!=NULL)
	{
		count++;
		t1=t1->next;
	}
	return count;
	

}

//f) deleteFromEnd

void delete_at_end()
{
	if(head==NULL)
	{
		printf("Linkedlist empty\n");
		return;
	}
	
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		struct node *t1=head,*t2;
		while(t1->next!=NULL)
		{
			t2=t1;
			t1=t1->next;
		}
		free(t1);
	
		t2->next=NULL;
	}
	
}

//g) deleteFromBeg

void delete_at_beg()
{
	if(head==NULL)
	{
		printf("Linkedlist empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{		
		struct node *t=head->next;
		free(head);
		head=t;
	}
}

//h)deleteFromPos 

void delete_from_pos(int ind)
{
	int i=1;
	int count=list_node_count();
	
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	
	
	if((ind<1)&&(ind>(count)))
	{
		printf("Index Invalid\n");
		return;
	}
	else if(ind==1)
	{	
		delete_at_beg();
	}
	else if(ind==count)
	{
		delete_at_end();
	}
	else
	{
		struct node *t1=head,*t2;
		
		while((i<ind)&&(t1->next!=NULL))
		{
			t2=t1;
			t1=t1->next;
			i++;
		}
	
		t2->next=t1->next;
		free(t1);
	}
}

//i) deleteByElement

void delete_by_element(int x)
{
	if(head==NULL)
	{
		printf("Linkedlist empty\n");
	}
	else
	{
		struct node *t1=head,*t2;
		
		while((t1->data!=x)&&(t1!=NULL))
		{
			t2=t1;
			t1=t1->next;
		}
		
		t2->next=t1->next;
		free(t1);
	}
}

//j) reverseDisplay

void reverse_display(struct node *t1)
{
	if(t1==NULL)
	{
		return;
	}
	reverse_display(t1->next);
	printf("%d-->",t1->data);
}

//k)freeAllNode

void free_all_node()
{
	struct node *t;
	
	if(head==NULL)
	{
		printf("Linkedlist empty\n");
	}
	else
	{
		while(head!=NULL)
		{
			t=head->next;
			free(head);
			head=t;
			
		}
		head=NULL;
	}

}


//l) reverseList

void reverse_list()
{
	if(head==NULL)
	{
		printf("Linkedlist empty\n");
	}
	else
	{
		struct node *t1,*t2,*t3;
		t1=head;
		t2=t1->next;
		t3=NULL;
		
		while(t2!=NULL)
		{
			t2=t1->next;
			t1->next=t3;
			t3=t1;
			t1=t2;
		}
		head=t3;
	}
}

//m)sortedList

void sorted_list()
{
	struct node *r=NULL;
	struct node *t=NULL;
	int flag,temp;
	do
	{
		t=head;
		flag=1;
		while(t->next!=r)
		{
			if(t->data>t->next->data)
			{
				temp=t->data;
				t->data=t->next->data;
				t->next->data=temp;
				
				flag=0;
			}
			t=t->next;
			
		}
		r=t;
	}while(flag==0);
	
}


/*
struct node *t1,*t2;
	int temp;
	int i=1,j;
		
	t1=head;
	
	for(;i<kount;i++)
	{
		t2=t1->next;
		for(j=i+1;j<=kount;j++)
		{
			if((t1->data)>(t2->data))
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
*/
/*

	t1=head;
	t2=t1->next;
	int i=1,flag=1;
	while(t2!=NULL)
	{	
		for(i;i<kount;i++)
		{
			if((t1->data)<(t2->data))
			{
				flag++;
			}
			t1=t2;
			t2=t1->next;
		}
		
		t1=head;
		t2=t1->next;
		
		if(flag==kount)
		{
			break;
		}		
		while(t2!=NULL)
		{
			if((t1->data)>(t2->data))
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			t1=t2;
			t2=t1->next;
		}
		
		t1=head;
		t2=t1->next;
		
	}	
*/


