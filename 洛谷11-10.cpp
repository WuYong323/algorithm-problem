#include<bits/stdc++.h>
using namespace std;

int main()
{
	int w,n;
	cin>>w>>n;
	int lst[n+5];
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	int k=1,l=n;
	int sum=0;
	sort(lst+1,lst+1+n);
	while(1){
		sort(lst+1,lst+1+n);
		k=1+n-l;
		l=n;
		bool t=true;
		while(k<l){
			if(lst[k]+lst[l]<=w){
				t=false;
				lst[k]+=lst[l];
				lst[l]=-1;
				k++;
				l--;
			}
			else{
				l--;
			}	
		}
		if(t){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(lst[i]!=-1){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}