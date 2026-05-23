#include<stdio.h>

int ma(int *lst){
	int t=lst[0];
	for(int i=1;i<3;i++){
		if(t<lst[i]){
			t=lst[i];
		}
	}
	return t;
}

int main()
{
	int lst[3];
	for(int i=0;i<3;i++){
		scanf("%d",&lst[i]);
	}
	printf("%d",ma(lst));
	return 0;
}