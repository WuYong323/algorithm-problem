#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lst[n+5]={0};
	int t=1;
	while(true){
		int tt=0;
		for(int i=1;i<=n;++i){
			if(lst[i]!=1){
				tt++;
				if(t%3==0){
					lst[i]=1;
					t%=3;
				}
				t++;
				
			}
		}
		if(tt==1){
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(lst[i]!=1)  printf("%d",i);
	}
	return 0;
}