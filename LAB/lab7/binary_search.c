#include<stdio.h>
#include<stdlib.h>

int recur(int a[],int l,int r,int x)
{
    if(l>r)
    return -1;
    int m=(l+r)/2;
    if(a[m]==x)
    return m;
    else if(a[m]<x)
    l=m+1;
    else
    r=m-1;
    return recur(a,l,r,x);
}
int iterate(int a[],int l,int r,int x)
{
    int idx,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a[m]==x)
        return m;
        else if(a[m]<x)
        l=m+1;
        else
        r=m-1;
    }
    return -1;
}
int main()
{
    int a[]={2,7, 9, 12, 13, 25, 64};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Recursion %d \n",recur(a,0,6,13));
    printf("Iterative %d ",iterate(a,0,6,13));
    return 0;
}