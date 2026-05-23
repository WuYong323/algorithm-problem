#include<stdio.h>

int tell_year(int year);

int main()
{
	int year,month;
	scanf("%d %d",&year,&month);
	if (tell_year(year)==1 && month==2) {
		printf("29");
	}
	else if (tell_year(year)==0 && month==2) {
		printf("28");
	}
	else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
		printf("31");
	}
	else if(month=4 || month==6 || month==9 || month==11) {
		printf("30");
	}
	return 0;
}

int tell_year(int year)
{
	if (year!=0) {
		if (year%100==0) {
		    if (year%400==0) {
			    return 1;
		    }
		    else {
		        return 0;
	        }
	    }
	    else {
	    	if (year%4==0) {
	    		return 1;
			}
			else {
				return 0;
			}
		}
	}
	else {
		return 0;
	}
}