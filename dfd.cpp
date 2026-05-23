#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst [m+1];
	for (int i=1;i<=m;i++) {
		cin>>lst[i];
	}
    int sum=0;
	for (int i=1;i<=m;i++){
		for (int j=1;j<i;j++) {
			if (lst[j]>lst[i]) {
				sum++;
			}
		}
    }
	return 0;
}