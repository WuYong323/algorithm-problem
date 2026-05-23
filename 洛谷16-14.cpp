#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<int>> q;


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		string a;
		for(int j=1;j<=t;++j){
			cin>>a;
			q[a].push_back(i);
		}
	}
	int l;
	cin>>l;
	string g;
	for(int i=1;i<=l;++i){
		cin>>g;
		if(q.find(g)==q.end()){
			cout<<endl;
		}
		else{
			vector<int>& r=q[g];
			sort(r.begin(),r.end());
			r.erase(unique(r.begin(),r.end()),r.end());
			for(int j=0;j<q[g].size();++j){
				cout<<r[j];
				if(j!=r.size()-1){
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}