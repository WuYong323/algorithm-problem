#include<bits/stdc++.h>
using namespace std;

struct student{
	int pow;
	int id;
}stu[500];


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=pow(2,n);i++){
		cin>>stu[i].pow;
		stu[i].id=i;
	}
	student t=stu[1];
	for(int i=2;i<=pow(2,n-1);i++){
		if(t.pow<stu[i].pow){
			t=stu[i];
		}
	}
	stu[1]=t;
	int p=pow(2,n-1);
	t=stu[p+1];
	for(int i=pow(2,n-1)+2;i<=pow(2,n);i++){
		if(t.pow<stu[i].pow){
			t=stu[i];
		}
	}
	stu[p+1]=t;
	if(stu[1].pow<stu[p+1].pow){
		cout<<stu[1].id;
	}
	else{
		cout<<stu[p+1].id;
	}
	return 0;
}