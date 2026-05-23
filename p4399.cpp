#include <bits/stdc++.h>
#define N 1005
using namespace std;

int n;
const int MOD=998244353;
int h[N];
long long ans;

int main() {
	cin>>n;
    for(int i=1;i<=n;++i) {
    	cin>>h[i];
	}
	vector<unordered_map<int,int>> dp(n+5);
    for (int i=1;i<=n;++i) {
        for (int j=1;j<i;++j) {
            int d=h[i]-h[j];
            int cnt=dp[j].count(d)?dp[j][d]:0;
            int add=(cnt+1)%MOD;
            dp[i][d]=(dp[i][d]+add)%MOD;
            ans=(ans+add)%MOD;
        }
    }
    cout<<(ans+n)%MOD;
    return 0;
}