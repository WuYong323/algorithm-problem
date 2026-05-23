#include<bits/stdc++.h>
using namespace std;

int n,k;
int lst[25];
int ans;

bool zhishu(int a){
	if(a<=1){
		return 0;
	}
	for (int i=2;i*i<=a;i++) {
		if(a%i==0) {
			return 0;
		}
	}
	return 1;
}

void dfs(int now, int sum, int sid) {
	if (now == k) {
		if (zhishu(sum))
			++ans;
		return ;
	}
	for (int i = sid; i <= n - k + now + 1; ++i)
		dfs(now + 1, sum + lst[i], i + 1);
	return ;
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
	}
	dfs(0, 0, 1);
	printf("%d\n", ans);
	return 0;
}