#include<bits/stdc++.h>
using namespace std;

void qs(int lst[],int l,int r){
	if(l>=r) return;
	int i=l;
	int j=r;
	int mid=(l+r)/2;
	int p=lst[mid];
	while (i<=j) {
		while (lst[i]<p) i++;
		while (lst[j]>p) j--;
		if(i<=j){
			swap(lst[i],lst[j]);
			i++;
			j--;
		}
	}
	if(l<j) qs(lst,l,j);
	if(r>i) qs(lst,i,r);
}

int main()
{
	int n;
	int p=1;
	cin>>n;
	int lst[n+1],lst1[n+1];
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
	}
	qs(lst,1,n);
	for (int i=1;i<=n;i++) {
		if(lst[i]!=lst[i+1]){
			lst1[p]=lst[i];
			p++;
		}
	}
	cout<<p-1<<endl;
	for (int j=1;j<p;j++) {
		cout<<lst1[j]<<" ";
	}
	return 0;
}