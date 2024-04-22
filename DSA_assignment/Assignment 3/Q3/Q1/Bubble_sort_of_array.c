//Code to sort an array by bubble sort.


#include<stdio.h>

void acend_sort(int []);
void descend_sort(int []);
int main()
{
	int arr[6];
	
	printf("\n\nEnter 6 int values to insert array");
	for(int i =0 ; i<6 ; i++){
		printf("\nEnter %d element: ", i+1);
		scanf("%d", &arr[i]);
	}//for ends
	int choice;
	printf("\nHow you want to sort array: ");
	printf("\n1.For ascending order");
	printf("\n2.For descending order");
	printf("\nEnter Choice: ");
	scanf("%d", &choice);
	
	switch(choice){
	
		case 1: acend_sort(arr);
			break;
			
		case 2: descend_sort(arr);
			break; 
	}//choice ends
	
	
	for(int i=0; i<6;i++){
		printf("\t%d", arr[i]);
	}//for ends

}//main ends

void acend_sort(int arr[6])
{
//Bubble sort for ascending starts
	for(int i= 0; i<6; i++){
		//If in first iteration there is no swapping then abort any swapping further
		
			for(int j=1+i; j<6;j++){
				if(arr[j]<arr[i]){
					
					int temp = arr[i];
					arr[i] = arr[j];
				        arr[j] = temp;
					
				}//if ends
			}//inner for ends
	}//for ends
	
	//To print the array.

}


void descend_sort(int arr[6])
{
//Bubble sort for ascending starts
	for(int i= 0; i<6; i++){
		//If in first iteration there is no swapping then abort any swapping further
		
			for(int j=1+i; j<6;j++){
				if(arr[j]>arr[i]){
					
					int temp = arr[i];
					arr[i] = arr[j];
				        arr[j] = temp;
					
				}//if ends
			}//inner for ends
	}//for ends
	
	//To print the array.

}
