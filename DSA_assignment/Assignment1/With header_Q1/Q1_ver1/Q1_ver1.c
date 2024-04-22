/*Q1. Write a C/C++ program that declares an array of length N
containing integers between 1 and N. Implement menu driven
program using switch case for below mentioned functionalities.
(a) insert element at index
(b) delete element at index
(c) find min val
(d) find max val
(e) display array element
(f) reverse display array element
(g) search element in array
(h) array element count
(i) avg of all array element
(j) determine if array contains any duplicates.
(k) reverse array element
*/

//Find not working.

#include<stdio.h>
#include<stdlib.h>

//func prototyping
int* insert_element(int *, int *, int *);
void display(int *, int*);
void find_min(int *, int *);
void reverse_display(int *, int*);

//Global declarations of variables.


int main()
{
    	int *address = NULL;//a ptr to heap locaton(Just like Head pointer).
    	int ele = 0;// To trace no of elements in array.
	int choice;// to store the choice of menu(user inpt).
	int size_of_arr = 0;// to trace the size of array.
while(1){
	printf("\n\n=================== Menu =======================");
	printf("\n1-> To enter a element at position in array.");
	printf("\n2-> To delete a element at position in array.");
	printf("\n3-> To find mimiumu value element in array.");
	printf("\n4-> To find maximum value element in array.");
	printf("\n5-> To display elements in array.");
	printf("\n6-> To reverse display elements in array.");
	printf("\n7-> To search an element in array.");
	printf("\n8-> To display element count in array.");
	printf("\n9-> To display average of every elementin array.");
	printf("\n10-> To find any duplicate element in array.");
	printf("\n0-> To exit ");
   	printf("\n\nEnter the choice: ");
		
	scanf("%d", &choice);

	switch(choice){
	
		case 0: printf("Thankyou\n\n");
		      	exit(0);
			break;

		case 1: address = insert_element(&ele, address, &size_of_arr);
			printf("\n\nCurrent element count is: %d", ele);
			break;

		case 2: find_min(address,&size_of_arr); 

			break;

		case 5: reverse_display(address, &size_of_arr);
	/*	case 1: 
		case 1: 
		case 1: 
		case 1: 
		case 1: 
		case 1: 
		case 1: 
	*/
	}//Switch ends    
    }//While ends
}// main ends

// Function to insert element
int* insert_element(int *ele, int *address, int *size_of_arr)
{
    int element, *ptr, pos;
    //for checking that the array is made or not.
    if(*ele == 0){
        printf("\nEnter position: ");
        scanf("%d", &pos);//accepting the user input of position.
	printf("Enter element: ");
	scanf("%d", &element);// accepting the user input of element value

        ptr = (int*)calloc(pos,sizeof(int));// assigning the size till position in heap.
	
	//For checking if the calloc is failed or not.
	if(ptr == NULL){
		perror("Failed to assign size");
		exit(0);// if calloc failed exit the program.
	}// if ends
	
	address = ptr;//if successfully allocated the memory in heap assign the address of heap to address ptr.
        ptr[pos-1] = element;// entering the value of element.
       	++*ele;//incrimenting the element value by 1
	*size_of_arr = pos;//For logging the size of array.
	display(size_of_arr, address);// calling display func.
        return ptr;// returning the ptr.
    }//if ends

    else{//if array already exists.
	    printf("\nEnter a pos: ");
	    scanf("%d", &pos);//user entry of position,
	    printf("\nEnter element: ");
	    scanf("%d", &element);// user entry of element value.
	    
	    //to check if the array size is within the position, and if not then realloc and create a new size with same elements.
	    if(pos >=*size_of_arr){
	    	ptr = (int*)realloc(ptr,pos*sizeof(int));//Reallocating the size of array.
		ptr[pos-1] = element;//assigning the respective array location with element value.
		++ele;//incrimenting the element.
		*size_of_arr = pos;// updating the size of array if current size < pos.
		address = ptr;// updating the new address after realloc.
		display(size_of_arr, address);// calling display
	    }//if ends
	    else{
	    	ptr = address;// getting heap address of array in a pointer.
		ptr[pos-1] = element;// assigning the position in heap the element value inserted by user.
		++*ele;//incrimenting the element
		display(size_of_arr, address);// calling display
	    }// else ends
    
    	}//else ends.

}// Insert element ends


//Function to print the elements of array.
void display(int *lim, int *a_ptr)
{
    for(int i = 0; i<*lim; i++){// for loop to iterate the array.
        printf("\nValue in array = %d", a_ptr[i] );
    }// for ends
}//display ends.

//Function to find the minimum value in array.
void find_min(int *address,int *size)
{
	int *ptr = address;
	int *ptr2 = address;
	
	//Loop to iterate till the last element of array
	for(int i = 0; i<*size; i++){
		ptr2 = ptr;
		if(ptr[i]<ptr2[i+1]){
			printf("Minimum value in array is: %d", ptr[i]);
		}//if ends	
	}//for ends

}//find minumum ends
 

//reverse display of array.
void reverse_display(int *add, int *size)
{
	int *ptr = add;
	int i = *size;
	for(; i<=*size;i--){
		printf("Value at %d: %d",i,add[i]);
	
	}// for ends.
}//reverse display ends
