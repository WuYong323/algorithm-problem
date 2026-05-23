#include<bits/stdc++.h>
#define ll long long
using namespace std;

string lst1,lst2;
ll n;

char digui(){
	lst2=lst1;
	if(lst1.size()>n){
		return lst1[n-1];
	}
	else {
		char a=lst2[lst2.size()-1];
		lst2.erase(lst2.size()-1,1);
		lst2=a+lst2;
		lst1=lst1+lst2;
	}
	digui();
	return lst1[n-1];
}

int main()
{
	cin>>lst1;
	cin>>n;
	cout<<digui();
	return 0;
}