#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}

int main()
{
	int ans=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++){
		double l=i,r=i+1;
		double f1=f(l);
        double f2=f(r);
		if(!f1){
			printf("%.2f ",l);
			ans++;
		}
		if(f1*f2<0){
			while(r-l>=0.001){
                double m=(l+r)/2;
                if(f(m)*f(r)<=0){
					l=m;
				}
				else{
					r=m;
				}
			}
			printf("%.2f ",r);
			ans++;
		}
		if(ans==3){
			break;
		}
	}
	return 0;
}#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}

int main()
{
	int ans=0;
	cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++){
		double l=i,r=i+1;
		double f1=f(l);
        double f2=f(r);
		if(!f1){
			printf("%.2f ",l);
			ans++;
		}
		if(f1*f2<0){
			while(r-l>=0.001){
                double m=(l+r)/2;
                if(f(m)*f(r)<=0){
					l=m;
				}
				else{
					r=m;
				}
			}
			printf("%.2f ",r);
			ans++;
		}
		if(ans==3){
			break;
		}
	}
	return 0;
}