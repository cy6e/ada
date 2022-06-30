#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>
int a[50],n;
void mergesort(int low,int mid,int high)
{
    int b[50],i,j,k,h;
    i=h=low;
    j=mid+1;
    while(h<=mid&&j<=high)
    {
        if(a[h]<a[j])
        {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k] = b[k];
    }
}
void divide(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        divide(low,mid);
        divide(mid+1,high);
        mergesort(low,mid,high);
    }
}
void main()
{
    int i;
    clock_t st,et;
    double ts;
    struct rusage r_usage;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter the elements to be sorted: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    st = clock();
    divide(1,n);
    et = clock();
    printf("Array elements after merge sort: \n");
    for(i=1;i<=n;i++)
    {
        printf("%d \t",a[i]);
    }
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("\nTime taken is %f seconds \n",ts);
    printf("Memory used is %ld kilobytes \n",r_usage.ru_maxrss);
}
