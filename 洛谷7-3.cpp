#include<bits/stdc++.h>
using namespace std;

char lst[1000000][15];
int point[1000000];
int main()
{
	long long n,m;
	scanf("%lld %lld",&n,&m);
	int lr;
	long long num;
	for (long long i=1;i<=n;i++) {
		cin>>point[i]>>lst[i];
	}
	long long t=1;
	for (long long i=0;i<m;i++) {
		cin>>lr>>num;
		if(point[t]==0 && lr==1 || point[t]==1 && lr==0) {
			t+=num;
		}
		else if(point[t]==0 && lr==0 || point[t]==1 && lr==1) {
			t-=num;
		}
		if (t/(n+1)==1) {
			t-=n;
		}
		if (t<=0) {
			t=n+t;
		}
	}
	cout<<lst[t];
	return 0;
}