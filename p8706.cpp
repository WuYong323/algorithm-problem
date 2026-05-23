#include<bits/stdc++.h>
using namespace std;

string a;

int main()
{
	cin>>a;
	int len=a.length();
	char s;
	for(int i=0;i<len;++i){
		if(!isdigit(a[i])&&isdigit(a[i+1])){
			int t=a[i+1]-'0';
			for(int j=1;j<=t;++j){
				cout<<a[i];
			}
		}
		if(!isdigit(a[i])&&!isdigit(a[i+1])){
			cout<<a[i];
		}
	}
	return 0;
}