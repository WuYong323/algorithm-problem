#include<bits/stdc++.h>
using namespace std;

map<string,int> q;

int main()
{
	int n;
	cin>>n;
	int num=0;
	int a;
	string name;
	int score;
	for(int i=1;i<=n;++i){
		cin>>a;
		if(a==1){
			cin>>name>>score;
			if(q.find(name)==q.end()){
				num++;
			}
			cout<<"OK"<<endl;
			q[name]=score;
		}
		else if(a==2){
			cin>>name;
			if(q.find(name)!=q.end()){
				cout<<q[name]<<endl;
			}
			else{
				cout<<"Not found"<<endl;
			}
		}
		else if(a==3){
			cin>>name;
			if(q.find(name)!=q.end()){
				cout<<"Deleted successfully"<<endl;
				q.erase(name);
				num--;
			}
			else{
				cout<<"Not found"<<endl;
			}
		}
		else{
			cout<<num<<endl;
		}
	}
	return 0;
} 