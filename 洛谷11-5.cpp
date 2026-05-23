#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	cin>>n>>x;
	int lst[n+5];
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	for(int i=1;i<(n+1)/2;i++){
		if(lst[i]+lst[i+1]<=x){
			continue;
		}
		sum+=lst[i]+lst[i+1]-x;
		if(0>=lst[i+1]-(lst[i]+lst[i+1]-x)){
			lst[i+1]=0;
		}
		else{
			lst[i+1]=lst[i+1]-(lst[i]+lst[i+1]-x);
		}
	}
	for(int i=n;i>(n+1)/2;i--){
		if(lst[i]+lst[i-1]<=x){
			continue;
		}
		sum+=lst[i]+lst[i-1]-x;
		if(0>=lst[i-1]-(lst[i]+lst[i-1]-x)){
			lst[i-1]=0;
		}
		else{
			lst[i-1]=lst[i-1]-(lst[i-1]+lst[i]-x);
		}
	}
	if(n%2==0&&lst[n/2]+lst[n/2+1]>x){
		sum+=lst[n/2]+lst[n/2+1]-x;
	}
	cout<<sum;
	return 0;
}