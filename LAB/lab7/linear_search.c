#include<stdio.h>
#include<stdlib.h>
void linear_search(int arr[],int size,int key)
{
    int flag=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            printf("%d",i);
            break;
        }
        
    }
    if (flag==0)
    {
        printf("NOT FOUND");
    }
}

int recursive_linear_seach(int arr[],int index,int key)
{
    if(index<0)
        return -1;
    if(arr[index]==key)
        return index;
    return recursive_linear_seach(arr,index-1,key);
}
int main()
{
    int arr[]={2,7,9,12,13,25,64};
    int a[]={2,7,9,12,13,25,64};
    int size = sizeof(arr)/sizeof(arr[0]);
    linear_search(arr,size,13);
    printf("\n");
   int y = recursive_linear_seach(a,size,13);
   printf("%d ",y);

    return 0;
}