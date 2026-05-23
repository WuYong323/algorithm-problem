#include<bits/stdc++.h>
using namespace std;

int n,r;
int lst[100];

void zuhe(int sid,int now){
	if(now==r+1){
		for(int j=1;j<=r;j++)
			cout<<setw(3)<<lst[j];
		cout<<"\n";
		return;
	}
	for (int i=sid;i<=n;i++){
		lst[now]=i;
		zuhe(i+1,now+1);
	}
}

int main()
{
	cin>>n>>r;
	zuhe(1,1);
	return 0;
}