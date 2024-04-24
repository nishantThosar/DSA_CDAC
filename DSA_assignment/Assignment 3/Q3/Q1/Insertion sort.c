//Code for selection sort

 
int main()
{
    int arr[6] = {12,6,23,4,7,90};
    
 int i, key, j;
   for (i = 1; i < 6; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
    return 0;
}
