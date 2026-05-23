#include<bits/stdc++.h>
using namespace std;

int l,n,k;
int lst[100010];

bool tel(int a){
	int sum=0;
	for(int i=2;i<=n;i++){
		int p=1;
		while(lst[i]-lst[i-1]>a*p){
			p++;
		}
		sum+=p-1;
	}
	return sum<=k;
}

int main()
{
	cin>>l>>n>>k;
	int z=0;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
		z=max(z,lst[i]);
	}
	int left=1,right=z;
	int t=1e9;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(tel(mid)){
			t=min(t,mid);
			right=mid-1;
		}
		else {
			left=mid+1;
		}
	}
	cout<<t;
	return 0;
}