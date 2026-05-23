#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst[m+1];
	for (int i=1;i<=m;i++) {
		cin>>lst[i];
	}
	for (int i=2;i<=m;i++) {
		for (int j=i;j>=1;j--){
			if(lst[j]<lst[j-1]){
				int t=lst[j];
				lst[j]=lst[j-1];
				lst[j-1]=t;
			}
			else {
				break;
			}
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<lst[i]<<" ";
	}
	return 0;
}