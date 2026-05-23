#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lst[7],lst2[7],lst3[7];
	for (int j=0;j<7;j++) {
		lst[j]=0;
		lst2[j]=0;
		lst3[j]=0;
	} 
	for (int j=0;j<7;j++) {
		scanf("%d",&lst2[j]);
	}
	for (int i=1;i<=n;i++) {
		int count=0;
		for (int j=0;j<7;j++) {
			scanf("%d",&lst[j]);
		}
		for (int p=0;p<7;p++) {
			for (int q=0;q<7;q++) {
				if (lst2[p]==lst[q]) {
					lst[q]=0;
					count++;
				}
		    }
		}
		for (int t=1;t<=7;t++) {
			if(count==t) {
				lst3[7-t]++;
			}
		}
	}
	for (int z=0;z<7;z++) {
		printf("%d ",lst3[z]);
	}
	return 0;
}