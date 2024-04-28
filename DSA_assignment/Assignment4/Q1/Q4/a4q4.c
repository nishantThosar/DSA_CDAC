/*Q4. Write a C/C++ program to implement circular queue data
 * structure using array. Implement below metioned functions.
 * a) add b) delete c) peep d) displayQueue e)isQueueFull
 * f) isQueueEmpty
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define GOOD_GARBAGE -99
#define INITIAL -1

void print_queue(int *, int);
void enqueue(int *, int ,int *,int *);
void print_queue(int *, int);
void de_queue(int *, int , int *, int *);

int main()
{
	enum option {Exit, Enqueue, Dequeue, Display};//enum to increase the readablity of code.
	enum option choice;//enum variable
	int rear = INITIAL;// initialization with -1.
	int front = INITIAL;//initilization with -1.
	int size, user_input;// temp var to store the user inputs of size & choice of switch case .
	printf("\n\nEnter how much size of queue you want: ");
	scanf("%d", &size);
	
	int *my_calloc = (int*) calloc(size,sizeof(int));
	if(!my_calloc){
		perror("\nMemory allocation failed");
		exit(0);
	}
	
	//To insert -99 in each element of queue.
	for(int i=0; i<size; i++){
		my_calloc[i] = GOOD_GARBAGE;
	}// for ends.
	
	while(1){
		bool flag = false;
		do{
			printf("\n\r\t-----------------------Circular Queue-----------------------------");
			printf("\n\r1. Queue\t2.Dequeue\t3.Display\t0. Exit");
			printf("\nEnter numerical option: ");
			scanf("%d", &user_input);
			if(user_input<0 || user_input>3){
				flag = true;
				printf("\n\tWRONG INPUT\n\n");
			}//if ends
			else{
				flag = false;
				choice = user_input;
			}//else ends
		}while(flag == true);//do while loop ends.
		
		switch(choice){
			
			case Exit:     printf("\nExiting-----\n");
				       free(my_calloc);// to return the heap memory pool.
				       exit(0);
				       break;
			case Enqueue:  printf("\n---------Queue operation");
				       printf("\n\nHear rear = %d\n", rear);//debugger 000000000 Rear =-1 00000000000
				       enqueue(my_calloc,size,&front,&rear);
				       print_queue(my_calloc, size);
				       break;

			case Dequeue:  printf("\n-------Dequeue operation");
				       de_queue(my_calloc,size, &front, &rear);
				       print_queue(my_calloc, size);
				       break;

			case Display:  printf("\n-----------Printing Queue");
				       print_queue(my_calloc, size);
				       break;
		}//switch ends
	}//while ends
}// main ends
 
/*To enqueue the elements*/
void enqueue(int *queue, int size, int *front, int *rear)
{
	// if the rear is at the last place and front is at 0th position then we can say that the queue is full
	if(*rear = size-1 && *front == 0){
		perror("\n\t\rQueue is full");
		return;
	}// if ends.
	else{
		int ele=0;
		printf("\nEnter the value you want to enter in queue: ");
		scanf("%d", &ele);
		//if rear is at last place and front is not at the first position then traverse the rear to the 0th place as we have place empty behind front.
		printf("\nRear = %d", *rear);//debugger 000000000 Here problem 00000.
		if(*rear != size-1 && *front !=0){
			++(*rear);
			queue[*rear] = ele;
			/*Now to bring the front to the first position of queue.*/
			if(*front == INITIAL){
				++(*front);//incrimenting front to the first position of queue
			}//if ends.
		}//if ends
		
		/*else if the rear & front is not at same position then incriment rear and then insert the element.
		 * Also if the next place is -99 (empty) then only insert at the next place after incrimenting */
		else if(*rear != *front && queue[*rear+1] ==-99){
			++(*rear);//incriment the rear pointer
			queue[*rear] = ele;//inserting the element at position.
		
			//if the front is at -1 then need to bring it to the 0th position of queue.
			if(*front == INITIAL){
				*front = 0;// to bring the front to the frist position of queue.
			}// if ends
		
		}//else if ends
		else{
			printf("\n\rQueue is full");
		}//else ends
	}//else ends

}// enqueue ends

void de_queue(int *queue, int size, int *front, int *rear)
{
	if(*front == size-1){
		perror("\n\n\tQueue is empty");
	}//if ends
	else{
		/*If the front and rear are at same place then print the current element(ie: last element at in the queue), then reset both front & rear to -1*/
		if(*rear == *front){
			if(queue[*front] !=GOOD_GARBAGE){
				printf("%d",queue[*front]);
				queue[*front] = GOOD_GARBAGE;
				*front = *rear = INITIAL;
			}//nested if ends.
			// if the front and rear are at same place but the value is not present then diretly reset them.
			else{
				*front = INITIAL;
				*rear = INITIAL;
			}//nested else ends
		}//if ends.
		/*if front and rear are not at the same location and if the rear hasnt't passed front(rear = front +1) then incriment the front and print the value*/
		else if (*rear != *front+1){
			printf("\n%d", queue[*front]);
			++(*front);//incrimenting front to point the next index.
		}//else if ends
		else{
			perror("\nQueue is empty");
		}//else ends
	}// outer else ends

}// dequeue ends

//To print the elements in queue
void print_queue(int *arr, int size)
{
	for(int i=0;i<size;i++){
		printf("\t%d", arr[i]);
	}//for ends

}//print_queue ends

