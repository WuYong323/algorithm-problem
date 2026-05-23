#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> q;
	map<int,int> memo;
	int m,n;
	cin>>m>>n;
	int t;
	int num=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(memo.find(t)==memo.end()){
			if(num>m-1){
				memo.erase(q.front());
				q.pop();
				num--;
			}
			ans++;
			q.push(t);
			memo[t]=ans;
			num++;
		}
	}
	cout<<ans;
	return 0;
}