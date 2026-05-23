#include<stdio.h>

int main()
{
	int n,jie;
	char s[70],q[70];
	s[70]=0;
	q[70]=1;
	scanf("%d",&n);
	for (int c=1;c<=n;c++) {
		for (int p=1;p<=c;p++) {
			for (int j=0;j<=70;j++) {
				q[70-j]*=p;
				if (q[70-j]/10>=1) {
					q[69-j]+=q[70-j]/10;
					q[70-j]=q[70-j]%10;
				}
			}
	    }
		for (int j=0;j<=70;j++) {
			s[70-j]+=q[70-j];
			if (s[70-j]/10>=1) {
				s[69-j]+=1;
				s[70-j]=s[70-j]%10;
			}
		}
	}
	for (int o=0;o<=70;o++) {
		for (int y=0;y<=o;y++) {
			s[o]*=10;
		}
	}
    for (int t=0;t<=70;t++) {
    	jie=s[t];
	}
	printf("%d",jie);
	return 0;
}