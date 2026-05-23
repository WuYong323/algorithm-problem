#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m;
vector<int> e[N];
int cundang[105];

int main()
{
    cin>>n>>m;
    int k;
    for(int i=1;i<=n;++i){
        cin>>k;
        int id;
        for(int j=1;j<=k;++j){
            cin>>id;
            e[i].push_back(id);
        }
    }
    int op;
    int position=1;
    for(int i=1;i<=m;++i){
        cin>>op;
        int j;
        if(op==0){
            cin>>j;
            position=e[position][j-1];
        }
        else if(op==1){
            cin>>j;
            cundang[j]=position;
            cout<<position<<endl;
        }
        else if(op==2){
            cin>>j;
            position=cundang[j];
        }
    }
    cout<<position;
    return 0;
}