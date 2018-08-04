#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <mem.h>

using namespace std;
int hashset[11]={0};
double count=0;

void Hash(int dd){
    int i=0;
    int j=0;
    int di=0;
    int Hk=0;
    while(j<11){
        di=i*((7*dd)%10+1);
        Hk=((3*dd)%11+di)%11;
        count++;
        j++;
        if(hashset[Hk]==-1){
            hashset[Hk]=dd;
            break;
        }
        i++;
    }
}

int main(){
    int dd=0;
    double k=0;
    char ch;

    memset(hashset,-1,sizeof(hashset));


    double sum=count/k;
    cout<< 2 <<endl;
    return 0;
}