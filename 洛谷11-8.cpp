#include<bits/stdc++.h>
#define MAX 100010
using namespace std;

int n;
int lst[MAX];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(lst[i]>lst[i-1])
			sum+=lst[i]-lst[i-1];
	}
	cout<<sum;
	return 0;
}