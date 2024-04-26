//Linear search

#include<stdio.h>
#define SIZE 10
void linear_search(int [], int);

int main()
{
	int size;
	printf("\nEnter the size of array: ");
	scanf("%d", &size);
	int arr[size];//Taking array in stack
	
	for(int i=0; i<size; i++){
		printf("\nEnter the element at %d: ",i+1);
		scanf("%d", &arr[i]);
	}
	
	linear_search(arr, size);

/*
 * Normal jindagi (This all variables where hardcoded eg size = 6)
	
 	int target = 8;
	//to traverse in the array
	for(int i = 0; i<6; i++){
		if(target == arr[i]){
			printf("\nElement found at %d place", i+1);
		}
	}//for ends	

*/
	
}//main ends

//Mentos jindagi
void linear_search(int arr[], int i)
{
	/*
	 * The following 3 lines needs to be put in the main function and to be passed as parameter
	int target;
	printf("\n\nEnter the target: ");
	scanf("%d", &target);
*/
	/*the following if condition checks that the i !=0 and if the target is found
	 * because if i=0 then the index is already of first position then we don't need 
	 * to traverse to privoius element more*/
	if(i>=0 && target == arr[i]){// if target is found then return.
		printf("\nElement found at place %d place in array", i+1);
		return;
	}
	else{
		/*If the target is not found then call linear_search 
		function again with decrimenting the size variable 
		as we have to change the index  */
		
		linear_search(arr, --i);// recursive case
	}

}// linear sort ends.
