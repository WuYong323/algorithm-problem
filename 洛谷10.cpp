#include<stdio.h>

int main()
{
	int s,v,minute1,hour,all_minute,minute;
	scanf("%d %d",&s,&v);
	if (s%v>0) {
		minute1=s/v+11;
	}
	else {
		minute1=s/v+10;
	}
	all_minute=8*60-minute1;
	if (all_minute<0){
		hour=(24*60+all_minute)/60;
		minute=(24*60+all_minute)%60;
	}
	else {
		hour=all_minute/60;
	    minute=all_minute%60;
	}
	printf("%02d:%02d",hour,minute);
    return 0;
}