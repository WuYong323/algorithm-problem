#include<bits/stdc++.h>
using namespace std;

int m,n;
int lst[501];

struct all{
	int id;
    int cost;
}a[21][21];

int tt[21][100001];
int step[21];
int last[21];
int ans;

int main()
{
	cin>>m>>n;
    for(int i=1;i<=m*n;i++) {
        cin>>lst[i];
    }
    for(int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j].id;
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j].cost;
        }
    }
    for(int i=1;i<=m*n;i++) {
        int now=lst[i];
        step[now]++;
        int id=a[now][step[now]].id,cost=a[now][step[now]].cost;
        int s=0;
        for (int j=last[now]+1; ;j++){
            if (tt[id][j]==0){
                s++;
            } else{
                s=0;
            }
            if (s==cost) {
                for(int k=j-cost+1;k<=j;k++){
                    tt[id][k]=1;
                }
                if (j>ans)ans=j;
                last[now]=j;
                break;
            }
        }
    }
    cout<<ans;
	return 0;
}