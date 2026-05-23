#include<bits/stdc++.h>
using namespace std;

int lst[200005];

int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++){
        scanf("%d",&lst[i]);
    }
    sort(lst,lst+n);
    int ans=0;
    for(int i=0;i<n;i++){
        int target=lst[i]+c;
        auto left=lower_bound(lst,lst+n,target);
        auto right=upper_bound(lst,lst+n,target);
        ans+=(right-left);
    }
    printf("%d",ans);
    return 0;
}