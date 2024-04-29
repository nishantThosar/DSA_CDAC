#include<stdio.h>
#include<stdbool.h>

void quick_sort(int [], int, int);
int partition(int [],int , int , int);

int main()
{
    int arr[6] ={20,60,4,10,50}; 
    quick_sort(arr,5,0);
}// main ends

void quick_sort(int arr[], int right, int left)
{
    //if the right & left crosses eachother then stop the recursion.
    if (right-left<=0)
    {
        return;
    }//if ends
    else
    {
        int part;
        int pivot = arr[right];
        part = partition(arr,left,right,pivot);
        quick_sort(arr, part-1, left);// to sort in left sub array
        quick_sort(arr, part+1, right);//to sort in right sub array
    }//else ends
    
    

}// quick sort ends

int partition(int arr[],int left, int right, int pivot)
{
    int lh_index = left-1;//local var to left side of array
    int rh_index = right;// taking local var to right side of array.

    while(true){
        /*Now get the lest element from left side*/
        while (arr[lh_index]<pivot)
        {
            ++lh_index;
        }//while ends
        /*Now get the highest element from RH side*/
        while (arr[rh_index]>pivot)
        {
            ++rh_index;
        }//while ends

        /*Now if we go on incrimenting the lh index & it passes the rh index then we have to breake the loop*/
        if(lh_index >=rh_index){
            break;
        }//if ends
        /*Eles if the index is not crossed then swapp highest and lowest element than pivot so as to get the 
        lower elements at the LH side & the higher elements at the RH side of pivot  the elements.*/
        else
        {
            printf("\nSwapping %d & %d", arr[lh_index], arr[rh_index]);
            
            arr[lh_index] = arr[lh_index]^arr[rh_index];
            arr[rh_index] = arr[lh_index]^arr[rh_index];
            arr[lh_index] = arr[lh_index]^arr[rh_index];
        }//else ends    

        printf("\n\nUpdated array: ");
        for (int i = 0; i < 6; i++)
        {
            printf("\t%d", arr[i]);
        }//for ends.
        return lh_index;
    }//while ends



}//partition ends