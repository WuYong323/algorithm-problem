#include<bits/stdc++.h>
using namespace std;

struct student{
	int yw;
	int sx;
	int yy;
	int zf;
	int id;
}lst[300];

bool comp(student a,student b){
	if(a.zf!=b.zf){
		return a.zf>b.zf;
	}
	else{
		if(a.yw!=b.yw){
			return a.yw>b.yw;
		}
		else {
			return a.id<b.id;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>lst[i].yw>>lst[i].sx>>lst[i].yy;
		lst[i].zf=lst[i].sx+lst[i].yw+lst[i].yy;
		lst[i].id=i;
	}
	sort(lst+1,lst+1+n,comp);
	for(int i=1;i<=5;i++) {
		cout<<lst[i].id<<" "<<lst[i].zf<<endl;
	}
	return 0;
}