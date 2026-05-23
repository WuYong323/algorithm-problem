#include<bits/stdc++.h>
using namespace std;

int n;
double z,r;
vector<int> dizi[100005];
double deliver[100005];
double sum;

void bfs(int s){
    queue<int> q;
    q.push(s);
    deliver[s]=z;
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int x:dizi[t]){
            if(x>=n) sum+=deliver[t]*(x-n);
            else{
                deliver[x]=deliver[t]*(1-r/100);
                q.push(x);
            }
        }
    }
}

int main()
{
    cin>>n>>z>>r;
    int num,id;
    for(int i=0;i<n;++i){
        cin>>num;
        if(num!=0){
            for(int j=1;j<=num;++j){
                cin>>id;
                dizi[i].push_back(id);
            }
        }
        else{
            cin>>id;
            dizi[i].push_back(id+n);
        }
    }
    bfs(0);
    printf("%.0f",sum);
    return 0;
}