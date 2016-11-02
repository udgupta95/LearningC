/* The task is to complete insert() which is used 
   as shown below to implement insertionSort() */

/* Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
} */

void insert(int arr[], int i)
{
    int index,key,j;
    for(index=1;index<i;index++)
    {
        key = arr[index];
        j = index - 1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
