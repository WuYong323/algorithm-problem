#include<bits/stdc++.h>
using namespace std;

struct zongtong{
	int id;
	string lst;
}cand[25];

bool comp(zongtong a,zongtong b){
	if(a.lst.size()==b.lst.size()){
		return a.lst>b.lst;
	}
	return a.lst.size()>b.lst.size();
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>cand[i].lst;
		cand[i].id=i;
	}
	sort(cand+1,cand+1+n,comp);
	cout<<cand[1].id<<"\n"<<cand[1].lst;
	return 0;
}