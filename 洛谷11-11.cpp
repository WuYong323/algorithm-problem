#include<bits/stdc++.h>
using namespace std;

int lst[305];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	sort(lst,lst+1+n);
	int k=1,l=n,t=1;
	int p=lst[0],q=lst[n];
	long long sum=0;
	while(k<=l){
		sum+=pow(q-p,2);
		if(t==1){
			p=lst[k];
			t=2;
			k++;
		}
		else if(t==2){
			l--;
			q=lst[l];
			t=1;
		}
	}
	cout<<sum;
	return 0;
}