#include<bits/stdc++.h>
using namespace std;

string a,b;

void solve(string a,string b){
	if(b.empty()){
		return;
	}
	char p=b[b.size()-1];
	b.erase(b.size()-1);
	int point=a.find(p);
	cout<<p;
	string la=a.substr(0,point);
	string ra=a.substr(point+1);
	string lb=b.substr(0,point);
	string rb=b.substr(point);
	solve(la,lb);
	solve(ra,rb);
}

int main()
{
	cin>>a>>b;
	solve(a,b);
	return 0;
}