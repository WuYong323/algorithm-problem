#include<bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<char,int> memo;
	memo['1']=0;
	memo['2']=0;
	memo['3']=0;
	memo['4']=0;
	memo['5']=0;
	memo['6']=1;
	memo['7']=0;
	memo['8']=2;
	memo['9']=1;
	memo['0']=1;
	string str;
	cin>>str;
	int sum=0;
	for(int i=0;i<str.size();i++){
		int p=memo[str[i]];
		sum+=p;
	}
	cout<<sum;
	return 0;
}