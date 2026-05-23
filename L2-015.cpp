#include<bits/stdc++.h>
using namespace std;

int n,k,m;

double stu[10005];
int num[10005];

int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            cin>>num[j];
        }
        sort(num+1,num+1+k);
        double sum=0;
        for(int j=2;j<k;++j){
            sum+=num[j];
        }
        stu[i]=sum*1.0/(k-2);
    }
    sort(stu+1,stu+1+n);
    cout<<stu[m];
    for(int i=m-1;i>=1;--i){
        cout<<" "<<stu[i];
    }
    return 0;
}