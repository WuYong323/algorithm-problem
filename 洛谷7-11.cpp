#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	string str,in_str;
	cin>>str;
	char n,m;
	int z;
	for (int i=0;i<str.size();i++) {
		if(str[i]=='-' &&str[i-1]<str[i+1] &&str[i-1]>='a' && str[i-1]<='z'&&str[i+1]>='a' && str[i+1]<='z'){
			n=str[i-1];
			m=str[i+1];
			in_str="";
			str.erase(i,1);
			if(p1==1) {
				if(p3==1){
					for (char k=n+1;k<m;k++) {
						for (int l=1;l<=p2;l++) {
							in_str.push_back(k);
						}
					}
					str.insert(i,in_str);
				}
				else if(p3==2) {
					for (char k=n+1;k<m;k++) {
						for (int l=1;l<p2;l++) {
							in_str.push_back(k);
						}
					}
					reverse(in_str.begin(),in_str.end());
					str.insert(i,in_str);
				}
			}
			else if(p1==2) {
				if(p3==1) {
					for (char k=n+1-32;k<m-32;k++) {
						for (int l=1;l<=p2;l++) {
							in_str.push_back(k);
						}
					}
					str.insert(i,in_str);
				}
				else if(p3==2){
					for (char k=n+1-32;k<m-32;k++) {
						for (int l=1;l<=p2;l++) {
							in_str.push_back(k);
						}
					}
					reverse(in_str.begin(),in_str.end());
					str.insert(i,in_str);
				}
			}
			else if(p1==3) {
				for (char k=n+1;k<m;k++) {
					for (int l=1;l<=p2;l++) {
						str.insert(i,"*");
					}
				}
			}
		}
		else if(str[i]=='-' &&str[i-1]<str[i+1] &&str[i-1]>='0' && str[i-1]<='9'&&str[i+1]>='0' && str[i+1]<='9'){
			n=str[i-1];
			m=str[i+1];
			in_str="";
			str.erase(i,1);
			if(p1==1 || p1==2){
				if (p3==1) {
					for (char k=n+1;k<m;k++) {
						for (int l=1;l<=p2;l++) {
							in_str.push_back(k);
						}
					}
					str.insert(i,in_str);
				}
				else if (p3==2) {
					for (char k=n+1;k<m;k++) {
						for (int l=1;l<=p2;l++) {
							in_str.push_back(k);
						}
					}
					reverse(in_str.begin(),in_str.end());
					str.insert(i,in_str);
				}
			}
			else if(p1==3) {
				for (char k=n+1;k<m;k++) {
					for (int l=1;l<=p2;l++) {
						in_str.push_back('*');
					}
				}
				str.insert(i,in_str);
			}
		}
	}
	cout<<str;
	return 0;
}