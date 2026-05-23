#include<stdio.h>

int main()
{
    int n;
    int s[100];
    int q[100];
    scanf("%d",&n);
    for (int a=0;a<=99;a++) {
    	s[a]=0;
    	q[a]=0;
	}
    q[100-1]=1;
    for (int c=1;c<=n;c++) {
        int cr=0;
        for (int j=100-1;j>=0;j--) {
            int p=q[j]*c+cr;
            q[j]=p%10;
            cr=p/10;
        }
        cr=0;
        for (int j=100-1;j>=0;j--) {
            int sum=s[j]+q[j]+cr;
            s[j]=sum%10;
            cr=sum/10;
        }
    }
    int st=0;
    while (st<100-1 && s[st]==0) {
        st++;
    }
    for (int i=st;i<100;i++) {
        printf("%d",s[i]);
    }
    return 0;
}