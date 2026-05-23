#include <bits/stdc++.h>
using namespace std;

int n,w[105],L[105],R[105];
int ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
    	cin>>w[i];
	}
    for(int i=1;i<=n;++i){
        L[i]=1;
        for(int j=1;j<i;++j)
            if(w[j]<w[i]) L[i]=max(L[i],L[j]+1);
    }
    for(int i=n;i>=1;--i){
        R[i]=1;
        for(int j=n;j>i;--j){
            if(w[j]<w[i]) R[i]=max(R[i],R[j]+1);
        }
    }
    for(int i=1;i<=n;++i){
        ans=max(ans,L[i]+R[i]-1);
    }
    cout<<n-ans;
    return 0;
}