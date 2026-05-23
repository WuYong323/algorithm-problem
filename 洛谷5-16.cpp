#include<bits/stdc++.h>
using namespace std;

string str,in_str,s;
int p=-1,q=0;
int main()
{
	cin>>in_str;
	for(int i=0;i<in_str.size();i++){
		in_str[i]=tolower(in_str[i]);
	}
	getchar();
	getline(cin,str);
	str+=' ';
	for(int i=0;i<str.size();i++) {
		str[i]=tolower(str[i]);
	}
	for(int i=0;i<str.size();i++) {
        if(str[i]==' '){
            if(s==in_str){
                q++;
                if(p==-1){
                	p=i-in_str.size();
                }
            }
            s="";
        }
        else {
        	s+=str[i];
    	}
    }
    if(q==0){
   		cout<<-1;
	}
	else {
	cout<<q<<' '<<p;
	}
    return 0;
}