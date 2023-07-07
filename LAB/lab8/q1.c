#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
// void display(int *A,int n)
// {
//     for(int i=0;i<n;i++){
//         printf("%d ",A[i]);
//     }
//     printf("\n ");
// }
int partition(int A[],int l,int h)
{
    int pivot=A[l];
    int i=l,j=h;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);

         if(i<j)swap(&A[i],&A[j]);
    }while(i<j);

    swap(&A[l],&A[j]);
    return j;
}
void QuickSort(int A[],int l,int h)
{
    int j;

    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
        

    }
}
void display(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n ");
}
int main()
{
    int A[]={8,6,4,2,7,5,3,1},n=8,i;

    QuickSort(A,0,8);
    display(A,n);

    // for(i=0;i<10;i++)
    // printf("%d ",A[i]);
    // printf("\n");

    return 0;
}