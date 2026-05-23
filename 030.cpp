#include<bits/stdc++.h>
using namespace std;

struct student{
    int gender;
    string str;
}stu[55];

bool check[55];

int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>stu[i].gender>>stu[i].str;
    }
    int num=0;
    int l=1;
    while(num<=n/2){
        if(check[l]) l++;
        for(int i=n;i>=1;--i){
            if(stu[i].gender==!stu[l].gender&&!check[i]){
                check[i]=1;
                check[l]=1;
                num++;
                cout<<stu[l].str<<" "<<stu[i].str<<endl;
                l++;
                break;
            }
            
        }
    }
    return 0;
}