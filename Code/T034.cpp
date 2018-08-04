#include<stdio.h>  
  
int n;  
int matr[30][30],ans[30];  
  
void init(){  
     int i,j;  
     scanf("%d", &n);  
     for(i = 0; i < n; i++){  
         for(j = 0; j < n; j++){  
             scanf("%d", &matr[i][j]);  
         }  
     }  
}  
  
void search(){  
    int i, j, k, tmp[30][30], min, v;  
    bool final[30];  
    for(i = 0; i < n; i++){  
        final[i] = false;  
        ans[i] = matr[0][i];  
        for(j = 0; j < n; j++){  
             tmp[i][j] = -1;  
             if(ans[i] < 10000){  
                 tmp[i][0] = 0;  
                 tmp[i][1] = i;  
             }  
        }  
    }  
  
    ans[0] = 0;  
    final[0] = true;  
  
    for(i = 1; i < n; i++){  
        min = 10000;  
        for(j = 0; j <n ; j++){  
            if(!final[j] && ans[j]<min){  
                 v=j;  
                 min = ans[j];  
            }  
        }  
        final[v] = true;  
        for(j = 0; j < n; j++){  
             if(!final[j] && min<10000 && matr[v][j]<10000&& (min+matr[v][j]<ans[j])) {  
                ans[j]=min+matr[v][j];  
                for(k = 0;  k < n; k++) {  
                    tmp[j][k]=tmp[v][k];  
                    if(tmp[j][k]==-1) {  
                        tmp[j][k]=j;  
                        break;  
                    }  
                }   
             }  
        }  
    }   
}  
  
void output(){  
     int i;  
     for(i = 0; i < n; i++){  
          printf("%d\n",ans[i]);  
     }  
}  
  
int main(){  
    init();  
    search();  
    output();  
    return 0;  
} 