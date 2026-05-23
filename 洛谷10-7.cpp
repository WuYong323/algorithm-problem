#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lst[1010][1010];



int main()
{
	int m,n;
	int len=1;
	cin>>m>>n;
	lst[m][1]=1;
	lst[m+1][1]=1;
	for(int i=m+2;i<=n;i++){
		for(int j=1;j<=len;j++){
			lst[i][j]+=lst[i-1][j]+lst[i-2][j];
			if(lst[i][j]>=10){
				lst[i][j+1]+=lst[i][j]/10;
				lst[i][j]%=10;
			}
		}
		while (lst[i][len+1]) len++;
	}
	for(int k=len;k>=1;k--)
		cout<<lst[n][k];
	return 0;
}