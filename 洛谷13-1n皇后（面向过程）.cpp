#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> answer;
vector<int> current;
vector<bool> hang_u;
vector<bool> zdui_u;
vector<bool> fdui_u;

void back_t(int row){
	if(row==n){
		answer.push_back(current);
		return;
	}
	for(int hang=0;hang<n;hang++){
		int d1=row-hang+n;
		int d2=row+hang;
		if(!hang_u[hang] && !zdui_u[d1] && !fdui_u[d2]){
			hang_u[hang]=true;
			zdui_u[d1]=true;
			fdui_u[d2]=true;
			current[row]=hang+1;
			back_t(row+1);
			hang_u[hang]=false;
			zdui_u[d1]=false;
			fdui_u[d2]=false;
		}
	}
}

int main()
{
	cin>>n;
	current.resize(n,0);
	hang_u.resize(n,false);
	zdui_u.resize(2*n,false);
	fdui_u.resize(2*n,false);
	back_t(0);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<answer.size();
	return 0;
}