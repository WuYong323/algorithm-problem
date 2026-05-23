#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> q;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int main()
{
	int t;
	t=read();
	for(int i=1;i<=t;++i){
		q.clear();
		int n;
		n=read();
		int a;
		for(int j=1;j<=n;++j){
			a=read();
			if(!q[a]){
				printf("%d ",a);
				q[a]=1;
			}
		}
		printf("\n");
	}
	return 0;
}