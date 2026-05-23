#include<bits/stdc++.h>
using namespace std;

struct dist{
	int x;
	int y;
	int z;
};

bool sor(dist a,dist b){
	return a.z<b.z;
}
int main()
{
	int n;
	cin>>n;
	dist wei[n+5];
	for (int i=1;i<=n;i++){
		cin>>wei[i].x>>wei[i].y>>wei[i].z;
	}
	sort(wei+1,wei+n+1,sor);
	double sum=0;
	for (int i=1;i<n;i++) {
		sum+=pow(pow(wei[i+1].x-wei[i].x,2)+pow(wei[i+1].y-wei[i].y,2)+pow(wei[i+1].z-wei[i].z,2),0.5);
	}
	printf("%.3lf",sum);
	return 0;
 } 