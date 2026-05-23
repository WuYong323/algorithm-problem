#include<bits/stdc++.h>
using namespace std;


void quickSort(int lst[],int left,int right){
	if(left>=right) return;
	int i=left;
	int j=right;
	int mid=(left+right)/2;
	int p=lst[mid];
	while(i<=j){
		while(lst[i]<p) i++;
		while(lst[j]>p) j--;
		if (i<=j) {
			swap(lst[i],lst[j]);
			i++;
			j--;
		}
	}
	if(left<j) quickSort(lst,left,j);
	if(right>i) quickSort(lst,i,right);
}
int main()
{
	int n,k;
	cin>>n>>k;
	int lst[n+1];
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
	}
	quickSort(lst,1,n);
	cout<<lst[k+1];
	return 0;
}