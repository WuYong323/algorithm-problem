#include<bits/stdc++.h>
using namespace std;

int lst[5000];
int lst1[15];

int mul(int num){
	memset(lst,0,sizeof(lst));
	lst[1]=1;
	int len=1;
	int t=0;
	for(int i=2;i<=num;i++){
		for(int j=1;j<=len;j++){
			lst[j]=lst[j]*i+t;
			t=lst[j]/10;
			lst[j]=lst[j]%10;
		}
		while(t>0){
			len++;
			lst[len]=t%10;
			t/=10;
		}
	}
	return len;
}

int main()
{
	int k;
	cin>>k;
	int zz=1;
	for(int i=1;i<=k;i++){
		int nn,pp,ans=0;
		cin>>nn>>pp;
		int ll=mul(nn);
		for(int j=1;j<=ll;j++){
			if(lst[j]==pp){
				ans++;
			}
		}
		lst1[zz]=ans;
		zz++;
	}
	for(int i=1;i<=k;i++){
		cout<<lst1[i]<<endl;
	}
	return 0;
}