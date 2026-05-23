#include<bits/stdc++.h>
using namespace std;

string str;
int arr[10];
int idx[20];
map<int,int> memo;

bool comp(int a,int b){
    return a>b;
}

int main()
{
    getline(cin,str);
    int len1=0;
    int len2=0;
    for(char ch:str){
        ch-='0';
        if(!memo[ch]) arr[++len1]=ch;
        memo[ch]++;
        idx[++len2]=ch;
    }
    sort(arr+1,arr+1+len1,comp);
    for(int i=1;i<=len2;++i){
        int t=idx[i];
        for(int j=1;j<=len1;++j){
            if(t==arr[j]) idx[i]=j-1;
        }
    }
    cout<<"int[] arr = new int[]{";
    cout<<arr[1];
    for(int i=2;i<len1;++i)cout<<","<<arr[i];
    cout<<"};";
    cout<<endl;
    cout<<"int[] index = new int[]{";
    cout<<idx[1];
    for(int i=2;i<=len2;++i){
        cout<<","<<idx[i];
    }
    cout<<"};";
    return 0;
}