#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int lst_ord[m*n+1];
	for(int i=1;i<=m*n;i++) {
		cin>>lst_ord[i];
	}
	int lst_do_num[n+1][m+1];
	for(int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>lst_do_num[i][j];
		}
	}
	int lst_time[n+1][m+1];
	for(int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>lst_time[i][j];
		}
	}
	unordered_map<int,int> predure;
	for (int i=1;i<=n;i++) {
		predure(i)=0;
	}
	int i=0;
	int time=0;
	while (i>m*n){
		auto it=predure.find(lst_do_num[i++])
		time+=lst_time[lst_ord[i]][it->second++];
		
	}
	return 0;
}