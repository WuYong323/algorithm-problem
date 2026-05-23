#include<bits/stdc++.h>
using namespace std;

set<int>q;

int bl(int x){
    bool found_a=false,found_b=false;
    int a,b;
    for(int num:q){
        if(num<x){
            a=num;
            found_a=true;
        }
        if(num>x){
            b=num;
            found_b=true;
            break;
        }
    }
    if(!found_a){
        return b;
    }
    if(!found_b){
        return a;
    }
    if(x-a<=b-x){
        return a;
    }else{
        return b;
    }
}

int main()
{
	int n;
	cin>>n;
	int num=0;
	for(int i=1;i<=n;++i){
		int a,b;
		cin>>a>>b;
		if(a==1){
			if(q.find(b)==q.end()){
				q.insert(b);
				num++;
			}
			else{
				cout<<"Already Exist"<<endl;
			}
		}
		else if(a==2){
			if(num==0){
				cout<<"Empty"<<endl;
				continue;
			}
			else if(q.find(b)!=q.end()){
				cout<<b<<endl;
				q.erase(b);
				num--;
			}
			else{
				int p=bl(b);
				cout<<p<<endl;
				q.erase(p);
				num--;
			}
		}
	}
	return 0;
}