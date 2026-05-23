#include<bits/stdc++.h>
using namespace std;

struct lst{
	int x;
	int y;
}lst1[20];
int times=1;
int n;
bool btu[410][410];
double tu[410][410]; 
queue <pair<int,int>> q;

double fun(int a1,int b1,int a2,int b2){
	return pow((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2),0.5);
}


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x1,y1;
		cin>>x1>>y1;
		lst1[i].x=x1+205;
		lst1[i].y=y1+205;
	}
	memset(btu,false,sizeof(btu));
	memset(tu,0,sizeof(tu));
	btu[205][205]=true;
	q.push(make_pair(205,205));
	while(!q.empty()){
		if(times==n){
			return 0;
		}
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		for(int i=1;i<=n;i++){
			int u=lst1[i].x;
			int v=lst1[i].y;
			if(u>=5&&u<=405&&v>=5&&v<=405&&!btu[u][v]){
				tu[u][v]=tu[xx][yy]+fun(u,v,xx,yy);
				btu[u][v]=true;
				q.push(make_pair(u,v));
			}
		}
		times++;
	}
	double sum=0;
	for(int i=1;i<=n;i++){
		sum=max(sum,tu[lst1[i].x][lst1[i].y]);
	}
	printf("%.2f",sum);
	return 0;
}