#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t,flag[2002][2002];
int k,f[2002][2002];
void yh(){
	f[0][0]=f[1][0]=f[1][1]=1;
	for (int i=2;i<=2000;i++){
		f[i][0]=1;
		for (int j=1;j<=i;j++){
			f[i][j]=(f[i-1][j-1]%k+f[i-1][j]%k)%k;
			flag[i][j]=flag[i-1][j]+flag[i][j-1]-flag[i-1][j-1];
			if (f[i][j]==0) flag[i][j]++;
		}
		flag[i][i+1]=flag[i][i];//本篇题解的重点，这里想明白了这题就很简单了
	}
}
int main (){
	scanf("%lld%d",&t,&k);
	yh();
	while (t--){
		int m,n;
		scanf("%d%d",&n,&m);
		if(m>n) printf("%lld\\n",flag[n][n]);
		else printf("%lld\\n",flag[n][m]);
	}
	return 0;
}