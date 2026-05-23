#include<bits/stdc++.h>
using namespace std;

map<int,char> memo={
    {0,'1'},
    {1,'0'},
    {2,'X'},
    {3,'9'},
    {4,'8'},
    {5,'7'},
    {6,'6'},
    {7,'5'},
    {8,'4'},
    {9,'3'},
    {10,'2'}
};
int quan[20]={0,7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int num[20];
int n;

int main()
{
    cin>>n;
    char ch;
    bool flag=0;
    for(int i=1;i<=n;++i){
        int sum;
        for(int j=1;j<=17;++j){
            cin>>ch;
            num[j]=ch-'0';
            sum+=(ch-'0')*quan[j];
        }
        sum/=100;
        cin>>ch;
        if(memo[sum%11]!=ch){
            flag=1;
            for(int j=1;j<=17;++j){
                cout<<num[j];
            }
            cout<<ch;
            cout<<endl;
        }
    }
    if(!flag) cout<<"All passed";
    return 0;
}