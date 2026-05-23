#include<bits/stdc++.h>
using namespace std;

int main()
{
	string n;
	int k;
	cin>>n>>k;
	vector<char>stk;
	for(char digit:n){
		while (!stk.empty()&&k>0&&stk.back()>digit){
			stk.pop_back();
			k--;
		}
		stk.push_back(digit);
	}
	while(k>0&&!stk.empty()){
		stk.pop_back();
		k--;
	}
	string result(stk.begin(),stk.end());
	int start=0;
	while(start<result.size()&&result[start]=='0'){
		start++;
	}
	if(start==result.size()){
		cout<<0;
	}
	else {
		cout<<result.substr(start);
	}
	return 0;
}