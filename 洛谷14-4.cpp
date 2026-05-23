#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	int lst[110];
	cin>>n>>m;
	queue<int> q;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int t=1;
	while(!q.empty()){
		int current=q.front();
		q.pop();
		if(t%m==0){
			cout<<current<<" ";
			t=0;
		}
		else{
			q.push(current);
		}
		t++;
	}
	return 0;
}