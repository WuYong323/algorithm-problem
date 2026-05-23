#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	long long sum1=0;
	long long sum2=0;
	for (int i=n,j=m;i>=1&&j>=1;i--,j--) {
		sum1+=i*j;
	}
	for (int i=n;i>=1;i--){
		for (int j=m;j>=1;j--) {
			sum2+=i*j;
		}
	}
	cout<<sum1<<" "<<sum2-sum1<<endl;
	return 0;
}