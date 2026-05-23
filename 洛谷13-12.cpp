#include<bits/stdc++.h>
using namespace std;

struct guize{
	string a;
	string b;
}guiz[8];

struct state{
	string str;
	int step;
};

int main()
{
	int n=1;
	string A;
	string B;
	cin>>A>>B;
	while(cin>>guiz[n].a>>guiz[n].b) n++;
	n--;
	queue<state>q;
	unordered_map<string, int> visited;
	
	q.push({A,0});
	visited[A]=0;
	int ans=-1;
	while(!q.empty()){
		state current=q.front();
		q.pop();
		if(current.str==B){
			ans=current.step;
			break;
		}
		if(ans>10){
			continue;
		}
		for(int i=1;i<=n;i++){
			string aa=guiz[i].a;
			string bb=guiz[i].b;
			int len=aa.size();
			int pos=0;
			while ((pos=current.str.find(aa,pos))!=string::npos){
				string newstr=current.str.substr(0,pos)+bb+current.str.substr(pos+len);
				if (newstr.length()<=20) {
                    if (visited.find(newstr)==visited.end()||current.step+1<visited[newstr]){
                        visited[newstr]=current.step+1;
                        q.push({newstr,current.step+1});
                    }
                }
                pos++;
			}
		}
	}
	if (ans!=-1&&ans<=10) {
        cout<<ans<<endl;
    } else {
        cout<<"NO ANSWER!"<<endl;
    }
	return 0;
}