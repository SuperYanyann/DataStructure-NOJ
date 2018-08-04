#include <stdio.h>  
typedef struct {  
    int vexs[20];  
    int arcs[20][20];  
    int vexnum,arcnum;  
}MGraph;  
typedef int sumlength[20];   
int Locate(MGraph * G,int v)  
{  
    int i=0;  
    for (i=0;i<G->vexnum; i++)  
    {  
        if (G->vexs[i]==v)  
        {  
            break;  
        }  
    }  
    if (i>G->vexnum) {  
        return -1;  
    }  
    return i;  
}  
void creat(MGraph *G)  
{   int i,j;  
    scanf("%d%d",&(G->vexnum),&(G->arcnum));  
    for (i=0; i<G->vexnum; i++)  
        {  
        G->vexs[i]=i+1;  
        }  
    for (i=0; i<G->vexnum; i++)   
    {  
        for ( j=0; j<G->vexnum; j++)  
        {  
            G->arcs[i][j]=65535;  
        }  
    }  
    for ( i=0;i<G->arcnum;i++)  
    {  
        int v1,v2,w;  
        scanf("%d%d%d",&v1,&v2,&w);  
        int n=Locate(G, v1);  
        int m=Locate(G, v2);  
        if (m==-1 ||n==-1)  
        {  
            printf("no this vertex\n");  
            return;  
        }  
        G->arcs[n][m]=w;  
    }  
}  
void zuiduanlu(MGraph G,int v0,sumlength *D)  
{  
    int final[20];  
    int i,v;  
    for (v=0; v<G.vexnum; v++)  
    {  
        final[v]=0;  
        (*D)[v]=G.arcs[v0][v];  
    }  
    (*D)[v0]=0;  
    final[v0]=1;  
    int k = 0;  
    int w;  
    for(i=1;i<G.vexnum;i++)  
    {  
        int min=65535;  
        for (w=0; w<G.vexnum; w++)  
        {  
            if (!final[w])  
            {  
                if ((*D)[w]<min)  
                {  
                    k=w;  
                    min=(*D)[w];  
                }  
            }  
        }  
        final[k]=1;  
        for ( w=0; w<G.vexnum; w++)  
        {  
            if (!final[w]&&(min+G.arcs[k][w]<(*D)[w]))  
            {  
                (*D)[w]=min+G.arcs[k][w];  
  
            }  
        }  
    }  
}  
int main(){  
    MGraph G;  
    creat(&G);  
    sumlength D;  
    int i,j,t,temp;  
    zuiduanlu(G, 0,&D);  
    for ( i=1; i<G.vexnum; i++)  
    {  
      for(j=1;j<G.vexnum-i;j++)  
      {  
          if(D[j]>D[j+1])  
          {  
          temp=D[j];  
          D[j]=D[j+1];  
          D[j+1]=temp;  
          t=G.vexs[j];  
          G.vexs[j]=G.vexs[j+1];  
          G.vexs[j+1]=t;  
          }  
      }  
    }  
    for ( i=1; i<G.vexnum; i++)  
    {   if(D[i]!=65535)  
       {  
        printf("%d %d %d \n",G.vexs[0],G.vexs[i],D[i]);  
       }  
       else  
       {  
           printf("%d %d -1 \n",G.vexs[0],G.vexs[i]);  
       }  
    }  
    return 0;  
} 