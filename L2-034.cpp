#include<bits/stdc++.h>
using namespace std;

struct people{
    string name;
    string id;
    int situation;
    int h,m;
    int idx;
}peo[1005];

int d,p;
vector<people> v;
map <string,int> vis,positive;

bool comp(people a,people b){
    if(a.h!=b.h){
        return a.h<b.h;
    }
    else{
        if(a.m!=b.m){
            return a.m<b.m;
        }
        else{
            return a.idx<b.idx;
        }
    }
}

int main()
{
    cin>>d>>p;
    int t,s;
    for(int i=1;i<=d;++i){
        cin>>t>>s;
        memset(peo,0,sizeof(peo));
        for(int j=1;j<=t;++j){
        	string name,id;
			int si,h,m;
            cin>>name>>id>>si;
            scanf("%d:%d",&h,&m);
            peo[j].name=name;
            peo[j].id=id;
            peo[j].situation=si;
            peo[j].h=h;
            peo[j].m=m;
            peo[j].idx=j;
            if(peo[j].situation==1&&positive[peo[j].name]==0) {
            	v.push_back(peo[j]);
            	positive[peo[i].name]=1;
			}
        }
        sort(peo+1,peo+1+t,comp);
        int len=0;
        for(int j=1;j<=t;++j){
            if(vis[peo[j].name]==0||vis[peo[j].name]==i){
                if(peo[j].id.size()==18){
                    cout<<peo[j].name<<" "<<peo[j].id<<endl;
                    vis[peo[j].name]=i+p+1;
                    ++len;
                    if(len==s){
                    	break;
					}
                }
        	}
        }
    }
    for(auto x:v){
        cout<<x.name<<" "<<x.id<<endl;
    }
    return 0;
}