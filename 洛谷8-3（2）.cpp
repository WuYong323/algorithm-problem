#include<bits/stdc++.h>
using namespace std;

int lst[5000010];

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&lst[i]);
	}
	sort(lst,lst+n);
	cout<<lst[k];
	return 0;
}