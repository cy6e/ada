#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>
int a[20][20],q[20],visited[20],i,j,n,f=0,r=-1;
void bfs(int v)
{
    for(i=1;i<=n;i++)
    {
        if(a[v][i]!=0 && visited[i]==0)
        {
            q[++r]=i;
        }
    }
    if(f<=r)
    {
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
void main()
{
    int v;
    clock_t st,et;
    double ts;
    struct rusage r_usage;
    printf("Enter number of vertices: \n");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
        q[i]=0;
    }
    printf("Enter graph data in matrix form: \n");
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
    st = clock();
    bfs(v);
    et = clock(); 
    printf("The BFS traversal is: \n");
    for(i=1;i<=n;i++)
    {
        if(visited[i]!=0)
        {
            printf("%d \t",i);
        }
        printf("\n");
    }
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Time taken is %f seconds \n",ts);
    printf("Memory used is %ld kilobytes \n",r_usage.ru_maxrss);
}

