#include<bits/stdc++.h>
using namespace std;

struct tree{
	char l;
	char r;
}t[100];

void qb(char m1){
	if(m1=='*'){
		return;
	}
	cout<<m1;
	qb(t[m1].l);
	qb(t[m1].r);
}

int main()
{
	int n;
	cin>>n;
	char m1,m;
	cin>>m1;
	cin>>t[m1].l>>t[m1].r;
	for(int i=2;i<=n;++i){
		cin>>m;
		cin>>t[m].l>>t[m].r;
	}
	qb(m1);
	return 0;
}