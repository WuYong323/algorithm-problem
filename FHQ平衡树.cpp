#include<bits/stdc++.h>
#define N 100005
using namespace std;

struct node{
	int l,r;   //左右儿子
	int val;   //树的权值
	int key;   //堆的随机值
	int size;   //子树大小
}tr[N];

int n,root,idx;

int newnode(int v){
	tr[++idx].val=v;
	tr[idx].key=rand();
	tr[idx].size=1;
	return idx;
}

void pushup(int p){
	tr[p].size=tr[tr[p].l].size+tr[tr[p].r].size+1;
}

//分裂（split）
void split(int p,int v,int &x,int &y){
	if(!p){
		x=y=0;
		return;
	}
	if(tr[p].val<=v){
		x=p;
		split(tr[x].r,v,tr[x].r,y);
	}
	else{
		y=p;
		split(tr[y].l,v,x,tr[y].l);
	}
	pushup(p);
}

//合并（merge）
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(tr[x].key<tr[y].key){
		tr[x].r=merge(tr[x].r,y);
		pushup(x);
		return x;
	}
	else{
		tr[y].l=merge(x,tr[y].l);
		pushup(y);
		return y;
	}
}

//插入（insert）
void insert(int v){
	int x,y,z;
	split(root,v,x,y);
	z=newnode(y);
	root=merge(merge(x,z),y);
}

//删除（del）
void del(int v){
	int x,y,z;
	split(root,v,x,z);
	split(x,v-1,x,y);
	y=merge(tr[y].l,tr[y].r);
	root=merge(merge(x,y),z);
}

int get_k(int p,int k){   //返回第k个节点
	if(k<=tr[tr[p].l].size){
		return get_k(tr[p].l,k);
	}
	if(k==tr[tr[p].l].size+1){
		return p;
	}
	return get_k(tr[p].r,k-tr[tr[p].l].size-1);
}

void get_pre(int v){   //前缀
	int x,y;
	split(root,v-1,x,y);
	int p=get_k(x,tr[x].size);
	printf("%d\n",tr[p].val);
	root=merge(x,y);
}

void get_suc(int v){   //后缀
	int x,y;
	split(root,v,x,y);
	int p=get_k(y,1);
	printf("%d\n",tr[p].val);
	root=merge(x,y);
}

void get_rank(int v){   //排名
	int x,y;
	split(root,v-1,x,y);
	printf("%d\n",tr[x].size+1);
	root=merge(x,y);
}

void get_val(int k){    //数值
	int p=get_k(root,k);
	printf("%d\n",tr[p].val);
}

int main()
{
	
	return 0;
}