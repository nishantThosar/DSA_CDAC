//Program of priority queue 


#include<stdlib.h>
#include<stdio.h>
#define INITIAL -1
#define SIZE 6

typedef struct queue{

	int priority;
	int value;
}que;

void input_sort(que arr[], int *, int *);//Inserting the elements priority sorted
void display(que arr[], int *, int *);// Function to display the elements in queue
void de_queue(que arr[], int *, int *);// Function to de_queue the elements in queue


int main()
{
	int fr = INITIAL;//front var will be passed as the pointer in the function to keep the track of index.
	int rr = INITIAL;//rear var will be passed as pointer in the function to keep track of index.
	//int *front = &fr;
	int choice;// to input choice of switch case
	que arr[SIZE];// defining the size of array
	enum input{Exit,Queue,Dequeue,Display};// enum to increase the readablity of code
	enum input user_input;// enum variable

	while(1){
		printf("\n\n\tWelcome to the priority queue program");
		printf("\n1->Enqueue\n2->Dequeue\n3->Display elements\nTo exit program enter 0");
		printf("\nEnter numerical choice: ");
		scanf("%d", &choice);
		user_input = choice;
		switch(user_input){
			
			case Exit:    printf("\nExiting---\n");
				      exit(0);
				      break;
			
			case Queue:   input_sort(arr, &fr, &rr);
				      break;
			
			case Dequeue: de_queue(arr,&fr,&rr);
				      break;
			
			case Display: display(arr, &fr, &rr);
				      break;
		}//Switch ends
	
	}//While ends	

}//main ends


/*This function accepts user inputs and checks two thing
 * 1. If there are no elements in Queue then enteres the element entered by user to the first place
 * 2. If there are elements in the queue then checks the priority and inserts the element to the appropriate position.*/
void input_sort(que arr[], int *front,int *rear)
{

	int pri, val,count= 0;
	printf("\n\nEnter the priority: ");
	scanf("%d", &pri);
	printf("\n\nEnter value: ");
	scanf("%d", &val);

	//If there are no elements in queue then add the first element in the queue.
	if(*rear == INITIAL){
		++(*rear);
		arr[*rear].priority = pri;
		arr[*rear].value = val;
		count++;
		//While adding the first element the front should be brought at 0 from INITIAL value.
		if(*front == INITIAL){
			*front = 0;
		}//if ends
	}//if ends
	//Else there are elements in queue then find the correct position to insert the element then insert the element.
	else{
		//if the rear is  not on the last index then only can enter in the element, else print queue is full
		if(*rear != (SIZE -1)){
			for(int i=0; i<SIZE-1 ; i++){
				printf("**** Here ****");
				if(pri < arr[i].priority){//if the user input priority is less than the current priority then shift the current elements and then insert.
					//++(*rear);// incrimenting the rear.
					//swapping from the rear
					//for(int j=*rear; j>0; j--){
					printf("Here Again");	
					printf("HERE rear value : %d\n",*rear);
					for(int j = *rear; j >= i  ; j--)
					{
						printf("HERE J value : %d\n",j);
						que temp;
						temp.priority = arr[j].priority;
						temp.value= arr[j].value;
						arr[j+1] = temp;
						printf("Arr[%d] : %d\t%d & arr[%d] : %d\t%d\n",j,arr[j].priority, arr[j].value,j+1,arr[j+1].priority,arr[j+1].value);
					
					}
						//}//for ends
					arr[i].priority = pri;// updating the value of priority
				       	arr[i].value = val;
					(*rear)++;	
					break;
				}//if ends
				else{// else if the user input priority is not less then add it to the next index of queue.
					++(*rear);
					arr[*rear].priority = pri;
					arr[*rear].value = val;	
					break;
				}// else ends
			}//for 	ends	
		}//if ends
		else{// else if the rear is at last index then print queue is full.
			printf("\n\tQueue is full\n");
			return;
		}//else ends
	}//else ends	
	display(arr, front, rear);
}// input sort ends



/*This function prints the element between the front and rear elements of queue.*/
void display(que arr[], int *front, int *rear)
{

	for(int i = *front; i<=*rear; i++){
		printf("\nPriority: %d", arr[i].priority);
		printf(" | Value: %d", arr[i].value);
	}// for ends
}// display ends


void de_queue(que arr[], int *front, int *rear)
{
	if(*rear == INITIAL){
		printf("\nQueue is empty");
		return;
	}// if ends
	else{
		if(*rear == *front){
			*front = INITIAL;
			*rear = INITIAL;
		}// if ends
		else{
			printf("Value: %d", arr[*front].value);
			printf("Priority: %d", arr[*front].priority);
			--(*front);//decrimenting front pointer to reduce its index.
		}// else ends
	}// else ends

}//dequeue ends

