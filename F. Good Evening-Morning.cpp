#include<bits/stdc++.h>
using namespace std;

int d,t0;

int main()
{
	cin>>d>>t0;
	for(int i=0;i<=23;++i){
		int flage1=0,flage2=0;
		int t1=(t0+i)%24;
		if(t1>=6&&t1<=17){
			flage1=1;
		}
		int t2=(t0+d+i)%24;
		if(t2>=0&&t2<=5||t2>=18&&t2<=23){
			flage2=1;
		}
		if(flage1&&flage2){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}