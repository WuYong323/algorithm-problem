#include<stdio.h>
#include<string>

int ma(int a,int b){
	if(a>=b){
		return a;
	}
	else {
		return b;
	}
}

void maxw(char b[],char a[]){
	int m=0,n;
	int cha;
	int p=0;
	for(int i=0;i<=strlen(a);i++){
		if(a[i]==' '||a[i]==0){
			n=i;
			cha=n-m;
			m=i+1;
		}
		p=ma(p,cha);
	}
	m=0;
	for(int i=0;i<=strlen(a);i++){
		if(a[i]==' '||a[i]==0){
			n=i;
			cha=n-m;
			if(cha==p){
				break;
			}
			m=i+1;
		}
	}
	int z=0;
	for(int i=m;i<=n;i++){
		b[z]=a[i];
		z++;
	}
	return;
}

int main()
{
	char a[100]="I am a teacher not a superman";
	char b[100];
	maxw(b,a);
	puts(b);
	return 0;
}