#include<stdio.h>

int tell_year(int year);

int main()
{
	int year;
	scanf("%d",&year);
	printf("%d",tell_year(year));
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

