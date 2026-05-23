#include<bits/stdc++.h>
using namespace std;

int lst1[100010];
int lst2[100010];
int lst3[100010];

struct point{
	int a;
	int b;
	int s;
}pp[10000];

bool comp(point a,point b){
	return a.s<b.s;
}

int main()
{
	int n;
	cin>>n;
	int a;
	int p=0,q=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>=0) {
			lst1[a]++;
			p=max(p,a);
		}
		else{
			lst2[abs(a)]++;
			q=max(q,abs(a));
		} 
	}
	int t=1; 
	for(int i=q;i>=1;i--){
		lst3[t++]=lst2[i];
	}
	t=q+1;
	for(int i=t;i<=p+q+1;i++){
		lst3[i]=lst1[i-q];
	}
	int j=1;
	int sum=0;
	int v=1;
	for(j=1;j<=p+q+1;j++){
		if(lst3[j+1]!=0&&lst3[j]!=0){
			sum++;
		}
		else{
			if(sum>0){
				pp[v].s=sum+1;
				pp[v].b=j;
				pp[v].a=j-sum;
				v++;
			}
		}
	}
	sort(pp+1,pp+v,comp);
	int d;
	for(int i=1;i<v;i++){
		d=i;
		if(pp[i].s==pp[1].s){
			int sum1=0;
			for(int c=pp[i].a;c<=pp[i].b;c++){
				int x=1;
				if(lst3[c]>1){
					x=0;
					sum1++;
				}
				if(x==1){
					cout<<pp[i].s;
					return 0;
				}
			}
			if(sum1==pp[i].s){
				cout<<pp[i].s;
				return 0;
			}
		}
		else{
			break;
		}
	}
	cout<<pp[d].s;
	return 0;
}