#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,p;
	int lst[15];
	int lst1[7];
	int tell=0;
	cin>>a>>b>>c;
	if(a==0||b==0||c==0){
		cout<<"No!!!";
		return 0;
	}
	for (int i=100;i<=999;i++) {
		if(i*b%a==0 && i*c%a==0){
			if(i*b/a<1000 && i*c/a<1000){
				int count=0;
				lst[0]=i%10;lst[1]=i%100/10;lst[2]=i/100;
				lst[3]=(i*b/a)%10;lst[4]=(i*b/a)%100/10;lst[5]=(i*b/a)/100;
				lst[6]=(i*c/a)%10;lst[7]=(i*c/a)%100/10;lst[8]=(i*c/a)/100;
				for (int k=0;k<8;k++) {
					for (int l=k+1;l<=8;l++) {
						if(lst[k]==lst[l] ||lst[k]==0){
							count++;
						}
					}
				}
				if(count==0){
					lst1[1]=i;
					lst1[2]=i*c/a;
					lst1[3]=i*b/a;
					sort(lst1+1,lst1+4);
					cout<<lst1[1]<<" "<<lst1[2]<<" "<<lst1[3]<<endl;
					tell++;
				}
			}
		}
	}
	if(tell==0){
		cout<<"No!!!";
	}
	return 0;
}