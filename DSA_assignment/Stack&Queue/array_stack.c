//Program to use array as an stack

#include<stdio.h>
#include<stdlib.h>

void push(int [], int *);//function to push elements on stack.
void display(int [], int *);// function to display the elements on stack.
void pop(int [], int *);//function to pop the latest element out of stack.
void peep(int [], int *);//To peep at the array and print the current element of array at which stack pointer is pointing

int main()
{
	int choice = 0;//Temp var to store the switch case choice value.
	int stack_ptr=-1;//To get the position of stack pointer (initilizd to -1 for conditional checking of stack empto or full).
	int *s_ptr = &stack_ptr;//pointer to stack. Due to this variable we can push or pop the elements at place

	int arr[6];// array declaration of size 6(i.e: We have a stack of 6 layers).
	
	while(1){
		//To enter the operation push or pop.
		printf("\n\nEnter the operation you want to do");
		printf("\n0. To exit the program\n1.PUSH operation\n2.POP operation\n3.To peep in stack\nEnter the numerical choice: ");
		scanf("%d", &choice);// entering choice.
		
		//Switch case for choosing the push or pop operations.
		switch(choice){
		
		case 0: //To exit the program	
			printf("\nExiting....");
			exit(0);
		
		case 1:// For pushing operations
			push(arr, s_ptr);
			break;
		case 2: //For poping operations
			pop(arr, s_ptr);
			break;	
		case 3: // For peeping in the stack
			peep(arr, s_ptr);
		}//switch ends
	}//While ends.

}//main close

/*This function first checks if the stack is empty or not if empty then it inserts one element inside the stack.Also displays the number of elements in stack 
 * and if the stack is full then prints "stack full" and returns to main menu*/
void push(int arr[], int *top_pos)
{
	int ele;
	if(*top_pos < -1  || *top_pos < 6){
		++*top_pos;
		printf("\nEnter the element to add: ");
		scanf("%d", &ele);
		arr[*top_pos] = ele;
		printf("\nTotal no of elements in stack: %d",*top_pos+1);/*+1 is done to adjust the display of no of elements in the stack as
									   I have initilized stack pointer =-1 in main*/

		display(arr, top_pos);
		
	}// if close
	else{
		printf("\nStack full");
		return;
	}// else ends

}//push ends


//This function pops out the latest entered value also it checks if the stack is empty then prints "Stack is empty".
void pop(int arr[], int *top_pos){
	
	if(*top_pos >-1){
	
		
		printf("\n%d",arr[*top_pos]);

		--(*top_pos);
		printf("\nTotal no of elements in stack: %d",*top_pos+1);/*+1 is done to adjust the display of no of elements in the stack as
									   I have initilized stack pointer =-1 in main*/
	}// if ends
	else{
		printf("\nStack Empty");
		return;
	}

}//pop ends


//Function to display the elements in stack.
void display(int arr[], int *top_pos)
{
	for(int i=-1; i<*top_pos; i++){
		printf("\n\nIn stack\t%d", arr[i+1]);/*+1 is done to adjust the display of no of elements in the stack as
									   I have initilized stack pointer =-1 in main*/

	}//for ends
}// display ends


//To peep the current value in stack
void peep(int arr[], int *top_pos){
	//If the pointer is in the stack then the peep will be printed
	if(*top_pos>=0 && *top_pos<6){
		printf("\nCurrent element: %d",arr[*top_pos]);//to print the stack.
	}//if ends
	else{
		printf("\nStack is empty\n");
		return;
	}// else ends
}// peep ends
