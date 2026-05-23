#include<bits/stdc++.h>
using namespace std;

struct dach{
	int l;
	int r;
}d[1010];

bool comp(dach a,dach b){
	return a.l*a.r<b.l*b.r;
}

void chu(int *lst,int a,int *len){
	int re=0;
	for(int i=*len;i>=1;i--){
		int cu=re*10+lst[i];
		lst[i]=cu/a;
		re=cu%a;
	}
	while(*len>1&&!lst[*len]){
		(*len)--;
	}
	
}

void chen(int *lst,int a,int *len){
	int ca=0;
	for(int i=1;i<=*len;i++){
		lst[i]=lst[i]*a+ca;
		ca=lst[i]/10;
		lst[i]%=10;
	}
	while(ca){
		(*len)++;
		lst[*len]=ca%10;
		ca/=10;
	}
}

void copy(int *a,int *b,int len){
	for(int i=1;i<=len;i++){
		a[i]=b[i];
	}
}

bool com(int *a,int *b,int len_a,int len_b){
	if(len_a!=len_b){
		return len_a>len_b;
	}
	for(int i=len_a;i>=1;i--){
		if(a[i]!=b[i]){
			return a[i]>b[i];
		}
	}
	return false;
} 

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>d[i].l>>d[i].r;
	}
	sort(d+1,d+1+n,comp);
	int lst[4005]={0};
 	int pre[4005]={0};
 	int pre2[4005]={0};
	int temp=d[0].l;
	int len_p=0;
	while(temp){
		len_p++;
		pre[len_p]=temp%10;
		temp/=10;
	}
	if(len_p==0){
		len_p=1;
	}
	int len_l=0;
	for(int i=1;i<=n;i++){
		copy(pre2,pre,len_p);
		int len_p2=len_p;
		chu(pre2,d[i].r,&len_p2);
		if(com(pre2,lst,len_p2,len_l)){
			len_l=len_p2;
			copy(lst,pre2,len_l);
		}
		chen(pre,d[i].l,&len_p);
	}
	if(len_l==0){
		cout<<0;
	}
	else {
		for(int i=len_l;i>=1;i--){
			cout<<lst[i];
		}
	}
	return 0;
}