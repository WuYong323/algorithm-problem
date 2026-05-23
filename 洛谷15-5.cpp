#include<bits/stdc++.h>
using namespace std;

string a,b;
int ans;

int main()
{
	cin>>a>>b;
	for(int i=0;i<a.size();++i){
		for(int j=1;j<b.size();++j){
			if(a[i]==b[j]&&a[i+1]==b[j-1]){
				ans++;
			}
		}
	}
	cout<<(1<<ans);
	return 0;
}