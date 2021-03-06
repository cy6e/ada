#include <string.h>
#include <stdio.h>
#include<time.h>
#include<sys/resource.h>
char str[100],ptn[20];
int res,m,n,len,len1,i,j,k,table[1000];
void main()
{
    clock_t st,et;
    double ts;
    struct rusage r_usage;
    printf("Enter the text \n");
    gets(str);
    printf("Enter the pattern to be found \n");
    gets(ptn);
    st = clock();
    res=horspool(ptn,str);
    et = clock();
    if(res==-1)
    printf("\nPattern not found\n");
    else
    printf("Pattern found at %d position \n",res+1);
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    getrusage(RUSAGE_SELF,&r_usage);
    printf("Time taken is %f seconds \n",ts);
    printf("Memory used is %ld bytes \n",r_usage.ru_maxrss);
}
void shift(char p[])
{
    len=strlen(p);
    for(i=0;i<1000;i++)
    {
        table[i]=len;
    }
    for(j=0;j<=len-2;j++)
    {
        table[p[j]]=len-1-j;
    }

}
int horspool(char p[], char t[])
{
    shift(p);
    m=strlen(p);
    n=strlen(t);
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && (p[m-1-k]==t[i-k]))
        k++;
        if(k==m)
        return i-m+1;
        else
        i=i+table[t[i]];
    }
    return -1;
}
