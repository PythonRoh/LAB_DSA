//sorting algorithms
#include<stdio.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void insertion_sort(int arr[],int size)
{
    int key, j;
    for (int i=1;i<size;i++)
    {
         key=arr[i];
         j=i-1;
        while(key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
            //printf("\n");
        }
        printf("\n");
    }
    
}

void selection_sort(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
        }
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
            //printf("\n");
        }
        printf("\n");
    }
    
}

void bubble_sort(int arr[],int size)
{
    for (int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
        for(int i=0;i<size;i++)
        {
          printf("%d ",arr[i]);
          //printf("\n");
        }
        printf("\n");
    }
    
}

int main()
{
    int arr[]={13,9,2,12,7,64,25};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);
    printf("\n");
     int arr1[]={13,9,2,12,7,64,25};
    bubble_sort(arr1,size);
    printf("\n");
     int arr2[]={13,9,2,12,7,64,25};
    selection_sort(arr2,size);
    printf("\n");


    return 0;
}