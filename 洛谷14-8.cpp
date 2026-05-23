#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	vector<int> q;
	for(int i=0;i<str.size();i++){
		if(str[i]==']'){
			if(!q.empty()&&str[q.back()]=='['){
				q.pop_back();
			}
			else{
				str.insert(i,"[");
				i++;
			}
		}
		else if(str[i]==')'){
			if(!q.empty()&&str[q.back()]=='('){
				q.pop_back();
			}
			else{
				str.insert(i,"(");
				i++;
			}
		}
		else{
			q.push_back(i);
		}
	}
	for(int i=q.size()-1;i>=0;i--){
		int tt=q[i];
		if(str[tt]=='['){
			str.insert(tt+1,"]");
		}
		if(str[tt]=='('){
			str.insert(tt+1,")");
		}
	}
	cout<<str;
	return 0;
}