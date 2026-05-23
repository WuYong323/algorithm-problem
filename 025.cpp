#include<bits/stdc++.h>
using namespace std;

char ch;
int a,b;


int main()
{
    bool flage1=0,flage2=0;
    while(cin.get(ch)){
        if(ch==' '||ch=='\n') break;
        if(isdigit(ch)){
            a=a*10+ch-'0';
        }
        else flage1=1;
    }
    if(flage1) cout<<"?";
    else cout<<a;
    cout<<" + ";
    while(cin.get(ch)){
        if(ch==' '||ch=='\n') break;
        if(isdigit(ch)){
            b=b*10+ch-'0';
        }
        else flage2=1;
    }
    if(flage2) cout<<"?";
    else cout<<b;
    cout<<" = ";
    if(flage1||flage2) cout<<"?";
    else cout<<a+b;
    return 0;
}