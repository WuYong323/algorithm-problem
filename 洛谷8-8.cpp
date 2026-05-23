#include<bits/stdc++.h>
using namespace std;

void qsort(int lst[],int l,int r){
	if(l>=r) return;
	int i=l;
	int j=r;
	int mid=(l+r)/2;
	int p=lst[mid];
	while(i<=j){
		while (lst[i]>p)i++;
		while (lst[j]<p)j--;
		if(i<=j){
			swap(lst[i],lst[j]);
			i++;
			j--;
		}
	}
	if(l<j) qsort(lst,l,j);
	if(i<r) qsort(lst,i,r);
}
int main()
{
	int n;
	long long b;
	cin>>n>>b;
	int lst[n+5];
	for (int i=1;i<=n;i++){
		cin>>lst[i];
	}
	qsort(lst,1,n);
	long long sum=0;
	int q=1;
	while (sum<b){
		sum+=lst[q];
		q++;
	}
	cout<<q-1;
	return 0;
}