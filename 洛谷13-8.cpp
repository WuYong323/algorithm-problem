#include<bits/stdc++.h>
using namespace std;

int n;
char lst[105][105];
int lx[]={0,0,1,-1,1,1,-1,-1};
int ly[]={1,-1,0,0,1,-1,1,-1};
int blst[105][105];

bool ci(int x,int y,int rx,int ry){
	if(lst[x][y]=='y'&&lst[x+rx][y+ry]=='i'&&lst[x+2*rx][y+2*ry]=='z'&&lst[x+3*rx][y+3*ry]=='h'&&lst[x+4*rx][y+4*ry]=='o'&&lst[x+5*rx][y+5*ry]=='n'&&lst[x+6*rx][y+6*ry]=='g'){
		return true;
	}
	return false;
}

void tian(int x,int y,int rx,int ry){
	blst[x][y]=1;
	blst[x+rx][y+ry]=1;
	blst[x+2*rx][y+2*ry]=1;
	blst[x+3*rx][y+3*ry]=1;
	blst[x+4*rx][y+4*ry]=1;
	blst[x+5*rx][y+5*ry]=1;
	blst[x+6*rx][y+6*ry]=1;
	return;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>lst[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<8;k++){
				if(ci(i,j,lx[k],ly[k])){
					tian(i,j,lx[k],ly[k]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(blst[i][j]==0){
				lst[i][j]='*';
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<lst[i][j];
		}
		cout<<endl;
	}
	return 0;
}