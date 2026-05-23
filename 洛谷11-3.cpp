#include<bits/stdc++.h>
using namespace std;

int lst[1000010];
struct game{
	int cha;
	int beg;
	int end;
};

bool comp(game a,game b){
	return a.end<b.end;
}

int main()
{
	int n;
	cin>>n;
	game ga[n+5];
	for(int i=1;i<=n;i++){
		cin>>ga[i].beg>>ga[i].end;
		ga[i].cha=ga[i].end-ga[i].beg;
	}
	sort(ga+1,ga+1+n,comp);
	int p=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=ga[i].beg;j<ga[i].end;j++){
			if(lst[j]==1){
				p=1;
				break;
			}
		}
		if(p==0){
			for(int j=ga[i].beg;j<ga[i].end;j++){
				lst[j]=1;
			}
			sum++;
		}
		p=0;
	}
	cout<<sum;
	return 0;
}