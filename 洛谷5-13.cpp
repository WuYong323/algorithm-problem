#include<bits/stdc++.h>
using namespace std;

int main()
{
	string lst;
	char p=0;
	int c=0;
	cin>>lst;
	for (int i=0;i<lst.size();i++) {
		if(lst[i]>='0'&&lst[i]<='9') 
			c++;
		else {
			p=lst[i];
			break;
		}
	}
	int x=c;
	c--;
	while(lst[c]=='0'&&c>0) {
		c--;
	}
	for(int i=c;i>=0;i--){
    	cout<<lst[i];
    }
    if(p==0){
    	return 0;
	}
	else{
	   	if(p=='%') {
		  	cout<<p;
			return 0;
		} 
		else {
			cout<<p;
		}
	}
    int m=lst.size()-1;
    while(lst[x+1]=='0' && x<m-1) {
		x++;
	}
    while(lst[m]=='0' && m>x+1) {
		m--;
	}
    for(int i=m;i>x;i--){
        cout<<lst[i];
    }
	return 0;
}