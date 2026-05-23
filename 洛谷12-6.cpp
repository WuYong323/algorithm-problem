#include<bits/stdc++.h>
using namespace std;

int lst[100010];
int n,k;

int tel(int a){
	int ans=0;
	for(int i=n;i>=1;i--){
		if(a<lst[i]){
			ans+=lst[i]/a;
		}
		else{
			break;
		}
	}
	if(ans==k){
		return 0;
	}
	else if(ans>k){
		return -1;
	}
	else {
		return 1;
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&lst[i]);
		sum+=lst[i];
	}
	sum/=k;
	sort(lst+1,lst+1+n);
	if(sum==0){
		cout<<0;
		return 0;
	}
	int p;
	int l=1,r=sum;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(tel(mid)==0){
			p=mid;
			break;
		}
		else if(tel(mid)==-1){
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	while(tel(p)==0){
		p++;
	}
	cout<<p-1;
	return 0;
}