#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> huochai={{0,6},{1,2},{2,5},{3,5},{4,4},{5,5},{6,6},{7,3},{8,7},{9,6}};


int main()
{
	int n;
	int z=0;
	int g=0;
	cin>>n;
	for(int i=0;i<=1000;i++) {
		for(int j=0;j<=1000;j++) {
			int sum=0;
			int d=i;
			int f=j;
			int t=i+j;
			if(d==0){
				sum+=6;
			}
			while (d>0){
				int x=d%10;
				auto a=huochai.find(x);
				sum+=a->second;
				d/=10;
			}
			if(f==0){
				sum+=6;
			}
			while (f>0){
				int y=f%10;
				auto b=huochai.find(y);
				sum+=b->second;
				f/=10;
			}
			if(t==0){
				sum+=6;
			}
			while (t>0){
				int l=t%10;
				auto c=huochai.find(l);
				sum+=c->second;
				t/=10;
			}
			if(4+sum==n){
				z++;
				if(i==j){
					g++;
				}
			}
		}
	}
	cout<<z-g/2;
	return 0;
}