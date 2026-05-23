#include<stdio.h>
#include<string.h>

int mi(int a,int b,int c);
int ma(int a,int b,int c);
int zhong(int a,int b,int c);

int ma(int a,int b,int c)
{
	int h=a;
	if(b>h) h=b;
	if(c>h) h=c;
	return h;
}

int mi(int a,int b,int c)
{
	int j=a;
	if(b<j) j=b;
	if(c<j) j=c;
	return j;
}

int zhong(int a,int b,int c)
{
	int l;
	l=a+b+c-ma(a,b,c)-mi(a,b,c);
	return l;
}

int main()
{
	int a,b,c,A,B,C;
	char s[4];
	scanf("%d %d %d",&a,&b,&c);
	scanf("%s",s);
	A=mi(a,b,c);
	B=zhong(a,b,c);
	C=ma(a,b,c);
	if (strcmp(s,"ABC")==0) {
		printf("%d %d %d",A,B,C);
	}
	if (strcmp(s,"ACB")==0) {
		printf("%d %d %d",A,C,B);
	}
	if (strcmp(s,"BAC")==0) {
		printf("%d %d %d",B,A,C);
	}
	if (strcmp(s,"BCA")==0) {
		printf("%d %d %d",B,C,A);
	}
	if (strcmp(s,"CAB")==0) {
		printf("%d %d %d",C,A,B);
	}
	if (strcmp(s,"CBA")==0) {
		printf("%d %d %d",C,B,A);
	}
	return 0;
}