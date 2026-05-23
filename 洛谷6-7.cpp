#include<stdio.h>

int main()
{
    int lst[100];
    scanf("%d",&lst);
    int n=sizeof(lst)/sizeof(int)-1;
    int lst1[n][n];
    for(int i=1;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d",&lst1[i][j]);
        }
    }
    for(int j=0;j<n;j++) {
        lst1[0][j]=lst[j];
    }
    printf("%d ",n);
    int count0=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(lst1[i][j]==0) {
                count0++;
                if(count0==1){
                    printf("%d ",count1);
                    count1=0;
                }    
            }
            if(lst1[i][j]==1){
                count1++;
                if(count1==1){
                    printf("%d ",count0);
                    count0=0;
                }    
            }
        }
    }
    return 0;
}