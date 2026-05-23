#include<bits/stdc++.h>
using namespace std;

int n;
int lst[35][35];
int lx[]={0,0,1,-1};
int ly[]={1,-1,0,0};

void dfs(int x,int y){
    if(x<1||x>n||y<1||y>n) return;
    if(lst[x][y]!=0) return;
    lst[x][y] = 2;
    for(int i=0;i<4;i++){
        int xx=x+lx[i];
        int yy=y+ly[i];
        dfs(xx,yy);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>lst[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(lst[1][i]==0) dfs(1,i);
        if(lst[n][i]==0) dfs(n,i);
        if(lst[i][1]==0) dfs(i,1);
        if(lst[i][n]==0) dfs(i,n);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(lst[i][j] == 0){
                cout<<2<<" ";
            }else if(lst[i][j] == 2){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}