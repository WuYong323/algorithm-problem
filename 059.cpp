#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin>>n;
    getchar();
    while (n--){
        getline(cin,s);
        int pos=s.find(",");
        if(s.rfind("ong,")==pos-3&&s.rfind("ong.")==s.length()-4){
            int cnt=0;
            int i;
            for (i=s.length()-1;i>=0;i--){
                if (s[i]==' '){
                    cnt++;
                    if (cnt==3)break;
                }
            }
            cout<<s.substr(0,i+1)<<"qiao ben zhong."<<endl;
        } else{
            cout<<"Skipped"<<endl;
        }
    }
    return 0;
}