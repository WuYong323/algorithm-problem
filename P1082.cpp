#include <iostream>
using namespace std;

int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main() 
{
    int a,b;
    cin>>a>>b;
    int x,y;
    exgcd(a,b,x,y);
    x=(x%b+b)%b;
    cout<<x;
    return 0;
}