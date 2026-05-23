#include<bits/stdc++.h>
using namespace std;

int n;
char str[20005];

int main()
{
    cin>>n;
    getchar();
    cin.getline(str,10000);
    int t=strlen(str);
    for(int i=1;i<=n;++i){
        for(int j=(t/n)*n+i-1;j>=0;j-=n){
            cout<<str[j];
        }
        cout<<endl;
    }
    return 0;
}