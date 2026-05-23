#include<bits/stdc++.h>
using namespace std;

int sch[100010];
int stu[100010];
int m,n;

int ch(int a){
	int l=0,r=m+1;
	while(l<r){
		int mid=(r+l)/2;
		if(sch[mid]<=a){
			l=mid+1;
		}
		else {
			r=mid;
		}
	}
	if(a<=sch[1]){
		return sch[1]-a;
	}
	else {
		return min(abs(sch[l-1]-a),abs(sch[l]-a));
	}
}

int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>sch[i];
	}
	for(int i=1;i<=n;i++){
		cin>>stu[i];
	}
	sort(sch+1,sch+1+m);
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=ch(stu[i]);
	}
	cout<<sum;
	return 0;
}