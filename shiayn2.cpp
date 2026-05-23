#include<bits/stdc++.h>
using namespace std;

int main()
{
	string in_str,str="abc";
	for (char i='1';i<='9';i++) {
		str.insert(1,"*");
	}
	cout<<str;
	return 0;
}