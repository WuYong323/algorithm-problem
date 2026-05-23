#include<bits/stdc++.h>
using namespace std;

const int maxn=1e8+10;
vector<int>q;
bool isp[maxn];

void prime(int x){
	for(int i=2;i<=x;i++){
		isp[i]=true;
	}
	for(int i=2;i<=x;++i){
		if(isp[i]){
			q.push_back(i);
		}
		for(int j=0;j<=q.size()&&i*q[j]<=x;++j){
			isp[i*q[j]]=false;
			if(i%q[j]==0){
				break;
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(0);
	int n,p;
	cin>>n>>p;
	prime(n);
	int t;
	while(p--){
		cin>>t;
		cout<<q[t-1]<<"\n";
	}
	return 0;
}