#include<stdio.h>
#include<stdbool.h>

void quick_sort(int [], int, int);
int partition(int [],int , int , int);

int main()
{
    int arr[6] ={20,60,4,10,50,90}; 
    quick_sort(arr,0,5);
    printf("\nIn main\n");
  for (int i = 0; i < 6; i++)
        {
            printf("\t%d", arr[i]);
        }//for ends.    
}// main ends

void quick_sort(int arr[], int left, int right)
{
    //if the right & left crosses eachother then stop the recursion.
    if (right-left<=0)
    {
        return;
    }//if ends
    
    
        int part;
        int pivot = right;
        part = partition(arr,left,right,pivot);
        quick_sort(arr, left,part-1);// to sort in left sub array
        quick_sort(arr,part+1,right);//to sort in right sub array
    
}// quick sort ends

int partition(int arr[],int left, int right, int pivot)
{
    int lh_index = left;//local var to left side of array
    int rh_index = right-1;// taking local var to right side of array.

    while(lh_index<=rh_index){
        /*Now get the lest element from left side*/
        while (arr[lh_index]<arr[pivot] && lh_index<=rh_index)
        {
            lh_index++;
        }//while ends
        if(lh_index >rh_index){
            break;
        }//if ends
        /*Now get the highest element from RH side*/
        while (arr[rh_index]>arr[pivot] && lh_index<=rh_index)
        {
            rh_index--;
        }//while ends

        /*Now if we go on incrimenting the lh index & it passes the rh index then we have to breake the loop*/
        if(lh_index >rh_index){
            break;
        }//if ends
          
        /*Eles if the index is not crossed then swapp highest and lowest element than pivot so as to get the 
        lower elements at the LH side & the higher elements at the RH side of pivot  the elements.*/
        
            printf("\nSwapping %d & %d", arr[lh_index], arr[rh_index]);
          //  swap(&arr[lh_index],&arr[rh_index]);
            arr[lh_index] = arr[lh_index]^arr[rh_index];
            arr[rh_index] = arr[lh_index]^arr[rh_index];
            arr[lh_index] = arr[lh_index]^arr[rh_index];
        //else ends    
	}//while ends
	//swap(&arr[pivot],&arr[lh_index]);
	arr[pivot] = arr[pivot]^arr[lh_index];
        arr[lh_index] = arr[pivot]^arr[lh_index];
        arr[pivot] = arr[pivot]^arr[lh_index];
        
        printf("\n\nUpdated array: ");
        for (int i = 0; i < 6; i++)
        {
            printf("\t%d", arr[i]);
        }//for ends.
        return lh_index;
}//partition ends

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
