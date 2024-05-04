/*Queue by singly ll*/

#include<stdio.h>
#include<stdlib.h>

/*---------------------------------------------------------------------------Node defined-------------------------------------------------------------------------------*/

typedef struct node
{
	struct node *next;
	int data;

}nd;

/*-----------------------------------------------------------------------Function Prototypes----------------------------------------------------------------------------*/
nd* node_maker(void);
void insert_end(nd **);
void menu(void);
int switch_case(nd **);
void display(nd *);
void del_at_beg(nd **);
/*-------------------------------------------------------------------------Main Starts----------------------------------------------------------------------------------*/
int main()
{
	nd *head = NULL;


	while(1)
	{
		menu();
		int choice;
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: insert_end(&head);
					printf("Queue:");
					display(head);
					break;

			case 2: del_at_beg(&head);
					printf("Queue:");
					display(head);
					break;

			case 3: display(head);
					//return 1;
					break;

			case 4: printf("\n\tExiting.....\n");
					free(head);
					return 0;
			// if(!(switch_case(&head)))
			// {
			// 	return 0;
			// }
		}//switch ends
	}//while ends

}//main ends



void insert_end(nd **head)
{
	nd *temp = NULL;

	temp = node_maker();

	printf("Enter the data: ");
	scanf("%d", &temp->data);

	if(*head == NULL)
	{
		printf("\n********Hi");//debugger
		*head = temp;
		
	}//if ends
	else
	{
		nd *trav = NULL;
		trav = *head;
		printf("\n********Here");//debugger
		//first traverse then insert the node at the end.
		while(trav->next)
		{
			trav = trav->next;

		}//while ends

		trav->next = temp;// insert new node at the last node of link list.

	}//else ends
}//insert at beginging ends


void del_at_beg(nd **head)
{

	if(!(*head))
	{
		perror("\n\nERROR QUEUE EMPTY");
		return;
	}
	else
	{
		nd *trav = NULL;
		trav = *head;;

		printf("%d", trav->data);

		*head = trav->next;// traversing the head to next node.
		free(trav);

	}//else ends
}//del at ends


/*Node maker functio makes the node and returns the address of node if the calloc is succeded*/
nd* node_maker(void)
{
	nd *temp = NULL;
	temp = (nd*)calloc(1, sizeof(nd));

	if(!temp)
	{
		perror("\n\nError in making node");
		exit(1);
	}//if ends
	else
	{
		return temp;
	}//else ends
}//node maker ends

/*--------------------------------------------------------------------------------------------MENU FUNCTION-----------------------------------------------------------------------*/

void menu(void)
{

	printf("\n\n====================================================================Queue Program By Linked List==================================================================");
	printf("\n\n------------------------------------------------------------------------------MENU--------------------------------------------------------------------------------");
	printf("\n\t1.Queue\t2.Dequeue\t3.Display\t4.Exit");
	printf("\nEnter the numerical value: ");
}//MENU ENDS

/*---------------------------------------------------------------------------------------Display Function------------------------------------------------------------------------*/
void display(nd *head)
{
	if(!head)
	{
		printf("\n\tERROR QUEUE IS EMPTY");
		return;
	}
	else
	{
		nd *trav = NULL;
		trav = head;

		while(trav)
		{
			
			printf("%d-->", trav->data);
			trav = trav->next;
		}//while ends
	}//else ends
}//display ends

/*______________________________________________________________________________________________END________________________________________________________________________________*/