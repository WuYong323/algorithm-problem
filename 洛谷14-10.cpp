#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum=0;
	int lst[50000];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		int b=1e9;
		if(i==1){
			sum+=a;
		}
		else{
			for(int j=1;j<=i-1;j++){
				if(b>abs(lst[j]-a)){
					b=abs(lst[j]-a);
				}
			}
			sum+=b;
		}
		lst[i]=a;
	}
	cout<<sum;
	return 0;
}