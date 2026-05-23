#include<stdio.h>
 
 int main()
 {
 	int n,a;
 	int d=1000;
 	scanf("%d",&n);
 	for (int i=1;i<=n;i++) {
 		if(i!=n) {
 		    scanf("%d ",&a);
 		    if (a<=d) {
 			    d=a;
		    }
		}
		else{
			scanf("%d",&a);
 	    	if (a<=d) {
 		    	d=a;
		    }
		} 
	}
 	printf("%d",d);
 	return 0;
 }