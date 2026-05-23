#include<bits/stdc++.h>
using namespace std;

int r,c,k;
int rx[2]={0,1},ry[2]={1,0},an;
char lst[110][110];

void skim(int i,int j,int t,int p){
	if(p>k){
		an++;
		return;
	}
	if(lst[i][j]!='.'||i<1||j<1||i>r||j>c){
		return;
	}
	skim(i+rx[t],j+ry[t],t,p+1);
	return;
}

int main()
{
	cin>>r>>c>>k;
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			cin>>lst[i][j];
		}
	}
	for (int i=1;i<=r;i++) {
		for (int j=1;j<=c;j++) {
			if(lst[i][j]=='.'){
				for (int t=0;t<2;t++){
					skim(i,j,t,1);
				}
			}
		}
	}
	if(k==1){
		an/=2;
	}
	cout<<an;
	return 0;
}