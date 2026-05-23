#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,r;
	cin>>n>>r;
	int p=n;
	char lst[100];
	int t=1;
	while(n!=0){
		int m=n%r;
		if(m<0) m-=r,n+=r;
		if(m>=10) m='A'+m-10;
		else m+='0';
		lst[t]=m;
		n/=r;
		t++;
	}
	cout<<p<<"=";
	for(int i=t-1;i>=1;--i){
		cout<<lst[i];
	}
	cout<<"(base"<<r<<")";
	return 0;
}