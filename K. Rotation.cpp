#include<bits/stdc++.h>
#define N 1000005
using namespace std;

int n;
int w[N];
int is[4];
int ans=1e9;

int main()
{
	cin>>n;
    vector<int> cnt(4);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<=3;i++){
        int x=cnt[(i+1)%4]+cnt[(i+3)%4]+2*(cnt[(i+2)%4]+cnt[(i+3)%4]);
        int id=(x+i)%4;
        ans=min(ans,x+(4-id)%4);
    }
    cout<<ans;
	return 0;
}