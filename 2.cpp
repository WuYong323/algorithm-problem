#include<stdio.h>
#include<math.h>
#define ll long long

ll ssum(int *lst){
	ll sum=0;
	for(int i=0;i<=2;i++){
		sum+=pow(lst[i],2);
	}
	return sum;
}

int main()
{
	int lst[3];
	for(int i=0;i<=2;i++){
		scanf("%d",&lst[i]);
	}
	printf("%lld",ssum(lst));
	return 0;
}