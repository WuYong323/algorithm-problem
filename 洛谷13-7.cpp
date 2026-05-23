#include<bits/stdc++.h>
using namespace std;

int n;
string words[25];
int len=0;
int used[25];

void back_t(const string &str){
	len=max(len,int(str.size()));
	for(int i=1;i<=n;i++){
		if(used[i]>=2){
			continue;
		}
		for(int j=1;j<min(words[i].size(),str.size());j++){
			if(str.substr(str.size()-j)==words[i].substr(0,j)){
				used[i]++;
				back_t(str+words[i].substr(j));
				used[i]--;
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>words[i];
	}
	char a;
	cin>>a;
	for(int i=1;i<=n;i++){
		if(words[i][0]==a){
			used[i]++;
			back_t(words[i]);
			used[i]--;
		}
	}
	cout<<len;
	return 0;
}