#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int x;
    while (cin>>x) a.push_back(x);
    int n=a.size();
    vector<int> d1;
    vector<int> d2;
    for (int i=0;i<n;++i) {
        auto it1=upper_bound(d1.begin(),d1.end(),a[i],greater<int>());
        if (it1==d1.end())
            d1.push_back(a[i]);
        else
            *it1=a[i];
        auto it2=lower_bound(d2.begin(),d2.end(),a[i]);
        if (it2==d2.end())
            d2.push_back(a[i]);
        else
            *it2=a[i];
    }
    cout<<d1.size()<<"\n"<<d2.size()<<"\n";
    return 0;
}