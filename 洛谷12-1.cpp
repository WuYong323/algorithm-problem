#include<bits/stdc++.h>
using namespace std;

int lst[1000010];
int sou[100010];

int erfen(int n,int i){
	int low=1;
	int high=n;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(lst[mid]>=sou[i]){
			if(lst[mid]==sou[i]){
				ans=mid;
			}
			high=mid-1;
		}
		else {
			low=mid+1;
		}
	}
	return ans;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&lst[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&sou[i]);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",erfen(n,i));
	}
	return 0;
}