#include<bits/stdc++.h>
using namespace std;

int main()
{
	int lst1[550]={0};
	int lst2[550]={0};
	scanf("%d %d",lst1,lst2);
	for (int i=549;i>=0;i--) {
		lst1[i]+=lst2[i];
		if(lst1[i]>=10) {
			lst1[i]%=10;
			lst1[i-1]++;
		}
	}
	for (int i=549;i>=0;i--) {
		if (lst1[i]!=0) {
			cout<<lst1[i];
		}
	}
	return 0;
}