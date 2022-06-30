#include<stdio.h>
#include<time.h>
#include<sys/resource.h>
int a[20][20],i,j,n,visited[20],count=0;
void dfs(int v)
{
    count++;
    visited[v]=count;
    if(visited[v]!=0)
    {
        printf("%d -> ",v);
    }
    for(i=1;i<=n;i++)
    {
        if(a[v][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }
}
void main()
{
    int v;
    clock_t st,et;
    double ts;
    struct rusage r_usage;
    printf("Enter the number of vertices: \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    printf("Enter adjacency matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex: \n");
    scanf("%d",&v);
    visited[v]=1;
    printf("DFS traversal is: \n");
    st = clock();
    dfs(v);
    et = clock();
    if(count==n)
    {
        printf("\nGraph is connected \n");
    }
    else
    {
        printf("\nGraph is not connected \n");
    }
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Time taken is %f seconds \n",ts);
    printf("Memory used is %ld kilobytes \n",r_usage.ru_maxrss);
}

