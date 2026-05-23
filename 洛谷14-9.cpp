#include<bits/stdc++.h>
using namespace std;

stack<int> q; 
int p,n;
int main()
{
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>n;
		int a[n+5];
		int b[n+5];
		int sum=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n;i++){
			q.push(a[i]);
			while((q.top())==b[sum]){
				q.pop();
				sum++;
				if(q.empty()){
					break;
				}
			}
		}
		if(q.empty()){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}
