#include<bits/stdc++.h>
using namespace std;

int n;
int lst[20];


void dfs(int index,int sum){
	if(sum==n){
		cout<<lst[1];
		for(int i=2;i<index;i++){
			cout<<"+"<<lst[i];
		}
		cout<<endl;
		return;
	}
	for(int i=lst[index-1];i<=n-sum;i++){
		if(i!=0&&i!=n){
			lst[index]=i;
			dfs(index+1,sum+i);
		}
	}
}

int main()
{
	cin>>n;
	lst[0]=1;
	dfs(1,0);
	return 0;
}