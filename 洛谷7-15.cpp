#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mull[10000];
int len=1;
void mul(int t){
	for(int i=1;i<=len;i++){
		mull[i]*=t;
	}
	for(int i=1;i<=len;i++){
		mull[i+1]+=mull[i]/10;
		mull[i]%=10;
	}
	while(mull[len+1]>0){
		len++;
		mull[len+1]+=mull[len]/10;
		mull[len]%=10;
	}
}

int main()
{
	int n;
	int lst[10010];
	cin>>n;
	if(n==3){
		cout<<3<<endl;
		cout<<3;
		return 0;
	}
	if(n==4){
		cout<<4<<endl;
		cout<<4;
		return 0;
	}
	mull[0]=1;
	mull[1]=1;
	int p=2;
	int sum=0;
	while(sum<=n){
		sum+=p;
		lst[p]=p;
		p++;
	}
	p--;
	if(sum-n>1){
		lst[sum-n]=1;
	}
	if(sum-n==1){
		lst[2]=1;
		lst[p]=p+1;
	}
	for(int i=2;i<=p;i++){
		if(lst[i]>1){
			cout<<lst[i]<<" ";
		}
	}
	cout<<endl;
	for(int i=2;i<=p;i++){
		mul(lst[i]);
	}
	for(int i=len;i>=1;i--){
		cout<<mull[i];
	}
	return 0;
}