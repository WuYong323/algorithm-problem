#include<bits/stdc++.h>
using namespace std;

map<string,string> q;

string fd(string a){
	if(q[a]==a){
		return a;
	}
	return q[a]=fd(q[a]);
}

int main()
{
	string fa;
	while(true){
		string a;
		cin>>a;
		if(a[0]=='#'){
			a.erase(0,1);
			fa=a;
			if(q[fa]=="") q[fa]=fa;
		}
		else if(a[0]=='+'){
			a.erase(0,1);
			q[a]=fa;
		}
		else if(a[0]=='?'){
			a.erase(0,1);
			cout<<a<<" "<<fd(a)<<endl;
		}
		else if(a[0]=='$'){
			break;
		}
	}
	return 0;
}