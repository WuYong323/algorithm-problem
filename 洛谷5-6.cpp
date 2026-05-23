#include<stdio.h>
#include<string.h>

int main()
{
	char lst[300];
	fgets(lst,sizeof(lst),stdin);
	int n=strlen(lst);
	int p=0;
	for (int i=0;i<n;i++) {
		if(lst[i]=='a'||lst[i]=='d'||lst[i]=='g'||lst[i]=='j'||lst[i]=='m'||lst[i]=='p'||lst[i]=='t'||lst[i]=='w'||lst[i]==' '){
			p++;	
		}
		if(lst[i]=='b'||lst[i]=='e'||lst[i]=='h'||lst[i]=='k'||lst[i]=='n'||lst[i]=='q'||lst[i]=='u'||lst[i]=='x'){
			p+=2;	
		}
		if(lst[i]=='c'||lst[i]=='f'||lst[i]=='i'||lst[i]=='l'||lst[i]=='o'||lst[i]=='r'||lst[i]=='v'||lst[i]=='y'){
			p+=3;	
		}
		if(lst[i]=='s'||lst[i]=='z'){
			p+=4;	
		}
	}
	printf("%d",p);
	return 0;
}