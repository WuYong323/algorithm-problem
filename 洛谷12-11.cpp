#include<bits/stdc++.h>
using namespace std;

int n;
double p;
double cosu[100005];
double cun[100005];

bool tel(double a){
	double sum=0;
	for(int i=1;i<=n;i++){
		if(cun[i]-a*cosu[i]<0){
			sum+=a*cosu[i]-cun[i];
		}
	}
	return sum<=a*p;
}

int main()
{
	cin>>n>>p;
	double sum=0;
	for(int i=1;i<=n;i++){
		cin>>cosu[i]>>cun[i];
		sum+=cosu[i];
	}
	if(sum<=p){
		cout<<-1.000000;
		return 0;
	}
	double l=0,r=1e10;
	while(r-l>1e-6){
		double mid=(l+r)/2;
		if(tel(mid)){
			l=mid;
		}
		else {
			r=mid;
		}
	}
	cout<<l;
	return 0;
}