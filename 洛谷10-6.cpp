#include<bits/stdc++.h>
using namespace std;


string digui(){
	int t;
	string str="",s="";
	char a;
	while (cin>>a){
		if(a=='['){
			cin>>t;
			str=digui();
			while(t--){
				s+=str;
			}
		}
		else if(a==']'){
			return s;
		}
		else{
			s+=a;
		}
	}
	return s;
}


int main()
{
	cout<<digui();
	return 0;
}