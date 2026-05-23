#include<bits/stdc++.h>
#define N 10005
using namespace std;

vector<int> e[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;

void tarjan(int x){
	//入x时，盖戳、入栈
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	instk[x]=1;
	for(int y:e[x]){
		if(!dfn[y]){//若y尚未访问
			tarjan(y);
			low[x]=min(low[x],low[y]);//回x时更新low
		}
		else if(instk[y]){//若y已访问且在栈中
			low[x]=min(low[x],dfn[y]);//更新low
		}
	}
	//离x时，记录scc
	if(dfn[x]==low[x]){//若x时scc的根
		int y;
		++cnt;
		do{
			y=stk[top--];
			instk[y]=0;
			scc[y]=cnt;//scc编号
			++siz[cnt];//scc大小
		}while(y!=x);
	}
}

int main()
{
	
	return 0;
}