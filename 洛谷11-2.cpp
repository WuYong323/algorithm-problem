#include<bits/stdc++.h>
using namespace std;

struct man{
	int t;
	int index;
};

bool comp(man a,man b){
	return a.t<b.t;
}
int main()
{
	int n;
	cin>>n;
	man peo[1010];
	for(int i=1;i<=n;i++){
		cin>>peo[i].t;
		peo[i].index=i;
	}
	sort(peo+1,peo+1+n,comp);
	long long sum=0;
	for(int i=1;i<=n;i++){
		cout<<peo[i].index<<" ";
		for(int j=1;j<i;j++){
			sum+=peo[j].t;
		}
	}
	cout<<endl;
	double p=(double)sum/n;
	printf("%.2f",p);
	return 0;
}