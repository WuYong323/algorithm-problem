#include<stdio.h>

char lst1[15][15];
char lst2[15][15];
char lst3[15][15];
int n;

int pd(char lst3[15][15],char lst2[15][15])
{
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if(lst3[i][j]!=lst2[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

int zhuanhuan_1(char lst1[15][15],char lst3[15][15])
{
	for (int i=1,v=n;i<=n;i++,v--) {
		for(int j=1,u=1;j<=n;j++,u++) {
			lst3[u][v]=lst1[i][j];
		}
	}
	return pd(lst3,lst2);
}

int zhuanhuan_2(char lst1[15][15],char lst3[15][15])
{
	for (int i=1,u=n;i<=n;i++,u--) {
		for(int j=1,v=n;j<=n;j++,v--) {
			lst3[u][v]=lst1[i][j];
		}
	}
	return pd(lst3,lst2);
}

int zhuanhuan_3(char lst1[15][15],char lst3[15][15])
{
	for (int i=1,v=1;i<=n;i++,v++) {
		for(int j=1,u=n;j<=n;j++,u--) {
			lst3[u][v]=lst1[i][j];
		}
	}
	return pd(lst3,lst2);
}

int zhuanhuan_4(char lst1[15][15],char lst3[15][15])
{
	for (int i=1,u=1;i<=n;i++,u++) {
		for(int j=1,v=n;j<=n;j++,v--) {
			lst3[i][j]=lst1[u][v];
		}
	}
	return pd(lst3,lst2);
}

int zhuanhuan_5(char lst1[15][15],char lst3[15][15])
{
	char lst[15][15];
	for (int i=1,u=1;i<=n;i++,u++) {
		for(int j=1,v=n;j<=n;j++,v--) {
			lst[i][j]=lst1[u][v];
		}
	}
	if(zhuanhuan_1(lst,lst3)==1){
		return 1;
	}
	else if(zhuanhuan_2(lst,lst3)==1) {
		return 1;
	}
	else if (zhuanhuan_3(lst,lst3)==1) {
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	getchar();
	getchar();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++){
			scanf("%c",&lst1[i][j]);
		}
		getchar();
		getchar();
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			scanf("%c",&lst2[i][j]);
		}
		getchar();
		getchar();
	}
	if(zhuanhuan_1(lst1,lst3)==1) {
		printf("1");
	}
	else if(zhuanhuan_2(lst1,lst3)==1) {
		printf("2");
	}
	else if(zhuanhuan_3(lst1,lst3)==1){
		printf("3");
	}
	else if(zhuanhuan_4(lst1,lst3)==1) {
		printf("4");
	}
	else if(zhuanhuan_5(lst1,lst3)==1) {
		printf("5");
	}
	else if(pd(lst2,lst1)==1) {
		printf("6");
	}
	else{
		printf("7");
	}
	return 0;
}