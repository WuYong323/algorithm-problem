#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	long n[20010]={0},m[20010]={0},mul[40020]={0};
	cin>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len1=a.size();
	int len2=b.size();
	for (int i=0;i<len1;i++) {
		n[i]=a[i]-'0';
	}
	for (int i=0;i<len2;i++) {
		m[i]=b[i]-'0';
	}
	for (int i=0;i<len1+len2;i++) {
		for (int j=0;j<len2+len1;j++) {
			mul[j+i]+=n[i]*m[j];
			mul[j+1]+=mul[j]/10;
			mul[j]%=10;
		}
	}
	if (a[0]=='0'||b[0]=='0') {
		cout<<0;
	}
	else {
		for (int i=len1+len2-2;i>=0;i--) {
			cout<<mul[i];
		}
	}
	return 0;
}