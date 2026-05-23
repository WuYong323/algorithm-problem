#include<bits/stdc++.h>
using namespace std;

struct obj{
	int val;
	int m;
	double rate;
};

bool comp(obj a,obj b){
	return a.rate>=b.rate;
}

int main()
{
	int n,t;
	int sum=0;
	double ans=0.0;
	cin>>n>>t;
	obj obj1[105];
	for(int i=1;i<=n;i++){
		cin>>obj1[i].m>>obj1[i].val;
		obj1[i].rate=(double)obj1[i].val/obj1[i].m;
	}
	sort(obj1+1,obj1+1+n,comp);
	for(int i=1;i<=n;i++){
		if(sum+obj1[i].m<=t){
			sum+=obj1[i].m;
			ans+=obj1[i].val;
		}
		else{
			ans+=(t-sum)*obj1[i].rate;
			break;
		}
	}
	if(n==0)cout<<0.00;
	else printf("%.2f",ans);
	return 0;
}