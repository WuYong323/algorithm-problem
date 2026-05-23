#include<bits/stdc++.h>
using namespace std;

string a;

int main()
{
	cin>>a;
	for(char x:a){
		if(x>='a'&&x<='z'){
			x-=32;
			cout<<x;
		}
		else cout<<x;
	}
	return 0;
}