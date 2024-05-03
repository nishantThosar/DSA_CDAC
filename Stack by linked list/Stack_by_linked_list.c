/*In this progra stack is implimented by linked list
Program By Nishant Thosar
Date: 03/May/2024
Place: ACTS
*/

#include<stdio.h>
#include<stdlib.h>
/*--------------------------------------------------------Struct declaration-------------------------------------------------------------------------*/
struct node
{
	struct node *prev;
	struct node *next;
	int data;
}nd;

/*--------------------------------------------------------Global Declaration-------------------------------------------------------------------------*/

/*---------------------------------------------------------Func ptorotypes---------------------------------------------------------------------------*/
struct node* node_maker(void);//to make the node.
void queue(struct node **);// to stacking in the stack
void dequeue(struct node**);// pop function.
void peep(struct node *);//to peep the upper element.
/*------------------------------------------------------------START----------------------------------------------------------------------------------*/
int main()
{
	struct node *head = NULL;
	int choice;
while(1)
	{
		printf("\n\noptions");
		printf("\n1.Stacking\n2.Unstacking\n3Exit");
		scanf("%d", &choice);

		switch(choice)
		{	
			case 1 :queue(&head);
					break;

			case 2:dequeue(&head);
					break;

			case 3:free(head);
					exit(0);

		}//switch ends
	}//while ends
}//main ends

/*-------------------------------------------------------Node maker function-------------------------------------------------------------------------*/
struct node* node_maker(void)
{
	struct node *temp = NULL;
	temp = (struct node*)calloc(1,sizeof(nd));

	//Null check
	if(!temp)
	{
		perror("\n\nError malloc");
		exit(1);
	}//if ends
	else
		return temp;
}//node maker ends

/*-----------------------------------------------------Queue function--------------------------------------------------------------------*/
void queue(struct node **head)
{
	struct node *temp = NULL;
	temp = node_maker();

	printf("\n\nEnter the data: ");
	scanf("%d", &temp->data);

	if(!*head)
	{
		*head = temp;
	}//if ends
	else
	{	
		(*head)->prev = temp;
		temp->next = *head;
		*head = temp;

	}//else ends

}//void insert at begning

/*-------------------------------------------------Dequeue function---------------------------------------------------------------------------*/
void dequeue(struct node **head)
{
	struct node *temp = NULL;
	temp = *head;
	if(temp){
		printf("-->%d", temp->data);

		*head = (*head)->next;
		temp->next = NULL;

		free(temp);
	}//if ends
	else
	{
		printf("\nNo data in stack");
		return;
	}
}// dequeue function ends


/*---------------------------------------------------Peep Function------------------------------------------------------------------------------*/
void peep(struct node *head)
{
	if(head)
	{
		printf("PEEP: %d", head->data);
	}
	else
	{
		printf("\n\nNo data in stack");
		return;
	}
}//peep ends
