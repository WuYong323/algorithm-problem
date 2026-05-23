#include<stdio.h>

int main()
{
	int a,b,c,d,e,f,h,i,j,l,lenth;
	int k=0;
	scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&h,&i,&j,&l);
	scanf("%d",&lenth);
	if(a<=lenth+30) {
		k++;
	}
	if(b<=lenth+30) {
		k++;
	}
	if(c<=lenth+30) {
		k++;
	}
	if(d<=lenth+30) {
		k++;
	}
	if(e<=lenth+30) {
		k++;
	}
	if(f<=lenth+30) {
		k++;
	}
	if(h<=lenth+30) {
		k++;
	}
	if(i<=lenth+30) {
		k++;
	}
	if(j<=lenth+30) {
		k++;
	}
	if(l<=lenth+30) {
		k++;
	}
	printf ("%d",k);
	return 0;
}