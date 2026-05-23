#include<stdio.h>
#include<string.h>

int main()
{
	int q;
	scanf("%d",&q);
	char lst[200];
	scanf("%s",lst);
	char lstt[110][200];
	int pp=0;
	for (int i=1;i<=q;i++) {
		int z;
		scanf("%d",&z);
		if (z==1) {
			char lst1[100];
			scanf("%s",lst1);
			strcat(lst,lst1);
			char lst10[200];
			sprintf(lstt[pp++],"%s",lst);
		}
		else if(z==2) {
			char lst2[200];
			int a,b;
			scanf("%d %d",&a,&b);
			lst[a+b]='\0';
			strcpy(lst2,&lst[a]);
			strcpy(lst,lst2);
			char lst11;
			sprintf(lstt[pp++],"%s",lst);
		}
		else if (z==3) {
			int k;
			char lst2[200];
			scanf("%d %s",&k,lst2);
			strcat(lst2,&lst[k]);
			lst[k]='\0';
			strcat(lst,lst2);
			sprintf(lstt[pp++],"%s",lst);
		}
		else if(z==4) {
			char lst2[100];
			scanf("%s",lst2);
			char *lst3=strstr(lst,lst2);
			if(lst3!=NULL) {
				int l=lst3-lst;
				sprintf(lstt[pp++],"%d",l);
			}
			else {
				sprintf(lstt[pp++],"-1");
			}
		}
	}
	for (int v=0;v<pp;v++) {
		printf("%s",lstt[v]);
		printf("\n");
	}
	return 0;
}