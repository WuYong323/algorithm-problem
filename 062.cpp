#include<bits/stdc++.h>
using namespace std;

int n;
int num;

int main()
{
    cin>>n;
    while(n--){
        int num1=0;
        int num2=0;
        for(int i=1;i<=3;++i){
            cin>>num;
            num1+=num;
        }
        for(int i=1;i<=3;++i){
            cin>>num;
            num2+=num;
        }
        if(num1==num2) cout<<"You are lucky!"<<endl;
        else cout<<"Wish you good luck."<<endl;
    }
    return 0;
}