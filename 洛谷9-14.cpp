#include<bits/stdc++.h>
#define ll long long
using namespace std;

int lst[11][3];
ll xiao=1e9;
int n;

void sousuo(int index,ll ji,ll he,bool select){
	if(index>n){
		if(select){
			xiao=min(xiao,abs(ji-he));
		}
		return;
	}
	sousuo(index+1,ji,he,select);
	sousuo(index+1,ji*lst[index][1],he+lst[index][2],true);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lst[i][1]>>lst[i][2];
	}
	sousuo(1,1,0,false);
	cout<<xiao;
	return 0;
}