#include<bits/stdc++.h>
using namespace std;

int lst[50010];
int cha[50010];
int l,n,m;

int main()
{
	cin>>l>>n>>m;
	int i;
	if(n==0){
		cout<<l;
		return 0;
	}
	for(i=1;i<=n;i++){
		cin>>lst[i];
		cha[i]=lst[i]-lst[i-1];
	}
	cha[i]=l-lst[n];
	for(int j=1;j<=m;j++){
		int p=cha[1];
		int index=1;
		for(int a=2;a<=n+1;a++){
			if(p>cha[a]&&cha[a]!=0){
				p=cha[a];
				index=a;
			}
		}
		int b=1,d=1;
		while(cha[index+b]==0){
			b++;
		}
		while(cha[index-d]==0){
			d++;
		}
		if(cha[index+b]<=cha[index-d]){
			cha[index]+=cha[index+b];
			cha[index+b]=0;
		}
		else{
			cha[index]+=cha[index-d];
			cha[index-d]=0;
		}
	}
	int z=1e9;
	for(int q=1;q<=n+1;q++){
		if(cha[q]!=0){
			z=min(z,cha[q]);
		}
	}
	cout<<z;
	return 0;
}