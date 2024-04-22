/*
Q3. Write C/C++ prgram which allocate and deallocate memory
dynamically.
(a) Allocating 1D array dynamically and access the elements
(b) Allocating 2D array dynamically
(1) contiguous rows with fixed no.of cols,
(2) Non contiguous rows with variable no.of columns
(c) Allocate memory for array of structure variables dynamically and
access members of each element
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
	  
	int *ptr;
	
	ptr=(int *)malloc(sizeof(ptr)*4);
	
	ptr[0]=100;
	
	//(a) Allocating 1D array dynamically and access the elements
	printf("ptr[0]%d\n",ptr[0]); //Accessing the static array
	
	free(ptr);//freeing the pointer after malloc
	
	//(b) Allocating 2D array dynamically
	//(1) contiguous rows with fixed no.of cols,
	//(2) Non contiguous rows with variable no.of columns
	
	
	int (*arr1)[3];//pointer to an array
	int *arr2[3];//array pointer for saving pointers to elements which will be allocated in heap.
	
	arr1=(int (*)[])malloc(48);//making the array in heap.
	
	//Allocating 3 int on heap & saving the pointer to them in the array2.
	for(int i=0;i<3;i++){
		arr2[i]=(int *)malloc(sizeof(int)*3);
	}
	//Accessing the non contageous array.
	arr1[0][0]=1;
	arr1[1][0]=2;
	arr1[2][0]=3;
	
	arr2[0][0]=10;
	arr2[1][0]=20;
	arr2[2][0]=30;
	
	//Printing the non-contageous array
	printf("arr1[0][0]=%d \narr1[1][0]=%d \narr1[2][0]=%d \n*arr2[0][0]=%d \n*arr2[1][0]=%d \n*arr2[2][0]=%d \n",arr1[0][0], arr1[1][0],arr1[2][0],arr2[0][0],arr2[1][0],arr2[2][0]);
	
	
	free(arr1);// need to free the pointer assigned for malloc
	
	
	for(int i=0;i<3;i++)
	free(arr2[i]);
	
	//(c) Allocate memory for array of structure variables dynamically and
	//access members of each element
	
	struct data *p;
	
	p=(struct data *)malloc(sizeof(struct data)*3);
	
	p[0].var=11;
	p[1].var=22;
	p[2].var=33;
	
	printf("p[0].var=%d\np[1].var=%d\np[2].var=%d\n",p[0].var,p[1].var,p[2].var);
	
	
	free(p);
	
	
}
	
