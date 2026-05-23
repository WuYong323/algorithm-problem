#include<bits/stdc++.h>
using namespace std;

int main()
{
	char f[10],str[100],t;
	int i,a,b;
	cin>>i;
	for (int k=1;k<=i;k++) {
		cin>>f;
		if(f[0]>='a' && f[0]<='c') {
			t=f[0];
			cin>>a>>b;
		}
		else {
			sscanf(f,"%d",&a);
			cin>>b;
		}
		if(t=='a') {
			sprintf(str,"%d+%d=%d",a,b,a+b);
		}
		else if(t=='b') {
			sprintf(str,"%d-%d=%d",a,b,a-b);
		}
		else if(t=='c') {
			sprintf(str,"%d*%d=%d",a,b,a*b);
		}
		cout<<str<<endl<<strlen(str)<<endl;
	}
	return 0;
}