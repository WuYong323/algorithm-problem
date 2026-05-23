#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int lst[n+2];
	for (int i=1;i<=n+1;i++) {
		cin>>lst[i];
	}
	for (int i=1;i<=n+1;i++) {
		if(lst[i]>0){
			if(i==1){
				if((n+1-i)==1){
					if(lst[i]==1){
						printf("x");
					}
					else
					printf("%dx",lst[i]);
				}
				else if((n+1-i)==0){
					printf("%d",lst[i]);
				}
				else if(lst[i]==1){
					printf("x^%d",n+1-i);
				}
				else
				printf("%dx^%d",lst[i],n+1-i);
			}
			else{
				if((n-i+1)==1) {
					if (lst[i]==1){
						printf("+x");
					}
					else
					printf("+%dx",lst[i]);
				}
				else if((n+1-i)==0){
					printf("+%d",lst[i]);
				}
				else if(lst[i]==1) {
					printf("+x^%d",n+1-i);
				}
				else {
					printf("+%dx^%d",lst[i],n+1-i);
				}
			}
		}
		if(lst[i]<0){
				if((n-i+1)==1) {
					if (lst[i]==-1){
						printf("-x");
					}
					else
					printf("%dx",lst[i]);
				}
				else if((n+1-i)==0){
					printf("%d",lst[i]);
				}
				else if(lst[i]==-1) {
					printf("-x^%d",n+1-i);
				}
				else {
					printf("%dx^%d",lst[i],n+1-i);
				}
			}
	}
	return 0;
}