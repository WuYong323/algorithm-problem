#include<stdio.h>

int m(int a,int b){
	if(a<=b){
		return a;
	}
	else {
		return b;
	}
}


int mi(int *a,int k){
	int t=a[0];
	for(int i=1;i<k;i++){
		t=m(t,a[i]);
	}
	return t;
}

int main()
{
	int lst1[5]={1,7,4,8,3};
	int lst2[8]={5,2,9,6,0,4,11,14};
	int lst3[10]={2,6,12,23,44,5,1,7,4,6};
	
	int p=mi(lst1,5);
	p=m(p,mi(lst2,8));
	p=m(p,mi(lst3,10));
	printf("%d",p);
	return 0;
}