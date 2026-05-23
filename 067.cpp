#include<bits/stdc++.h>
using namespace std;

map<int,string> memo;
int n;
int num;
string str;
vector<int> s;

int main(){
    double sum=0;
    int ans;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>str>>num;
        sum+=num;
        memo[num]=str;
        s.push_back(num);
    }
    sum=sum/n/2;
    sort(s.begin(),s.end());
    auto a=lower_bound(s.begin(),s.end(),round(sum));
    if(n!=1&&*a-sum<sum-*(a-1)) ans=*a;
    else ans=*(a-1);
    if(n==1) ans=*a;
    printf("%d ",(int)sum);
    cout<<memo[ans];
    return 0;
}