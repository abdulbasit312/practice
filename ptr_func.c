#include<stdio.h>
#include<stdlib.h>
#define max 10
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void display(int*);
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
void fillandsort(void (*func)(int*,int,int),int arr[])
{
	int i;
	for(i=0;i<10;i++)
		arr[i]=rand();
	display(arr);
	(*func)(arr,0,9);
}
void display(int arr[])
{
	int i;
	for(i=0;i<max;i++)
	{
		printf("\n%d",arr[i]);
	}
	printf("\n***********************");
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
main()
{
	int arr[max];
	fillandsort(quickSort,arr);
	display(arr);
}
