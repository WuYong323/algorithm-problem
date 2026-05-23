#include<stdio.h>

int main()
{
	char a[100],score[100];
	int c=0;
	for (int i=1;i<=100;i++) {
		c++;
		scanf("%d",&a[i]);
		if (a[i]==0) {
			break;
		}
    }
	for (int j=1;j<=c-1;j++) {
		score[j]=a[c-j];
	}
	for (int z=1;z<=c-1;z++) {
		printf("%d ",score[z]);
	}
	return 0;
}