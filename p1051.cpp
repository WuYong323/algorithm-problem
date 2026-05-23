#include<bits/stdc++.h>
#define N 105
using namespace std;

int n,ans;

struct student{
	string name;
	int index,score,cla,num,sum;
	char prov,guan;
}stu[N];

bool comp(student a,student b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	else{
		return a.index<b.index;
	}
}

void tel(int p){
	if(stu[p].score>80&&stu[p].num>=1){
		stu[p].sum+=8000;
	}
	if(stu[p].score>85&&stu[p].cla>80){
		stu[p].sum+=4000;
	}
	if(stu[p].score>90){
		stu[p].sum+=2000;
	}
	if(stu[p].score>85&&stu[p].prov=='Y'){
		stu[p].sum+=1000;
	}
	if(stu[p].cla>80&&stu[p].guan=='Y'){
		stu[p].sum+=850;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>stu[i].name>>stu[i].score>>stu[i].cla>>stu[i].guan>>stu[i].prov>>stu[i].num;
		stu[i].index=i;
		tel(i);
		ans+=stu[i].sum;
	}
	sort(stu+1,stu+1+n,comp);
	cout<<stu[1].name<<endl<<stu[1].sum<<endl<<ans;
	return 0;
}