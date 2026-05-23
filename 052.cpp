#include<bits/stdc++.h>
using namespace std;

int n;
char ch;
char tu[105][105];

int main(){
    cin>>ch>>n;
    char c;
    memset(tu,' ',sizeof(tu));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>c;
            if(c=='@') tu[i][n-j]=ch;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<tu[i][j];
        }
        cout<<endl;
    }
    return 0;
}