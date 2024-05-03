//Program for linked list

#include<stdio.h>
#include<stdlib.h>
/*------------------------------------------------------------Struct declaration-------------------------------------------------*/
struct node{

	struct node *next;
	struct node *prev;
	int data;
};
/*--------------------------------------------------------------Function prototypes-----------------------------------------------*/
void menu(void);// to print menu
struct node* node_maker(void);// to make node
void node_insertion(struct node **);//to insert node
int search(struct node** , int);// to search the correct place to insert node.
void display(struct node *);

/*----------------------------------------------------------------------main------------------------------------------------------*/
int main()
{
	struct node *head = NULL;// head pointer to the linked list
	
	int user_choice;
	enum choice{Insert,Display,Exit};
	enum choice option;//enum var

	while(1)
	{
		menu();//menu function calling
		scanf("%d", &user_choice);//for accepting the user input
		//printf("\nUser ip: %d", user_choice);//debugger
		/*option = user_choice;//assigning the user input to the enum variable.
		
		switch(option)
		{
			case Insert:	node_insertion(&head);
							display(head);
							break;
				
			case Display:	display(head);
							break;

			case Exit:		free(head);
							return 0;
		}//switch ends*/

		switch(user_choice)
		{
			case 1: node_insertion(&head);
					break;
			case 2:	display(head);
					break;

			case 3: free(head);
					exit(0);
		}//switch ends
	}//while ends
}//main ends

/*--------------------------------------------------node insertion function----------------------------------------------*/
void node_insertion(struct node **head)
{
	struct node *temp = NULL;//temp local pointer.
	temp = node_maker();// to make a node

	int data;
	//if head is null then need to insert first node.
	if(*head == NULL){
		printf("\n\nEnter the data: ");
		scanf("%d", &temp->data);
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
		display(*head);
	}//if ends
	//if head is not null then find the right place to insert
	else
	{
		int temp_data, count;
		//struct node *temp = NULL;
		struct node *trav = NULL;
		trav = *head;

		printf("\n\nEnter the data to add next: ");
		scanf("%d", &temp_data);
		printf("\n****Here");//debugger
		count = search(head,temp_data);//to count the traverse.
		printf("Count: %d", count);//debugger
		/*Trav till the node then insert the node at the place*/
		for(int i=0; i<count; i++)
		{
			trav = trav->next;
		}//for ends.

		//temp = node_maker();// making new node.
		temp->data = temp_data;// inserting the data in the node.
		//inserting the node at the place.
		

		trav->prev->next = temp;
		temp->prev = trav->prev;
		trav->prev = temp;
		temp->next = trav; 
		display(*head);
	}//else ends.
	

}// node insertion ends

/*---------------------------------------------------------------search function--------------------------------------------------*/
int search(struct node **head, int target)
{
	int count = 0;// to keep the count of traverse.
	struct node *trav = NULL;
	trav = *head;// now head and temp are on the same node.
	printf("hi\n");
	if ((*head)->next == NULL )
	{
		if(target <= (*head)->data)
			return 0;
		else
			return 1;
	}
	count = 1;
	while( trav->next != NULL)
	{
		printf("hi2\n");
		count++;
		if(trav->data <= target)
		{	
			printf("\nCount: %d", count);
			return count;
		}//if ends
		trav = trav->next;
	}//while ends
	return count+1;
}

/*--------------------------------------------------------------------node maker---------------------------------------------------*/
struct node* node_maker(void)
{
	struct node *temp = NULL;// temp pointer to struct.
	temp = (struct node*) calloc(1,sizeof(struct node));// making a node in the heap

	if(!temp)
	{
		perror("\nMEMORY ALLOCATION FAILED.... EXITING PROGRAM");
		exit(0);
	}//if ends
	else
	{
		return temp;
	}

}//node maker ends


/*-------------------------------------------------------------Menu display function------------------------------------------------*/
void menu(void)
{
	printf("\n\n------------------------------------------Doubly linked list program------------------------------------------------");
	printf("\n--------------------------------------------------------Menu----------------------------------------------------------");
	printf("\n1.Insert node\n2.Display node\n3.Exit");
	printf("\nEnter the numerical option: ");
	return ;

}// menu ends
/*------------------------------------------------------------Display function--------------------------------------------------------*/
void display(struct node *head)
{
	struct node *trav = NULL;
	trav = head;
	while(trav)
	{
		printf("--->%d", trav->data);
		trav = trav->next;
	}//while ends
}//display ends

/*-----------------------------------------------------------END------------------------------------------------------------------------*/