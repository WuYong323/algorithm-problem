#include<bits/stdc++.h>
using namespace std;

int lst[10010];
int num[35];

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	sort(lst+1,lst+1+n);
	int len=1;
	int le=1;
	for(int i=2;i<=n;i++){
		num[1]+=lst[i]+lst[i-1];
		lst[i]=lst[i-1]+lst[i];
		sort(lst+i,lst+1+n);
		len=1;
		while(num[len]>=10){
			num[len+1]+=num[len]/10;
			num[len]%=10;
			len++;
			le=max(le,len);
		}
	}
	for(int i=le;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}