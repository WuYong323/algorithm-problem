#include<bits/stdc++.h>
using namespace std;

int n;
char ch;

int main()
{
    cin>>n>>ch;
    int t;
    if(n%2) t=n/2;
    else t=n/2+1;
    for(int i=1;i<=t;++i){
        for(int j=1;j<=n;++i){
            cout<<ch;
        }
        cout<<endl;
    }
    return 0;
}