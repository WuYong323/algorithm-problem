#include<bits/stdc++.h>
using namespace std;

double w0,w,m;

void fun(double l,double r){
	double k=(l+r)/2,ji=r-l;
	double a=w0;
	if(ji<0.0001){
		printf("%.1f",k*100);
		return;
	}
	for(int i=1;i<=m;i++){
		a=a*(1+k)-w;
	}
	if(a>0) fun(l,k);
	if(a<0) fun(k,r);
	if(a==0) {
		printf("%.1f",k*100);
		return;
	}
}

int main()
{
	cin>>w0>>w>>m;
	fun(0,5);
	return 0;
}