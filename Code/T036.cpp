#include<stdio.h>
#define inf 10000
int main()
{
    int e[100][100];
    int i,j,k,n,m,a,b,v;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&e[i][j]);
    scanf("%d",&m);
        for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(e[i][j]>e[i][k]+e[k][j])
                e[i][j]=e[i][k]+e[k][j];
    for(v=0;v<m;v++)
        {
   scanf("%d%d",&a,&b);


            printf("%d\n",e[a][b]);
    }
    return 0;
}