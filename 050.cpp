#include<bits/stdc++.h>
using namespace std;

int n;
int num;
char str[10];

int main(){
    cin>>n>>num;
    int res=1;
    for(int i=n;i>=1;--i){
        res*=26;
    }
    res-=num;
    for(int i=n;i>=1;--i){
        str[i]=res%26+'a';
        res/=26;
    }
    for(int i=i;i<=n;++i){
        cout<<str[i];
    }
    return 0;
}