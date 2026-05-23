#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> memo={{"BangZhu",1},{"FuBangZhu",2},{"HuFa",3},{"ZhangLao",4},{"TangZhu",5},{"JingYing",6},{"BangZhong",7}};

struct people{
	string name;
	string zhiwei;
	int bg;
	int lv;
	int index;
}man[150];

bool tel(people a,people b){
	if(a.bg!=b.bg){
		return a.bg>b.bg;
	}
	else{
		return a.index<b.index;
	}
}

bool telll(people a,people b){
	if(memo[a.zhiwei]!=memo[b.zhiwei]){
		return memo[a.zhiwei]<memo[b.zhiwei];
	}
	else{
		if(a.lv!=b.lv){
			return a.lv>b.lv;
		}
		else{
			if(a.index!=b.index){
				return a.index<b.index;
			}
		}
	}
	return true;
}

bool te(people a,people b){
	return memo[a.zhiwei]<memo[b.zhiwei];
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>man[i].name>>man[i].zhiwei>>man[i].bg>>man[i].lv;
		man[i].index=i;
	}
	sort(man+1,man+1+n,te);
	sort(man+4,man+n+1,tel);
	int tt=1;
	while(tt<=n-3){
		if(tt<=2){
			man[3+tt].zhiwei="HuFa";
		}
		else if(tt<=6){
			man[3+tt].zhiwei="ZhangLao";
		}
		else if(tt<=13){
			man[3+tt].zhiwei="TangZhu";
		}
		else if(tt<=38){
			man[3+tt].zhiwei="JingYing";
		}
		else {
			man[3+tt].zhiwei="BangZhong";
		}
		tt++;
	}
	sort(man+1,man+n+1,telll);
	for(int i=1;i<=n;i++){
		cout<<man[i].name<<" "<<man[i].zhiwei<<" "<<man[i].lv<<endl;
	}
	return 0;
}