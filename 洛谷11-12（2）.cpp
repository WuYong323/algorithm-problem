#include<bits/stdc++.h>
using namespace std;

map<int,int>m;

typedef map<int,int>::iterator it;
int main(){
	int n,ans=1e6;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		m[t]++;
	}
	while(!m.empty()){
		it i=m.begin(),j=m.begin();
		(*i).second--;
		int t=1;
		for(++j;j!=m.end()&&(*j).first==(*i).first+1&&(*j).second>(*i).second;++i,++j){
   			t++;
			(*j).second--;
		}
		i=m.begin();
		while(i!=m.end()&&(*i).second==0){
			m.erase((*i++).first);
		}
		if(t<ans){
			ans=t;
		}
	}
	cout<<ans;
	return 0;
}
