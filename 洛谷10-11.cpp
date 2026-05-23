#include<bits/stdc++.h>
using namespace std;

int n;
char lst[220];


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		lst[i]='o';
	}
	for(int j=n+1;j<=2*n;j++){
		lst[j]='*';
	}
	lst[2*n+1]='-';
	lst[2*n+2]='-';
	for(int i=1;i<=2*n+2;i++){
		cout<<lst[i];
	}
	cout<<endl;
	for(int i=0;i<=n-4;i++){
		swap(lst[2*n+2-2*i],lst[n+1-i]);
		swap(lst[n*2+1-2*i],lst[n-i]);
		for(int j=1;j<=2*n+2;j++){
			cout<<lst[j];
		}
		cout<<endl;
		if(i==n-4){
			break;
		}
		swap(lst[n+1-i],lst[n*2-2*i]);
		swap(lst[n-i],lst[n*2-1-2*i]);
		for(int j=1;j<=2*n+2;j++){
			cout<<lst[j];
		}
		cout<<endl;
	}
	string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
	string ss;
	for (int i = 0; i < n - 4; i++)
        ss += "o*";
    for (int i = 0; i < 4; i++)
        cout << out[i] << ss << endl;
	return 0;
}