#include<bits/stdc++.h>
using namespace std;

int lst[5010][5010];
int len=1;

void he(int k){
	for(int i=1;i<=len;i++){
		lst[k][i]=lst[k-1][i]+lst[k-2][i];
	}
	for(int i=1;i<=len;i++){
		if(lst[k][i]>=10){
			lst[k][i+1]+=lst[k][i]/10;
			lst[k][i]%=10;
			if(lst[k][len+1])len++;
		}
	}

}


int main()
{
	int n;
	cin>>n;
	lst[1][1]=1;
	lst[2][1]=2;
	for (int k=3;k<=n;k++){
		he(k);
	}
	for(int i=len;i>=1;i--){
		cout<<lst[n][i];
	}
	return 0;
}