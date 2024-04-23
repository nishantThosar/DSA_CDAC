//Selection sort

/*In selection sort first the least element is found  and then swapped it with the current element of comparision.*/

#include<stdio.h>
int main()
{
	int temp,j,i, ind;
	int arr[6] = {10,20,1,5,15,40};
	for(int z = 0; z<6; z++){
		printf("\t%d", arr[z]);
	}

	for( i = 0; i<(sizeof(arr)/sizeof(arr[0])); i++){
		ind = i; // Here i=0 in first iteration and we are assigning to insex variable.
		
		
		for( j=i+1; j<(sizeof(arr)/sizeof(arr[0]));j++){

			if(arr[j]<arr[ind]){// here the 0th index(10) is compared with whole array first & if smaller value is found then the index is updated.
				ind = j;
				printf("\tj = %d", j);

			}//if ends
		}//inner for ends
		
			temp = arr[ind];
			arr[ind] = arr[i];
			arr[i] = temp;
		
	}//outer for ends

	printf("\n");
	for(int k = 0; k<6; k++){
		printf("%d\t", arr[k]);
	}
}// main ends
