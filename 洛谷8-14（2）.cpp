#include<bits/stdc++.h>
using namespace std;

struct num{
	string a;
};

bool comp(num a,num b){
	int p=min(a.a.size(),b.a.size());
	for (int i=0;i<p;i++) {
		if(a.a[i]!=b.a[i]){
			return a.a[i]>b.a[i];
		}
	}
	if(a.a.size()>b.a.size()){
		return a.a[p]<b.a[0];
	}
	else{
		return b.a[p]<a.a[0];
	}
}

int main()
{
	int n;
	cin>>n;
	num lst[n+1];
	for (int i=1;i<=n;i++) {
		cin>>lst[i].a;
	}
	sort(lst+1,lst+1+n,comp);
	for (int i=1;i<=n;i++) {
		cout<<lst[i].a;
	}
	return 0; 
}