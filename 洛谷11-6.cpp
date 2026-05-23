#include<bits/stdc++.h>
using namespace std;

string str;

int main()
{
	cin>>str;
	int k;
	cin>>k;
	int p=0;
	while(k>0){
		bool de=false;
		for(int i=0;i<str.size()-1;i++){
			if(str[i]>str[i+1]){
				str.erase(i,1);
				k--;
				de=true;
				break;
			}
		}
		while(!de){
			str.erase(str.size()-k,k);
			k=0;
		}
	}
	while(str[0]=='0'){
		str.erase(0,1);
	}
	if(str==""){
		cout<<0;
	}
	for(int i=0;i<str.size();i++){
		cout<<str[i];
	}
	return 0;
}