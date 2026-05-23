#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int len;
	for(int i=0;i<str.size();i++){
		if(str[i]=='@'){
			str[i]=0;
			break;
		}
	}
	int num=0;
	int t=0;
	int lst[60]={0};
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&str[i]>='0'){
			num+=str[i]-'0';
			num*=10;
		}
		if(str[i]=='.'){
			num/=10;
			t++;
			lst[t]=num;
			num=0;
		}
		if(str[i]=='/'){
			lst[t-1]/=lst[t];
			t--;
		}
		else if(str[i]=='*'){
			lst[t-1]*=lst[t];
			t--;
		}
		else if(str[i]=='+'){
			lst[t-1]+=lst[t];
			t--;
		}
		else if(str[i]=='-'){
			lst[t-1]-=lst[t];
			t--;
		}
	}
	cout<<lst[1];
	return 0;
}