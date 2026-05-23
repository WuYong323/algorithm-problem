#include<bits/stdc++.h>
using namespace std;

queue<int> q;
map<int,vector<int>> memo;
map<int,int> num;

int main()
{
	int n;
	cin>>n;
	int t,k;
	int nn=0;
	for(int i=1;i<=n;i++){
		cin>>t>>k;
		q.push(t);
		vector<int> arr;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			arr.push_back(a);
			if(num[a]==0){
				nn++;
			}
			num[a]++;
		}
		memo[t]=arr;
		while(!q.empty()&&q.front()<=t-86400){
			for(int j=0;j<memo[q.front()].size();j++){
				num[memo[q.front()][j]]--;
				if(num[memo[q.front()][j]]==0){
					nn--;
				}
			}
			q.pop();
		}
		cout<<nn<<endl;
	}
	return 0;
}