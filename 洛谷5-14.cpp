#include<bits/stdc++.h>
using namespace std;

char str[100],t;

void jia(int a,int b)
{
	sprintf(str,"%d+%d=%d",a,b,a+b);
}

void jian(int a,int b)
{
	
	sprintf(str,"%d-%d=%d",a,b,a-b);
}

void cheng(int a,int b)
{
	sprintf(str,"%d*%d=%d",a,b,a*b);
}

int main()
{
	int i;
	cin>>i;
	char f[10];
	int a;
	int b;
	for (int k=1;k<=i;k++) {
		cin>>f;
		memset(str,0,sizeof(str));
		if (f[0]!='a' || f[0]!='b'|| f[0]!='c') {
			sscanf(f,"%d",&a);
			cin>>b;
			f[0]=t;
		}
		if (f[0]=='a') {
			cin>>a;
			cin>>b;
			jia(a,b);
		}
		if (f[0]=='b') {
			cin>>a;
			cin>>b;
			jian(a,b);
		}
		if (f[0]=='c') {
			cin>>a;
			cin>>b;
			cheng(a,b);
		}
		t=f[0];
		cout<<str<<endl<<strlen(str)<<endl;
	}
	return 0;
}