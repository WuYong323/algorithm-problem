#include<bits/stdc++.h>
using namespace std;

int num[10];
char ch;

int main()
{
    while(ch=getchar()){
        num[ch-'0']++;
    }
    for(int i=0;i<=9;++i){
        if(num[i]){
            printf("%d:%d\n",i,num[i]);
        }
    }
    return 0;
}