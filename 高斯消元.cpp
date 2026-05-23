#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
const double eps=1e-9;

double a[maxn][maxn];   // 增广矩阵，a[i][j] 第i行第j列
int n;

int gauss(){
	for(int i=0;i<n;++i){   // 当前处理第i列（也是第i个主元）
		// 1. 选主元：找第i列中绝对值最大的行，减少浮点误差
		int r=i;
		for(int j=i+1;j<n;++j){
			if(fabs(a[j][i])>fabs(a[r][i])) r=j;
		}
		if(fabs(a[r][i])<eps) return 1;
		
		// 2. 将主元行交换到当前行（第i行）
		//选主元（目的）：1. 防止除以零  2. 保证计算精确度
		if(r!=i) swap(a[i],a[r]);
		
		// 3. 主元行归一化（让主元变成1），方便消去其他行
		double div=a[i][i];
		for(int j=i;j<=n;++j) a[i][j]/=div;
		
		// 4. 用当前行消去下面所有行的第i列
		for(int j=i+1;j<n;++j){
			double factor=a[j][i];
			for(int k=i;k<=n;++k){
				a[j][k]-=factor*a[i][k];
			}
		}
	}
	// 5. 回代（从下往上求）
	for(int i=n-1;i>=0;--i){
		for(int j=i+1;j<n;++j){
			a[i][n]-=a[i][j]*a[j][n];
			// 此时a[i][i]已经是1（之前归一化了），所以a[i][n]就是解
		}
	}
	return 0;// 唯一解
}

int main()
{
	
	return 0;
}