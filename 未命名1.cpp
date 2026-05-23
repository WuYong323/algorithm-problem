#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    char p=0;//放符号 
    int cnt=0; 
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9') cnt++;//记录第一个数长度
        else    //遇到符号，记录，跳出 
        {
            p=s[i];
            break;
        } 
    }
    int x=cnt;//记下第一个数末后一个的位置，也就是符号的位置，如果是分数或小数就要用 
    cnt--;
    while(s[cnt]=='0'&&cnt>0) cnt--;//去除多余前导0； 
    for(int i=cnt;i>=0;i--)//输出第一个数 
       cout<<s[i];
    if(p==0) return 0;//无符号return 0 
    else
      if(p=='%') {cout<<p;return 0;} 
      else cout<<p;//其他继续 
    int m=s.size()-1;
    while(s[x+1]=='0'&&x<m-1) x++;//去除末尾0 
    while(s[m]=='0'&&m>x+1) m--; //去除多余前导0
    for(int i=m;i>x;i--)//输出第二个数 
        cout<<s[i];
    return 0; 
}