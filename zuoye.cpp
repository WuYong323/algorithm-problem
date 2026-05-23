//函数back()功能：实现字符串倒序 
#include<stdio.h>
#include<string>

void back(char lst[]){
	char a;
	int l=0,r=strlen(lst)-1;
	while(l<=r){
		a=lst[l];
		lst[l]=lst[r];
		lst[r]=a;
		l++;
		r--;
	}
}

int main()
{
	char a[10]="abcdef";
	back(a);    //
	puts(a);	//显示结果为：fedcba 
	return 0;
 } 