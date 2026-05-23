#include<stdio.h>

int yuefen(int j,int k);
int ma(int a,int b,int c);
int zh(int a,int b,int c);
int xiao(int a,int b,int c);

int xiao(int a, int b,int c)
{
	int z;
	if (a<b && a<c) {
		z=a;
	}
	if (b<a && b<c) {
		z=b;
	}
	if (c<a && c<b) {
		z=c;
	}
	return z;
}

int zh(int a,int b,int c)
{
	int h;
	if (a<ma(a,b,c) && a>xiao(a,b,c)) {
		h=a;
	}
	if (b<ma(a,b,c) && b>xiao(a,b,c)) {
		h=b;
	}
	if (c<ma(a,b,c) && c>xiao(a,b,c)) {
		h=c;
	}
	return h;
}

int ma(int a,int b,int c)
{
	int s;
	if (a>b && a>c) {
		s=a;
	}
	if (b>a && b>c) {
		s=b;
	}
	if (c>a && c>b) {
		s=c;
	}
	return s;
}

int yuefen(int j,int k) 
{
	while (1) {
		if (j%2==0 && k%2==0) {
		    j/=2;
		    k/=2;
	    }
	    if (j%3==0 && k%3==0) {
	    	j/=3;
	    	k/=3;
		}
		if (j%5==0 && k%5==0) {
			j/=5;
			k/=5;
		}
		if (j%7==0 && k%7==0) {
			j/=7;
			k/=7;
		}
		if (j%2!=0 || j%3!=0 || j&5!=0 || j%7!=0) {
			break;
		}
	}
	printf ("%d/%d",j,k);
	return 0;
}

int main()
{
	int a,b,c,e,f,g;
	scanf("%d %d %d",&a,&b,&c);
	yuefen (xiao(a,b,c),ma(a,b,c));
	return 0;
}