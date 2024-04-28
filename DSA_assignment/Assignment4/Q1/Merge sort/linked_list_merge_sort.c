/*This program is for reversing the sub list of a linked list and also tried merge sorting in the linked list*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


/*---------------------------------Structure Defination-------------------------------------------*/
typedef struct nd{
	struct nd *next;
	int value;
}node;

/*---------------------------------Function prototyping-------------------------------------------*/

void insert_node(node **, int *);// to insert node
node* node_maker(void);// to make node
void delete_node(node **, int *);// to delete the node
void display_node(node *);// to display the nodes
void sort_arr_cpy(node **, int );
void merge_sort(int [], int , int);
void combine_array(int [], int , int , int);


/*---------------------------------Global declarations--------------------------------------------*/


/*-------------------------------------Main Starts------------------------------------------------*/
int main()
{
	enum choice{Exit, Insert, Delete, Sort};
	int no_of_node = 0;// to store the node count.
	int u_in, flag =false; //To store the choice of input by user "u_in" variable is used & "flag" var to check the user validation
	node *head = NULL;
	
	while(true){
		enum choice option;// enum variable declared,
		do{
			printf("\n\r\tWelcome to merge sorting");
			printf("\n1.Insert\t2.Delete\t3.Sort\t0.Exit");
			printf("\nEnter choice: ");
			scanf("%d", &u_in);//accepting the user input.
			// to check the user input is within the choices
			if(u_in<0 || u_in>3){
				printf("\n\rYou entered wring option");
				flag = true;
			}//if ends
			else{
				flag = false;
				option = u_in;
			}//else ends
		}while(flag == true);
		
		// switch case to choose the option.
		switch(option){
			
			case Exit:   printf("\n Exiting...");
				     free(head);//freeing the head before exiting the program.
				     exit(0); 
				     break;

			case Insert: insert_node(&head, &no_of_node);
				     display_node(head);
				     break;

			case Delete: delete_node(&head, &no_of_node);
				     display_node(head);
				     break; 
			
			case Sort:   sort_arr_cpy(&head,no_of_node);
				     display_node(head);
				     break;
		}//switch ends
	}//while ends
}// main ends

/*-------------------------------------Insert node--------------------------------------------------*/

/*This function inserts node in the list. 
 * If the list is empty it inserts node to the first place 
 * else it traverse till the last node and inserts the node at end
 * and increases the count of node*/
void insert_node(node **head, int *no_ele)
{
	int val;//Temp var to store the user input value.
	printf("\n\nEnter the value: ");
	scanf("%d", &val);
	node *temp = NULL;
	temp = node_maker();//Calling node maker as we have to insert node anyways.	
	temp->value = val;// inserting value in the newely made node.
	
	//if head is null then add first node
	if(!*head){
		*head = temp;// first node inserted and assigned to head.
		++(*no_ele);//Increasing the count of node 
	}//if ends
	 //else when we have 
	else{
		node *trav = NULL;// Temp pointer to traverse
		trav = *head;// assigning the head to traverse pointer.
		//to traverse till the last node and then add the new node 
		while(trav->next){
			trav = trav->next;	
		}//while ends
		trav->next = temp;// inserting new node to the last of the linked list.
		++(*no_ele);// increasing the count of node in the list.
	}//else ends
}// insert node ends

/*--------------------------------------Node maker---------------------------------------------------*/

/*This function makes node and dose null check, 
 * if node is made it returns the address
 * if node is not made then returns error.*/
node* node_maker(void)
{
	node *temp = NULL;
	temp = (node*)calloc(1, sizeof(node));
	//If temp is NOT NULL then return temp else return an error & exit the program.
	if(temp){
		return temp;
	}//if ends.
	else{
		perror("\n\n\tError in making node");
		exit(0);
	}//else ends.
}// node maker ends.
 
/*--------------------------------------Delete node---------------------------------------------------*/
/*This function deletes the node from end of list by traversing the list till the last 
 * and then breaking the link by inserting NULL in the second last node next address
 * then freeing the last node.*/
void delete_node(node **head, int *no_ele)
{
	node *trav = NULL;
	node *pre = NULL;// This pointer keeps back to the traverse node.
	trav = *head;
	while(trav->next){
		pre = trav;
		trav = trav->next;
	}// while ends
	pre->next = NULL;// to break the link of last node from second last node.
	trav->value = 0;// implictly inserting 0 in the value of node so as to avoid any future accessing of value.
	free(trav);
	--(*no_ele);// decreasing the count of node.
}// delete node ends

/*------------------------------------------Display function---------------------------------------------------*/
/*This function prints the value of all nodes by traversing till the last node.*/
void display_node(node *head)
{
	node *trav = NULL;// local ptr to traverse in list.
	trav = head;// assigning head to traverse pointer.
	
	//to traverse till the last node
	while(trav){
		printf("-->%d", trav->value);//To print the value of node.
		trav = trav->next;// to jump to the next node.
	}// while ends

}// display node ends

/*------------------------------------Merge sorting list-----------------------------------------------------*/
//This function copies all the elements in the list in a array.
void sort_arr_cpy(node **head, int no_ele)
{
	
	node *trav = NULL;// local pointer to traverse.
	trav = *head;
	int arr_main[no_ele];// declaration of array of size of number of  elements in the list.
	for(int i=0; i<no_ele; i++){
		arr_main[i] = trav->value;// inserting the value of node inside the array.
		trav = trav->next;//traversing to the next node.
	}// for ends
	 int left = 0;
	 printf("\n\n***Here");//debugger
	 printf("\n\nNo of element: %d", no_ele);//debugger
	 merge_sort(arr_main,left,no_ele);
	 
}//sort ends.
 
// main merge sort function starts here.
void merge_sort(int arr[], int low, int high)
{
	// base case to stop the recursion is that if the low is grater or equal to high then recursion will not happen.
	if(low < high){
		int mid = (low+high)/2;// To divide the array into 2.
		printf("\n\n***aft mid");//Debugger
		merge_sort(arr, low, mid);//To divide the left array.
		printf("\n\n***aft lh array");//Debugger
		merge_sort(arr, mid+1, high);//To divide the right array.
		printf("\n\n***aft rh array");//Debugger
		combine_array(arr, low, mid, high); // to combine the array in sorted way.
		printf("\n\n***aft cmobine");//Debugger
	}// if ends
}// merge sort ends

// THis function combines the divided array into a sorted fashion.
void combine_array(int arr[], int low, int mid, int high)
{	
	int left = low;printf("\nLow: %d", left);//debuggger
	int right = high;printf("\nHigh: %d", right);//debugger
	// we need to make two temporary arrays here.
	int size_temp = low-high+1;printf("\nsize_of arr: %d", size_temp);// size of left temp array.
	//int size_rh = mid-high+1;// size of right temp array.
	
	//Declaration of LH & RH temp arrays.
	//int lh_temp[size_lh];
	//int rh_temp[size_rh];
	int temp[size_temp];//declared the temp array

	int i=0;
	/*Here we are comparing array elements of divided array, if the left element is small then insert it into the first element of temp array of LH side*/
	while(low<=mid && mid<=high){
		if(arr[left]<arr[high]){
			temp[i] = arr[i];
			i++;// to input next element at the next position of array.
			left++;// to compare the next lh element.
		}// if ends
		/*if the element of lh or rh is at the last element of lh or rh array respectively. Then further elements are needed to be 
		 * inserted in the next position of temp arr without comparision.*/
		else{
			temp[i] = arr[right];
			i++;
			right++;
		}
		/*After comparision if some elements are remaining in the left original array then copy those elements directly into the temp array*/
		while(left <= mid){
			temp[i] = arr[left];
			i++;
			left++;
		}//while ends.
		/*After comparision if some elements are missing in the right original array then copy those elements into temp array.*/
		while(right <= high){
			temp[i] = arr[right];
			i++;
			right++;
		}// while ends
	}//while ends
	//Now we need to copy all the temp array elements into original array.
	for(int i= low;i<high;i++){
		arr[i] = temp[i];
	}// for ends

}// combine ends

