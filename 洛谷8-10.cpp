#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n+5];
	int lst[n+5];
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int j=1;j<n;j++) {
		lst[j]=abs(a[j]-a[j+1]);
	}
	int b=0;
	sort(lst+1,lst+n);
	for (int k=1;k<n-1;k++) {
		if(lst[k]+1!=lst[k+1]){
			printf("Not jolly");
			b=1;
			break;
		}
	}
	if (b==0)
	printf("Jolly");
	return 0;
}