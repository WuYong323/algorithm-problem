#include<stdio.h>

int main()
{
	int n;
	scanf("%d",n);
	char lst[n];
	 lst1[5][4*n-1];
	for (int i=0;i<n;i++) {
		scanf("%c",&lst[i]);
	}
	for (int j=0;j<n;j++) {
		if(lst[j]==0) {
			lst1[0]+="XXX";
			lst1[1]+="X.X";
			lst1[2]+="X.X";
			lst1[3]+="X.X";
			lst1[4]+="XXX";
		}
		if(lst[j]==1) {
			lst1[0]+="..X";
			lst1[1]+="..X";
			lst1[2]+="..X";
			lst1[3]+="..X";
			lst1[4]+="..X";
		}
		if(lst[j]==2) {
			lst1[0]+="XXX";
			lst1[1]+="..X";
			lst1[2]+="X.X";
			lst1[3]+="X..";
			lst1[4]+="XXX";
		}
		if(lst[j]==3) {
			lst1[0]+="XXX";
			lst1[1]+="..X";
			lst1[2]+="XXX";
			lst1[3]+="..X";
			lst1[4]+="XXX";
		}
		if(lst[j]==4) {
			lst1[0]+="X.X";
			lst1[1]+="X.X";
			lst1[2]+="XXX";
			lst1[3]+="..X";
			lst1[4]+="..X";
		}
		if(lst[j]==5) {
			lst1[0]+="XXX";
			lst1[1]+="X..";
			lst1[2]+="XXX";
			lst1[3]+="..X";
			lst1[4]+="XXX";
		}
		if(lst[j]==6) {
			lst1[0]+="XXX";
			lst1[1]+="X..";
			lst1[2]+="XXX";
			lst1[3]+="X.X";
			lst1[4]+="XXX";
		}
		if(lst[j]==7) {
			lst1[0]+="XXX";
			lst1[1]+="..X";
			lst1[2]+="..X";
			lst1[3]+="..X";
			lst1[4]+="..X";
		}
		if(lst[j]==8) {
			lst1[0]+="XXX";
			lst1[1]+="X.X";
			lst1[2]+="XXX";
			lst1[3]+="X.X";
			lst1[4]+="XXX";
		}
		if(lst[j]==9) {
			lst1[0]+="XXX";
			lst1[1]+="X.X";
			lst1[2]+="XXX";
			lst1[3]+="..X";
			lst1[4]+="XXX";
		}
	}
	for (int i=0;i<5;i++) {
		for (int j=0;j<n*4-1;j++) {
			printf("%s",lst[i][j]);
		}
	}
	return 0;
}