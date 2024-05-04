/*Normal queue program
 * Implementing Array as queue
 * Here different pointers are used to insert and delete elements.*/

#include<stdio.h>
#include<stdlib.h>
#define GOOD_GARBAGE -99 // This is the good garbage value for inserting inplictly in the queue
#define INITIAL -1 // initial value as -1
#define SIZE 6


void enq(int [], int *, int *);//To enqueue the stack.
void display(int []);// to display the queue.
void dequeue (int [], int *, int *dequeue);// To dequeue the stack.
void peep(int [], int *);// To peep in the queue


int main()
{
	enum method  {Exit,Enqueue,Deque,Display};// local enum for reliability of code
	enum  method choice;// enum variable
	int fr = INITIAL;
	int rr = INITIAL;
	int *front, *rear, user_ip;
	//pointers of front and last to pass in the function.
	front = &fr;
	rear = &rr;
	int arr[SIZE];

	//Explictely inserting -99 in the array.
	for(int i=0; i<SIZE; i++){
		arr[i] = GOOD_GARBAGE;
	}//for ends

	

	while(1){
		printf("\n1->Enqueue\n2->Dequeue\n3->Display Queue Element\n0->To exit");
		printf("\n\nEnter the choice: ");
		scanf("%d", &user_ip);
		
		choice = user_ip;
		switch(choice){
		
			case Exit:    printf("\n\nExiting ....");
				      exit(0);
				      break;
			case Enqueue: enq(arr, front, rear);
				      break;
			case Deque: dequeue(arr, front, rear);
				      break;
			case Display: display(arr);
				      break;

		}//switch ends
	}//While ends
	

}// main ends


/*This function does enqueue operations on queue, if the front is at the last place then it returns as queue is full*/
void enq(int arr[], int *front, int *rear)
{
	int ele;
	//if rear is at size-1 then queue is full and will not accept any element till the whole queue is empty as it is not a circular queue.
	if(*rear == (SIZE -1)){
		printf("\nQueue is full");
		return;
	}// if ends
	else{
		/*This takes the element and then incriments the rear pointer then inserts the element at the index.*/
		printf("\nEnter the element to add: ");
		scanf("%d", &ele);
		++(*rear);// incrimenting the rear so as the rear will be on next index.
		arr[*rear] = ele;//inserting on the incrimented place.
		printf("Rear ptr: %d", *rear);//debugger
		printf("\nInsertion done\n\n");

		//if front = Initial value(ie: -1) then assign 0 implictly to front as as to know that there are values in queue.
		if(*front == INITIAL){
			*front = 0;
		}
	}//else ends
		
	display(arr);// to display the queue elements.
	

}//enqueue ends

/*The following function dequeues the queue and incriments the front pointer, also this checks that the queue is empty.*/
void dequeue(int arr[], int *front, int *rear){
	
	//If front is at -1 then the queue is empty and cannot dequeue any element from queue.
	if(*front == INITIAL){
		printf("\tQueue is empty\n");
		return;
	}// if ends
	
	else{
		/*The following code has 2 conditions
		 * 1.If front and rear pointers are at same index then initialize both front and rear to Initial condition (ie:-1)
		 * 2.If not then incriment the front pointer */

		int temp = arr[*front];// Take the current element in the temp variable.
		arr[*front] = GOOD_GARBAGE;
		
		//if front and rear pointers are at same place then reset them to initial value.
		if(*front == *rear){
			*front = INITIAL;
			*rear = INITIAL;
		}// if ends
		
		else{
			++(*front);// incrimenting the front.
		}//else ends
		
	}// else ends
	printf("\nFront ptr = %d", *front);
	display(arr);
}//Dequeue ends

//Dsiplay function to display the elements in queue
void display(int arr[])
{
	printf("\nElements in queue: ");
	for(int i = 0; i<SIZE ; i++){
		// just print the elements in queue
		if(arr[i] != GOOD_GARBAGE){
			printf("%d\t", arr[i]);
		}// if ends
	}// for ends

	printf("\n");
}//display ends


//To peep inside queue.
void peep(int arr[], int *front)
{
	printf("\nPEEP: %d", arr[*front]);// to print the current element in which the front is pointing.
}//peep ends
