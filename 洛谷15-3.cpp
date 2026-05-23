#include<bits/stdc++.h>
using namespace std;

string front,mid;

void solve(string f,string m){
	if(m.empty()) return;
	char ff=m[0];
	m.erase(m.begin());
	int k=f.find(ff);
	string fleft=f.substr(0,k);
	string fright=f.substr(k+1);
	string mleft=m.substr(0,k);
	string mright=m.substr(k);
	solve(fleft,mleft);
	solve(fright,mright);
	cout<<ff;
}

int main()
{
	cin>>mid>>front;
	solve(mid,front);
	return 0;
}