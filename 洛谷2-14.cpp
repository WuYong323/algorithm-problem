#include <stdio.h>

int main()
{
	int x,n,a;
	int km=0;
	scanf("%d %d",&x,&n);
    for (a=1;a<=n;a++) {
    	if (x!=6 && x!=7) {
    		km+=250;
		}
		else if(x==6) {
			x=6;
		}
		else {
			x=0;
		}
		x++;
	}
	printf("%d",km);
	return 0;
}