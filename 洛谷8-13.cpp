#include<bits/stdc++.h>
using namespace std;

struct oiz{
	string n;
	int y;
	int m;
	int d;
	int index;
};

bool comp(oiz a,oiz b){
	if(a.y!=b.y){
		return a.y<b.y;
	}
	else{
		if(a.m!=b.m){
			return a.m<b.m; 
		}
		else {
			if(a.d!=b.d){
				return a.d<b.d;
			}
		}
	}
	return a.index>b.index;
}

int main()
{
	int n;
	cin>>n;
	oiz stu[n];
	int p;
	for (int i=0;i<n;i++) {
		cin>>stu[i].n>>stu[i].y>>stu[i].m>>stu[i].d;
		stu[i].index=i;
	}
	sort(stu,stu+n,comp);
	for (int j=0;j<n;j++){
		cout<<stu[j].n<<"\n";
	}
	return 0;
}