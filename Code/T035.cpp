#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <stack>  
#include <stdlib.h>  
using namespace std;  
      
const int maxnum = 130;  
const int maxint = 10000;  
      
void Dijkstra(int n, int v, int *dist, int *prev, int matrix[maxnum][maxnum])  
{  
    bool visited[maxnum];  
    int i, j;  
    for(i = 1; i <= n; i++)  
    {  
        dist[i] = matrix[v][i];  
        visited[i] = 0;  
        if(dist[i] == maxint)  
            prev[i] = 0;  
        else  
            prev[i] = v;  
    }  
          
    dist[v] = 0;  
    visited[v] = 1;  
      
    for(i = 2; i <= n; i ++)  
    {  
        int temp = maxint;  
        int u;  
      
        for(j = 1; j <= n; j++)  
        {  
            if((visited[j]==0)&&(dist[j]<temp))  
            {  
                u = j;  
                temp = dist[j];  
            }  
        }  
        visited[u] = 1;  
      
        for(j = 1; j <= n; j++)  
        {  
            if((visited[j]==0)&&(matrix[u][j]<maxint))  
            {  
                int newdist = dist[u]+matrix[u][j];  
                if(newdist<dist[j])  
                {  
                    dist[j] = newdist;  
                    prev[j] = u;  
                }  
            }  
        }  
    }  
      
    }  
      
      
    void searchPath(int *prev, int u, int v)  
    {  
        stack<int>s;  
        while(v!=u)  
        {  
            s.push(v);  
            v = prev[v];  
        }  
        s.push(v);  
        while(!s.empty())  
        {  
            cout << s.top()-1 << endl;  
            s.pop();  
        }  
    }  
      
    int main()  
    {  
        int dist[maxnum];  
        int prev[maxnum];  
        int matrix[maxnum][maxnum];  
        int n;  
      
        cin >> n;  
        int i, j;  
        for(i = 1; i <= n; i++)  
        {  
            for(j = 1; j <= n; j ++)  
            {  
                cin >> matrix[i][j];  
            }  
        }  
        int x, y;  
        cin >> x >> y;  
      
        Dijkstra(n, x+1, dist, prev, matrix);  
        searchPath(prev, x+1, y+1);  
    }  