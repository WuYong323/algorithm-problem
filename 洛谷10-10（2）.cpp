#include<bits/stdc++.h>
#define ll long long
using namespace std;

string str;
ll n,num,i;

int main()
{
	cin>>str>>n;
	num=str.size();
	while (num<n){
		i=num;
		while(n>i) i*=2;
		i=i/2;
		n-=(i+1);
		if(n==0) n=i;
	}
	cout<<str[n-1];
	return 0;
}