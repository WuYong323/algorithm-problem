#include<bits/stdc++.h>
using namespace std;

int lst[20][20];
int n;

int main()
{
	cin>>n;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if(!i) lst[i][j]=1;
			else if(!j) lst[i][j]=lst[i-1][j+1];
			else lst[i][j]=lst[i][j-1]+lst[i-1][j+1];
		}
	}
	cout<<lst[n][0];
	return 0;
}