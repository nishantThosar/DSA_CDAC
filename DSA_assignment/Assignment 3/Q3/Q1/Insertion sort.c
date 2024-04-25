//Code for selection sort

#include<stdio.h>
 
int main()
{
    int arr[6] = {12,6,23,4,7,90};
    
 int i, key, j;
   for (i = 1; i < 6; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
       /*if j is grater than 0 and element of array is grater than key then only the program enters in while loop*/
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];//To traverse the elements of array.
           j = j-1;//Insert the next element to the privious element in array.
       }
       /*Once all comparision is done the element is inserted at correct place */
       /*Eg array = [10,40,5,30,15,70]
	*key = 40, now in first iteration the program compares whole arraay with the key and swaps all the lesser elements than 40 to the \
       		lh side and keeps all big elements to rh side
	array = [10,_,_,30,15,70]
	*key = 40   ^ ^   
		 vaccant due to swapping.
	Next step is to insert the key at j+1 place 
	array = [10,5,40,30,15,70]
		    ^  ^
		   Swapped 
	
	* */
       arr[j+1] = key;//Once all the comparision is done then insert the key at place
   }

   //for printing the array
   for(int i=0; i<6;i++){
   	printf("%d\n",arr[i]);

   }// for ends
    return 0;
}
