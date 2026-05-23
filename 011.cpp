#include<bits/stdc++.h>
using namespace std;

char str[10005];
bool ascii[200];
int len;

int main()
{
    char ch;
    scanf("%[^\n]s",str);
    while(cin>>ch){
        ascii[(int)ch]=1;
    }
    for(int i=0;i<strlen(str);++i){
        if(ascii[(int)str[i]]){
            cout<<str[i];
        }
    }
    return 0;
}