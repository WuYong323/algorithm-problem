#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char a[100];
	sprintf(a,"%08x",n);
	long long sum=0;
	for(int i=4;i<=7;++i){
		if(a[i]>='0'&&a[i]<='9') sum=sum*16+a[i]-'0';
		else sum=sum*16+a[i]-'a'+10;
	}
	for(int i=0;i<=3;++i){
		if(a[i]>='0'&&a[i]<='9') sum=sum*16+a[i]-'0';
		else sum=sum*16+a[i]-'a'+10;
	}
	cout<<sum;
	return 0;
}