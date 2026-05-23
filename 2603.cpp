#include<stdio.h>

void cs(char* from,char* to){
	for(;*from;from++,to++){
		*to=*from;
	}
	*to=0;
}

int main()
{
	char* a="I am a teacher.";
	char b[]="You are a student.";
	char* p=b;
	printf("string a=%s\nstring b=%s\n",a,b);
	printf("\ncopy string a to string b:\n");
	cs(a,p);
	printf("string a=%s\nstring b=%s\n",a,b);
	return 0;
}