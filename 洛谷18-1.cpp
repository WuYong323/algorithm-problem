#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string a;
    cin >> n >> a >> m;
    
    int sum=0;
    for(char c:a) {
        sum=sum*n+(isdigit(c)?c-'0':c-'A'+10);
    }
    
    string result;
    do {
        int digit=sum%m;
        result+=(digit<10)?'0'+digit:'A'+digit-10;
        sum/=m;
    } while(sum>0);
    
    reverse(result.begin(),result.end());
    cout<<result;
    return 0;
}