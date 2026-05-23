#include<bits/stdc++.h>
#define int long long
#define N 20005
using namespace std;

struct milk{
	int v;
	int x;
	bool operator<(const milk &t){
		return v<t.v;
	}
}m[N];

int n;
int cnt[N];
int sum[N];
int ans;

int lowbit(int x){
	return x&-x;
}

void change_cnt(int x,int k){
	while(x<=20000){
		cnt[x]+=k;
		x+=lowbit(x);
	}
}

void change_sum(int x,int k){
	while(x<=20000){
		sum[x]+=k;
		x+=lowbit(x);
	}
}

int query_cnt(int x){
	int t=0;
	while(x>0){
		t+=cnt[x];
		x-=lowbit(x);
	}
	return t;
}

int query_sum(int x){
	int t=0;
	while(x>0){
		t+=sum[x];
		x-=lowbit(x);
	}
	return t;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>m[i].v>>m[i].x;
	}
	sort(m+1,m+1+n);
	for(int i=1;i<=n;++i){
		int x=m[i].x;
		int v=m[i].v;
		int left_cnt=query_cnt(x);
		int left_sum=query_sum(x);
		int total_cnt=i-1;
		int total_sum=query_sum(20000);
		
		int right_cnt=total_cnt-left_cnt;
		int right_sum=total_sum-left_sum;
		
		int left_cost=left_cnt*x-left_sum;
		int right_cost=right_sum-right_cnt*x;
		ans+=v*(left_cost+right_cost);
		change_cnt(x,1);
		change_sum(x,x);
	}
	cout<<ans;
}