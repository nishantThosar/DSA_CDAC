//Code to sort an array


#include<stdio.h>

int main()
{
	int arr[] = {1,2,3,4,5};
	int flag = 0;
	//printf("%d", sizeof(arr)/sizeof(arr[0]));
	
	//Bubble sort starts
	for(int i= 0; i<(sizeof(arr)/sizeof(arr[0])); i++){
		//If in first iteration there is no swapping then abort any swapping further
		if(flag == 1){
			for(int j=1+i; j<(sizeof(arr)/sizeof(arr[0]));j++){
				if(arr[j]<arr[i]){
					int temp = arr[i];
					arr[i] = arr[j];
				       	arr[j] = temp;
					flag = 1;	
				}//if ends
			}//inner for ends
		}//if loop ends
	}//for ends
	
	//To print the array.
	for(int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++){
		printf("\t%d", arr[i]);
	}//for ends

}//main ends

