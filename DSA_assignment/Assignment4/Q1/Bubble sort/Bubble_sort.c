//Program for quick sort

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/*-------------------------------Structure Deifination------------------------------------------*/
typedef struct nd{
	struct nd *prev;
	struct nd *next;
	int value;

}node;
/*-------------------------------Function Declarations------------------------------------------*/
node* node_maker(void);
void insert(node **, int *);
void display(node *);


/*--------------------------------Global declarations-------------------------------------------*/


/*000000000000000000000000000000000 Main Starts 000000000000000000000000000000000000000000000000*/
int main()
{
	int no_of_ele = 0;
	node *head = NULL;
	insert(&head, &no_of_ele);
	display(head);
}//Main ends
 
//Function to make nodes
node* node_maker()
{
	node *temp = (node*) calloc (1,sizeof(node));
	if(temp){
		return temp;
	}
	else{
		perror("\nMemory allocation failed");
		exit(0);
	}//else ends
}//node maker ends
 
/*Function to insert the node at the end or make the first node*/
void insert(node **head, int *no_ele)
{

	int val;
	node *temp = NULL;// took a local temp pointer.
	temp = node_maker();// making a new node by calling node maker function.
	printf("\n\rEnter the value to be entered in the node: ");
	scanf("%d", &val);// Accepting value of element in node.
	temp->value = val;// inserting user input value in node.
	temp->next = NULL;// inserting NULL in the next address of node.
	temp->prev = NULL;// inserting NULL in the privious address of node.

	//If head is empty then assign the first node to the head.
	if(! (*head)){
		*head = temp;//assigning address of temp to head as temp will be the first node of list.
		++(*no_ele);// incrimenting the no of node.
	}//if ends
	 //if head is not empty then insert the node at the first position.
	else{
		*head->prev = temp;//inserting address of temp in privious of head.
		temp->next = *head;//inserting address of head in next of temp.
		*head = temp;// changing position of head.
		++(*no_ele);//incrimenting no of elements in list.
	}//else ends
}//Insert ends

//this function displays the elemtnt value in node.
void display(node *head)
{
	node *trav = NULL;// local pointer for traversing
	trav = head;
	//to traverse till the last of node
	while(!trav){
		printf("%d<--", trav->value);
		trav = trav->next;
	}//while ends
}// display end
 
/*This function makes array for bubble sorting br inserting each element value in the node to the array of size of nodes.*/
void bubble_array(node *head, int *no_ele)
{
	int arr[*no_ele], i=0;
	node *trav = NULL;
	trav = head;
	//for inserting each value of node in the array.
	while(trav->next){
		arr[i] = trav->value;
		++i;
	}// while ends
	
}//bubble array ends


/*This is the function for bubble sorting*/
void bubble_sort(int arr[], int *no_ele)
{
	bool flag = false;// flag to detect if the sorting has been happend in the first iteration or not.
	for(int i=0; i<*no_ele; i++){
		//if swapping happens at the first itration then only continue the sorting.
		do{
			for(int j=1; j<(*no_ele-1); j++){
				//if the first element is grater than the next element then swap the positions.
				if(arr[j]> arr[j+1]){
					arr[j]   = arr[j]^arr[j+1];
					arr[j+1] = arr[j+1]^arr[j];
					arr[j]   = arr[j]^arr[j+1];
					flag = true;
				}//if ends
			}//nested for ends
		}while(flag = true);// do-while loop ends.
	}//for ends
}// bubble sort ends
