#include<bits/stdc++.h>
using namespace std;

struct time{
    bool s;
    int hh,mm;
}t[1005];

int n;
int num;
char ch;
int hh,mm;

int count(int h1,int m1,int h2,int m2){
    return ((h2-h1)*60+(m2-m1));
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
    	memset(t,0,sizeof(t));
        int ans=0;
        int p=0;
        while(1){
            scanf("%d %c %d:%d",&num,&ch,&hh,&mm);
            if(!t[num].s&&ch=='S') {
            	t[num].s=1;
				t[num].hh=hh;
				t[num].mm=mm;
			}
            if(t[num].s&&ch=='E') {
            	ans+=count(t[num].hh,t[num].mm,hh,mm);
				p++;
			}
            if(!num) break;
        }
        if(p) ans/=p;
        cout<<p<<" "<<ans;
    }
    return 0;
}