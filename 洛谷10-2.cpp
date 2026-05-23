#include<bits/stdc++.h>
using namespace std;

int bx,by,cx,cy;
long long lst[40][40];
bool s[40][40];




int main()
{
	cin>>bx>>by>>cx>>cy;
	bx+=2;by+=2;cx+=2;cy+=2;
	lst[2][1]=1;
	s[cx][cy]=1;
	int m[]={0,-2,-1,1,2,2,1,-1,-2};
	int n[]={0,1,2,2,1,-1,-2,-2,-1};
	for(int i=1;i<=8;i++){
		s[cx+m[i]][cy+n[i]]=1;
	}
	for(int i=2;i<=bx;i++){
		for(int j=2;j<=by;j++){
			if(s[i][j])continue;
			lst[i][j]=lst[i-1][j]+lst[i][j-1];
		}
	}
	cout<<lst[bx][by];
	return 0;
}