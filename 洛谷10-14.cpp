#include<bits/stdc++.h>
using namespace std;

char a[1024][2048];
int main()
{
	int len=4,k=1,n;
	cin>>n;
	for(int i=0;i<1024;i++){
		for(int j=0;j<2048;j++){
			a[i][j]=' ';
		}
	}
	a[0][0]=a[1][1]='/';
	a[0][1]=a[0][2]='_';
	a[0][3]=a[1][2]='\\';
	while(k<n)
	{
		for(int i=0;i<len/2;i++)
		for(int j=0;j<len;j++)
		a[i+(len/2)][j+(len/2)]=a[i][j+len]=a[i][j];
		len*=2,k++;
	} 
	for(int i=(len/2)-1;i>=0;i--) 
	{	
	    for(int j=0;j<len;j++)
	    cout<<a[i][j]; 
		cout<<endl;
	}
	return 0;
}