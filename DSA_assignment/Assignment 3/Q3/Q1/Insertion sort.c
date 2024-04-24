//Code for insertion sort
#include <stdio.h>

int main()
{
    int arr[6] ={20,15,2,7,10}; 
    int j;
    
    int target;
    for(int i = 0; i<6;i++){
        target = arr[i];
        j = 1-i;
        while(j>0 && arr[i]>target){
            arr[j+1] = arr[j];
            j = j-1;
        }//while ends
        arr[j+1] = target;
    }//for ends

//to print the array.
for(int k = 0; k<6; k++){
    printf("\t%d", arr[k]);
}//for ends
    return 0;
}
