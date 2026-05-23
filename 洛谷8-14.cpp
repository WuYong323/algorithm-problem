#include<bits/stdc++.h>
using namespace std;

struct num{
	char a[11];
};

bool comp(num a,num b){
	for (int i=1;i<=11;i++) {
		if(a.a[i]!=b.a[i]){
			return a.a[i]>b.a[i];
	}
	return false;
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