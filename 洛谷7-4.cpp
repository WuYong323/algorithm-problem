#include<bits/stdc++.h>
using namespace std;

int main()
{
	char lst1[550]={0};
	char lst2[550]={0};
	scanf("%s %s",lst1,lst2);
	int t=max(strlen(lst1),strlen(lst2));
	for (int i=t+2;i>=0;i--) {
		lst1[i]+=lst2[i];
		if(lst1[i]>=10) {
			lst1[i]%=10;
			lst1[i-1]++;
		}
	}
	for (int i=strlen(lst1)-1;i>=0;i--) {
		cout<<lst1[i];
	}
	return 0;
}