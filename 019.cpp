#include<bits/stdc++.h>
using namespace std;

int n;
int a,b;
int x1,x2,y1,y2;
int len1,len2;

int check(int x1,int x2,int y1,int y2){
    bool f1=(x1+y1)==x2;
    bool f2=(x1+t1)==y2;
    if(f1&&f2||!f1&&!f2) return 0;
    if(f1) return 1;
    if(f2) return -1;
}

int main()
{
    cin>>a>>b;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x1>>x2>>y1>>y2;
        int t=check(x1,x2,y1,y2);
        if(t==1) len1++;
        if(t==-1) len2++;
        if(len1>a){
            cout<<"A"<<endl;
            cout<<len2;
            break;
        }
        if(len2>b){
            cout<<"B"<<endl;
            cout<<len1;
            break;
        }
    }
    return 0;
}