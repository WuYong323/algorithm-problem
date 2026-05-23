#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin>>t;
	int n,k;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int lst[n+5];
		for(int j=1;j<=n;j++){
			cin>>lst[j];
		}
		int sum=0;
		for(int p=1;p<=n;p++){
			if(lst[p]==1){
				sum++;
			}
		}
		int z;
		
		if(k<=n-sum){
			z=0;
		}
		int low=max((k+1)/2,k-(n-sum));
		low=max(low,1);
		int h=min(n-sum,k);
		if(low<=h){
			z=0;
		}
		if(z!=0){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}