#include<bits/stdc++.h>
using namespace std;

int n;
int sum;

void louti(int index){
	if(index==n){
		sum++;
		return;
	}
	if(index>n){
		return;
	}
	louti(index+2);
	louti(index+1);
	return;
}


int main()
{
	cin>>n;
	louti(0);
	cout<<sum;
	return 0;
}