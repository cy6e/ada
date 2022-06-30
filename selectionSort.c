#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>
int a[100],n,min,temp,i,j;
void selectionsort(int a[],int n)
{
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
void main()
{
    struct rusage r_usage;
    clock_t st,et;
    double ts;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    st = clock();
    selectionsort(a,n);
    et = clock();
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Array elements after sorting: \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("\nTime taken is %f seconds \n",ts);
    printf("Memory used is %ld kilobytes \n",r_usage.ru_maxrss);
}
