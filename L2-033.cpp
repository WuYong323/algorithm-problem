#include<bits/stdc++.h>
using namespace std;

int n;
stack<double> number;
stack<char> option;

void check(double n1,char opt,double n2){
    if(opt=='+'){
        n2+=n1;
    }
    else if(opt=='-'){
        n2-=n1;
    }
    else if(opt=='*'){
        n2*=n1;
    }
    else if(opt=='/'){
        if(n1==0){
            cout<<"ERROR: X/0";
            exit(0);
        }
        n2/=n1;
    }
    number.push(n2);
}

int main()
{
    cin>>n;
    double num;
    char op;
    for(int i=1;i<=n;++i){
        cin>>num;
        number.push(num);
    }
    for(int i=1;i<n;++i){
        cin>>op;
        option.push(op);
    }
    double n1,n2;
    char opt;
    n1=number.top();
    number.pop();
    for(int i=1;i<n;++i){
        n2=number.top();
        number.pop();
        opt=option.top();
        option.pop();
        check(n1,opt,n2);
        n1=number.top();
        number.pop();
    }
    int ans=(int)n1;
    printf("%d",ans);
    return 0;
}