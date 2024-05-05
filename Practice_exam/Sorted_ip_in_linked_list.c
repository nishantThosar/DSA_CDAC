//To insert the element in the linked list in the correct positoin.

#include<stdio.h>
#include<stdlib.h>
/*++++++++++++++++++++++++++++++++++++++++STRUCT DEFINATINO++++++++++++++++++++++++++++++++++++++++++*/
typedef struct node
{
	struct node *next;
	int value;
}nd;

/*+++++++++++++++++++++++++++++++++++++++++FUNC PROTOTYPES+++++++++++++++++++++++++++++++++++++++++++*/
nd* node_maker(int *);
void sorted_insert(nd **head, int *count);
void display(nd *);

/*+++++++++++++++++++++++++++++++++++++++++++++MAIN++++++++++++++++++++++++++++++++++++++++++++++++++*/
int main()
{
	int count = 0;
	nd *head = NULL;
	while(1){
		sorted_insert(&head, &count);	
	}
	return 0;
}//main ends

/*+++++++++++++++++++++++++++++++++++++++++++NODE MAKER++++++++++++++++++++++++++++++++++++++++++++++*/
nd* node_maker(int *count)
{
	nd *temp = NULL;

	temp = (nd*)calloc(1,sizeof(nd));
	if(!temp)
	{
		perror("\n\nError in node making");
		exit (0);
	}//if ends
	else
	{
		++(*count);
		return temp;
	}//else ends
}//node maker

/*+++++++++++++++++++++++++++++++++++++++++SORTED INSERT++++++++++++++++++++++++++++++++++++++++++++++++*/
void sorted_insert(nd **head, int *count)
{
	int ele;
	printf("\n\nEnter the element");
	scanf("%d", &ele);
	nd *temp = node_maker(count);
	temp->value = ele;

	nd *trav = NULL;
	trav = *head;


	if (*head == NULL)
	{
		*head = temp;
	}//if ends
	else
	{
		if(trav->value > ele)//insert at beg
		{	
			printf("**************here0");
			temp->next = *head;
			*head = temp;
		}//if ends
		else
		{
			while((trav->next !=NULL) && (trav->next->value < ele))
			{
				printf("\n***********here1");//debugger
				trav = trav->next;
			}//while ends
			if(trav->next == NULL)//insert at end
			{
				printf("\n***********here2");//debugger
				trav->next = temp;
				
			}//if ends
			else//insert at pos.
			{
				printf("\n***********her3");//debugger
				temp->next = trav->next;
				trav->next = temp; 
			}//else ends
		}//else ends
	}//else ends
display(*head);
}//sorted insert ends

void display(nd *head)
{
	nd *temp = NULL;
	temp = head;
	while(temp)
	{
		printf("-->%d", temp->value);
		temp = temp->next;
	}//while
}//display ends

/*+++++++++++++++++++++++++++++++++++++++++++++++POSITION FINDER++++++++++++++++++++++++++++++++++++++*/
/*int pos_finder(nd *head, int pos)
{
	int ele;
	printf("\nEnter the value: ");
	scanf("%d", &ele);
	int cnt = 0;
	nd *trav = NULL;
	trav = head;
	for (int i = 1; i < pos ; ++i)
	{
		if(trav){
			if(trav->value <ele)
			{
				trav = trav->next;
				cnt++;
			}//if ends
		}//if ends;
		else
		{
			return 0;
		}//else ends
	}//for ends
	return cnt;
}//pos finder ends*/

/*++++++++++++++++++++++++++++++++++++++++++++++INSERT AT POSITION++++++++++++++++++++++++++++++++++++*/
/*void insert_at_pos(nd **head, int *count, int pos, int ele)
{
	nd *temp = NULL;
	nd *trav = NULL;
	nd *trav2= NULL;
	temp = node_maker(count);
	trav = *head;

	//traverse till the position
	for(int i=0; i<pos; i++)
	{	
		trav2 = trav;
		trav = trav->next;
	}//for ends
	//insert at the positoin.
	trav2->next = temp;
	temp->next = trav;
}//insert at position ends*/

/*+++++++++++++++++++++++++++++++++++++++++++++INSERT AT END++++++++++++++++++++++++++++++++++++++++++*/
/*void insert_at_end(nd **head, int *count)
{
	nd *temp = NULL;
	nd *trav = NULL;
	trav = *head;
	temp = node_maker(count);
	//traversing the pointer to the last node.
	while(trav->next)
	{
		trav = trav->next;
	}//while ends
	trav->next = temp;//insert the node at the end.
}//insert at ends ends
*/
/*+++++++++++++++++++++++++++++++++++++++++INSERT AT BEGINGING FUNCTION++++++++++++++++++++++++++++++++*/
/*void insert_beginging(nd **head, int count)
{
	int ele;
	printf("\n\nEnter the value");
	scanf("%d", &ele);
	nd *temp = NULL;
	temp = node_maker(&count);
	if(!(*head))
	{
		temp->value = ele;
	}//if ends
	else
	{
		temp->next = *head;
		*head = temp;
	}//else ends
}//insert at begning ends
*/
/*++++++++++++++++++++++++++++++++++++++++++NODE MAKER++++++++++++++++++++++++++++++++++++++++++++++++*/
