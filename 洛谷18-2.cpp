#include<bits/stdc++.h>
using namespace std;



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
	int n;
	n=read();
	int t;
	int ans=0;
	for(int i=1;i<=n;++i){
		t=read();
		ans^=t;
	}
	cout<<ans;
	return 0;
}