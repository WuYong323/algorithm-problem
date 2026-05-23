#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<int> num[55];
int ch;
int k;

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m;
        num[i].push_back(m);
        for(int j=1;j<=m;++j){
            cin>>ch;
            num[i].push_back(ch);
        }
    }
    cin>>k;
    int num1,num2;
    for(int i=1;i<=k;++i){
        cin>>num1>>num2;
        int nc=0,nt=0;
        set<int> s1;
        set<int> s2;
        set<int> s;
        m=num[num1][0];
        for(int j=1;j<=m;++j){
            s1.insert(num[num1][j]);
            s.insert(num[num1][j]);
        }
        m=num[num2][0];
        for(int j=1;j<=m;++j){
            s2.insert(num[num2][j]);
            s.insert(num[num2][j]);
        }
        for(int x:s1){
            if(s2.count(x)){
                nc++;
            }
        }
        nt=s.size();
        printf("%.2f%\n",1.0*nc/nt*100);
    }
    return 0;
}