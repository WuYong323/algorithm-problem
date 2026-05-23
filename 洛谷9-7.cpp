#include<bits/stdc++.h>
using namespace std;

int n;
int lst[15];
int te[15];

void zuhe(int now){
	if(now==n){
		for (int j=1;j<=n;j++) {
			cout<<setw(5)<<lst[j];
		}
		cout<<"\n";
		return;
	}
	for (int i=1;i<=n;i++) {
		if(!te[i]){
			te[i]=1;
			lst[now+1]=i;
			zuhe(now+1);
			te[i]=0;
		}
	}
}

int main()
{
	cin>>n;
	zuhe(0);
	return 0;
}