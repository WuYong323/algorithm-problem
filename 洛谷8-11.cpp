#include<bits/stdc++.h>
using namespace std;

struct vol{
	int id;
	int score;
};

bool comp(vol a,vol b){
	if(a.score!=b.score)return a.score>b.score;
	return a.id<b.id;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vol stu[n+5];
	for (int i=1;i<=n;i++) {
		cin>>stu[i].id>>stu[i].score;
	}
	sort(stu+1,stu+n+1,comp);
	int t=m*3/2;
	for (int i=t+1;i<=n;i++) {
		if(stu[t].score==stu[i].score){
			t++;
		}
		else {
			break;
		}
	}
	cout<<stu[t].score<<" "<<t<<endl;
	for (int i=1;i<=t;i++) {
		cout<<stu[i].id<<" "<<stu[i].score<<endl;
	}
	return 0;
}