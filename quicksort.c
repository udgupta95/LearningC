#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot;
   int i = low-1,j = low;
   pivot = arr[high];
   while(j<=high -1)
   {
       if(arr[j] <= pivot)
       {
           i++;
           swap(&arr[i],&arr[j]);
       }
       j++;
   }
   swap(&arr[i+1],&arr[high]);
   return i+1;
   
}





void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
    


int main() {
    
    int arr[] = {5,4,3,2,1};
    quickSort(arr,0,4);
    int i;
    for(i=0;i<5;i++){
        cout << arr[i];
    }
	// your code goes here
	return 0;
}

