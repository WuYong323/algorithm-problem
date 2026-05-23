#include<bits/stdc++.h>
using namespace std;

void fenzhi(int x,int y,int a,int b,int l){
	if(l==1)return;
	if(x-a<=l/2-1&&y-b<=l/2-1){
		cout<<a+l/2<<" "<<b+l/2<<" "<<1<<endl;
		fenzhi(x,y,a,b,l/2);
		fenzhi(a+l/2-1,b+l/2,a,b+l/2,l/2);
		fenzhi(a+l/2,b+l/2-1,a+l/2,b,l/2);
        fenzhi(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
	}
	else if(x-a<=l/2-1 && y-b>l/2-1)
    {
        cout<<a+l/2<<" "<<b+l/2-1<<" "<<2<<endl;
        fenzhi(a+l/2-1,b+l/2-1,a,b,l/2);
        fenzhi(x,y,a,b+l/2,l/2);
        fenzhi(a+l/2,b+l/2-1,a+l/2,b,l/2);
        fenzhi(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a>l/2-1 && y-b<=l/2-1)
    {
        cout<<a+l/2-1<<" "<<b+l/2<<" "<<3<<endl;
        fenzhi(a+l/2-1,b+l/2-1,a,b,l/2);
        fenzhi(a+l/2-1,b+l/2,a,b+l/2,l/2);
        fenzhi(x,y,a+l/2,b,l/2);
        fenzhi(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else
    {
        cout<<a+l/2-1<<" "<<b+l/2-1<<" "<<4<<endl;
        fenzhi(a+l/2-1,b+l/2-1,a,b,l/2);
        fenzhi(a+l/2-1,b+l/2,a,b+l/2,l/2);
        fenzhi(a+l/2,b+l/2-1,a+l/2,b,l/2);
        fenzhi(x,y,a+l/2,b+l/2,l/2);
	}
}


int main()
{
	int k,x,y;
	cin>>k>>x>>y;
	int sum=1;
	for(int i=1;i<=k;i++){
		sum*=2;
	}
	fenzhi(x,y,1,1,sum);
	return 0;
}