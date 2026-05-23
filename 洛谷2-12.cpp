#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b<=c || a+c<=b || b+c<=a) {
		printf("Not triangle\n");
	}
	else{
	    if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b) {
		    printf("Right triangle\n");
	    }
	    else if(a*a+b*b>c*c && b*b+c*c>a*a && c*c+a*a>b*b) {
	    	printf("Acute triangle\n");
		}
		else {
			printf("Obtuse triangle\n");
		}
		if(a==b || a==c || c==b){
			printf("Isosceles triangle\n");
		}
		if(a==b && a==c){
			printf("Equilateral triangle\n");
		}
    
    }
	return 0;
	
}