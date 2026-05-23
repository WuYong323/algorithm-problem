#include<bits/stdc++.h>
using namespace std;

int n;
char ch;
char ytu[105][105];
char tu[105][105];

int main(){
    cin>>ch>>n;
    char c;
    memset(tu,' ',sizeof(tu));
    getchar();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            c=getchar();
            if(c=='@') {
                tu[n-i+1][n-j+1]=ch;
                ytu[i][j]=ch;
            }
        }
        getchar();
    }
    bool flage=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(ytu[i][j]!=tu[i][j]){
                flage=1;
                break;
            }
        }
    }
    if(!flage){
        cout<<"bu yong dao le"<<endl;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<tu[i][j];
        }
        cout<<endl;
    }
    return 0;
}