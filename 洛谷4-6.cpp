#include<stdio.h>

int main()
{
	int w,x,h;
	int a1,b1,c1,a2,b2,c2;
	int count=0;
	scanf("%d %d %d",&w,&x,&h);
	int q;
	scanf("%d",&q);
	int lst[h][x][w];
	for (int i=0;i<h;i++) {
        for (int j=0;j<x;j++) {
       		for (int k=0;k<w;k++) {
       				lst[i][j][k]=0;
      	    }
       	}
    }
	for(int p=1;p<=q;p++) {
		scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);
        for (int i=c1-1;i<=c2-1;i++) {
        	for (int j=b1-1;j<=b2-1;j++) {
        		for (int k=a1-1;k<=a2-1;k++) {
        			lst[i][j][k]=1;
				}
			}
		}
	}
	for (int i=0;i<h;i++) {
        for (int j=0;j<x;j++) {
       		for (int k=0;k<w;k++) {
       			if(lst[i][j][k]==0){
       				count++;
				}
      	    }
       	}
    }
    printf("%d",count);
	return 0;
}