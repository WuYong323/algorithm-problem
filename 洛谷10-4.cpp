#include<bits/stdc++.h>
using namespace std;

int n;
int lst[1010];

int main()
{
	cin>>n;
	lst[1]=1;
	for (int i=2;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			lst[i]+=lst[j];
		}
		lst[i]++;
	}
	cout<<lst[n];
	return 0;
}