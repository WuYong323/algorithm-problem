#include<bits/stdc++.h>
#define N 10005
using namespace std;

int n;
bool a[N],b[N];

int main(){
	cin>>n;
	char ch;
	for(int i=1;i<=n;++i){
		cin>>ch;
		a[i]=ch=='B'?0:1;
	}
	int mincnt=1e9;
	int anslen;
	for(int len=1;len<=n;++len){
		memset(b,0,sizeof(b));
		bool fb=0,flag=1;
		int cnt=0;
		for(int i=1;i<=n;++i){
			fb^=b[i];
			if(!(a[i]^fb)){
				if(i+len-1>n){
					flag=0;
					break;
				}
				fb^=1,b[i+len]^=1;
				cnt++;
			}
		}
		if(flag){
			if(cnt<mincnt){
				mincnt=cnt;
				anslen=len;
			}
		}
	}
	cout<<anslen<<" "<<mincnt;
}
