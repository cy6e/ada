#include<stdio.h>
#include<time.h>
#include<sys/resource.h>
void siftdown(int a[],int root,int bottom)
{
    int maxchild,temp,done;
    done = 0;
    while((root * 2 <= bottom) && (!done))
    {
        if(root * 2 == bottom)
        maxchild = root * 2;
        else if(a[root * 2] > a[root * 2 + 1])
        maxchild = root * 2;
        else
        maxchild = root * 2 + 1;
    if(a[root]<a[maxchild])
    {
        temp = a[root];
        a[root] = a[maxchild];
        a[maxchild] = temp;
        root = maxchild;
    }
    else
    done = 1;
    }
}
void heapsort(int a[],int n)
{
    int i,temp;
    for(i=n-1;i>=0;i--)
    {
        siftdown(a,i,n - 1);
    }
    for(i=n-1;i>=1;i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        siftdown(a,0,i-1);
    }
}
void main()
{
    int a[50],n,i;
    clock_t st,et;
    double ts;
    struct rusage r_usage;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    printf("Enter the array elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
    }
    st = clock();
    heapsort(a,n);
    et = clock();
    printf("Array elements after sorting: \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("\n");
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Time taken is %f seconds \n",ts);
    printf("Memory used is %ld kilobytes \n",r_usage.ru_maxrss);
}
