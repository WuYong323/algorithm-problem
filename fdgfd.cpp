#include<bits/stdc++.h>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int t[120][120];

int deep,wide;
int point;
int b[100000000];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=110;++i){
		for(int j=1;j<=110;++j){
			t[i][j]=1e9;
		}
	}
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		point=Max(point,b);
		t[a][b]=1;
		t[b][a]=2;
	}
	int x,y;
	cin>>x>>y;
	for(int k=1;k<=point;++k){
		for(int i=1;i<=point;++i){
			for(int j=1;j<=point;++j){
				t[i][j]=Min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	for(int i=2;i<=point;++i){
		deep=Max(deep,t[1][i]);
		b[t[1][i]]++;
	}
	for(int i=1;i<=deep+1;++i){
		wide=Max(wide,b[i]);
	}
	cout<<deep+1<<endl;
	cout<<wide<<endl;
	cout<<t[x][y]<<endl;
	return 0;
} 