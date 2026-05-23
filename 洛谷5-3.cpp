#include<stdio.h>
#include<string.h>

int zhishu(int a)
{
	if(a<=1) {
		return 0;
	}
	for (int i=2;i*i<=a;i++) {
		if(a%i==0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	char lst[110];
	scanf("%s",lst);
	int n=strlen(lst);
	int p=1;
	int m=0;
	int z=100;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			int a1=lst[i];
			int a2=lst[j];
			if(a1==a2 && lst[i]!='0') {
				p++;
				lst[j]='0';
			}
		}
		if(m<p) {
			m=p;
		}
		if(z>p && lst[i]!='0'){
			z=p;
		}
		p=1;
	}
	int a=m-z;
	if(zhishu(a)==1) {
		printf("Lucky Word\n");
		printf("%d",a);
	}
	else {
		printf("No Answer\n");
		printf("0");
	}
	return 0;
}