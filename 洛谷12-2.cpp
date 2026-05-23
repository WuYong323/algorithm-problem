#include<bits/stdc++.h>
using namespace std;

int lst[200005];

int erfen(int a,int n){
	int low=1;
	int high=n;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(lst[mid]==a){
			int i=1,j=1;
			while(lst[mid+i]==a){
				i++;
			}
			while(lst[mid-j]==a){
				j++;
			}
			return i+j-1;
		}
		else if(lst[mid]>a){
			high=mid-1;
		}
		else {
			low=mid+1;
		}
	}
	return -1;
}

int main()
{
	int n,c;
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&lst[i]);
	}
	int ans=0;
	sort(lst+1,lst+1+n);
	for(int i=1;i<=n;i++){
		int t=erfen(c+lst[i],n);
		if(t!=-1){
			ans+=t;
		}
	}
	printf("%d",ans);
	return 0;
}