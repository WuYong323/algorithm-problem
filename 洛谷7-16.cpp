#include<bits/stdc++.h>
using namespace std;

int lst[510];
int a[510];

void mul1(){
	int tep[1010]={0};
	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++){
			tep[i+j]+=lst[i]*a[j];
		}
	}
	int t=0;
	for(int i=0;i<500;i++){
		tep[i]+=t;
		lst[i]=tep[i]%10;
		t=tep[i]/10;
	}
}

void mul2(){
	int tep[1010]={0};
	for(int i=0;i<500;i++){
		for(int j=0;j<500;j++){
			tep[i+j]+=a[i]*a[j];
		}
	}
	int t=0;
	for(int i=0;i<500;i++){
		tep[i]+=t;
		a[i]=tep[i]%10;
		t=tep[i]/10;
	}
}

void q_pow(int p){
	lst[0]=1;
	a[0]=2;
	while(p){
		if(p&1)mul1();
		mul2();
		p>>=1;
	}
}

int main()
{
	int p;
	cin>>p;
	int len=p*log10(2)+1;
	cout<<len<<endl;
	q_pow(p);
	lst[0]--;
	int num=0;
	for(int i=499;i>=0;i--){
        if(num==50) {
			cout<<endl;
			num=0;
		}
        cout<<lst[i];
        num++;
    }
	return 0;
}