#include<stdio.h>

int main()
{
	float a[3]={123.456,460.323,-0.123456};
	unsigned char *p;
	for(int i=0;i<3;++i){
		p=(unsigned char*)(&a[i]);
		for(int j=0;j<sizeof(float);++j){
			printf("%p,%x\n",p+j,*(p+j));
		}
		printf("%p\n",&a[i]);
	}
	return 0;
}