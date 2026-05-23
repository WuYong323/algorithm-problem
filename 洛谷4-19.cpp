#include<stdio.h>

int main()
{
	int n;
	scanf("%d",n);
	char lst1[n][n];
	for (int i=0;i<n;i++) {
		scanf("%c",lst1[i]);
	}
	char lst2[n][n];
	for (int i=0;i<n;i++) {
		scanf("%c",lst2[i]);
	}
	int t=8
	for(double i=-(n-1)/2.0;i<=(n-1)/2.0;i++) {
		for (double j=-(n-1)/2;j<=(n-1)/2;j++){
			if(lst1[round((n-1)/2.0+i)][round((n-1)/2.0+j)]==lst2[round((n-1)/2.0+j)][round(-(lst1(n-1)/2.0+i))] && t>1) {
				t=1;
			}
			if(lst1[round((n-1)/2.0+i)][round((n-1)/2.0+j)]==lst2[round(-((n-1)/2.0+i))][round(-(lst1(n-1)/2.0+j))] && t>2){
				t=2;
			}
			if(lst1[round((n-1)/2.0+i)][round((n-1)/2.0+j)]==lst2[round(-(n-1)/2.0+j)][round(lst1(n-1)/2.0+i)] && t>3) {
				t=3;
			}
			if(lst1[round((n-1)/2.0+i)][round((n-1)/2.0+j)]==lst2[round(-((n-1)/2.0+i))][round(lst1(n-1)/2.0+j)] && t>4){
				t=4;
			}
			
		}
	}
	return 0;
}