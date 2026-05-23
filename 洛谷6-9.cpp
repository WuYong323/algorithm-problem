#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	char lst[n][10];
	int lst1[n][3];
	for (int i=0;i<n;i++) {
		scanf("%s %d %d %d",&lst[i],&lst1[i][0],&lst1[i][1],&lst1[i][2]);
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if(abs(lst1[i][0]-lst1[j][0])<=5 && abs(lst1[i][1]-lst1[j][1])<=5 && abs(lst1[i][2]-lst1[j][2])<=5 && abs(lst1[i][0]-lst1[j][0]+lst1[i][1]-lst1[j][1]+lst1[i][2]-lst1[j][2])<=10) {
				printf("%s %s\n",lst[i],lst[j]);
			}
		}
	}
	return 0;
}