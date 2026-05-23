#include<stdio.h>

int main()
{
	int s1,s2,s3;
	scanf("%d %d %d",&s1,&s2,&s3);
	int lst1[s1];
	int lst2[s2];
	int lst3[s3];
	int sum[s1*s2*s3];
	for (int i=0;i<s1;i++) {
		lst1[i]=i+1;
	}
	for (int i=0;i<s2;i++) {
		lst2[i]=i+1;
	}
	for (int i=0;i<s3;i++) {
		lst3[i]=i+1;
	}
	int y=0;
	for(int i=0;i<s1;i++) {
		for (int j=0;j<s2;j++) {
			for (int k=0;k<s3;k++) {
				sum[y]=lst1[i]+lst2[j]+lst3[k];
				y++;
			}
		}
	}
	int sss[s1*s2*s3];
	for (int i=0;i<s1*s2*s3;i++) {
		sss[i]=0;
	}
	for (int i=0;i<s1*s2*s3;i++) {
		for (int j=0;j<s1*s2*s3;j++){
			if(sum[i]==j+1) {
				sss[j]++;
			}
		}
	}
	int z=sss[0];
	int i,t;
	for (i=0;i<s1*s2*s3;i++) {
		if(z<sss[i]) {
			z=sss[i];
			t=i;
		}
	}
	printf("%d",t+1);
	return 0;
}