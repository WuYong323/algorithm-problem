#include<bits/stdc++.h>
using namespace std;

int lst[5000000];

int main()
{
	int p;
	cin>>p;
	int len=1;
	lst[1]=1;
	
	for(int i=1;i<=p;i++){
		for(int j=1;j<=len;j++){
			lst[j]*=2;
		}
		for(int j=1;j<=len;j++){
			lst[j+1]+=lst[j]/10;
			lst[j]%=10;
		}
		len++;
	}
	len--;
	int l=1;
	while(lst[l]==0){
		l++;
	}
	for(int i=l;i>1;i--){
		lst[i]-=1;
		lst[i-1]+=10;
	}
	lst[1]--;
	int t=0;
	cout<<len<<endl;
	while(t<500-len){
		cout<<0;
		t++;
		if(t%50==0){
			cout<<endl;
		}
	}
	for(int i=len;i>=1;i--){
		cout<<lst[i];
		t++;
		if(t%50==0){
			cout<<endl;
		}
	}

	return 0;
}