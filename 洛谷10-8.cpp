#include<bits/stdc++.h>
using namespace std;

int lst[110];
int ans=0;
int n,m;

void digui(int index,int sum){
	if(sum==m){
		ans++;
		return;
	}
	else if(sum>m||index>n){
		return;
	}
	int p=0;
	for(int i=index;i<=n;i++){
		p+=lst[i];
	}
	if(sum+p<m){
		return;
	}
	digui(index+1,sum+lst[index]);
	digui(index+1,sum);
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	sort(lst+1,lst+1+n);
	digui(1,0);
	cout<<ans;
	return 0;
}