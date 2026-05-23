#include<bits/stdc++.h>
using namespace std;

string str,in_str;
int lst[10],p=0;
int main()
{
	getline(cin,str);
	unordered_map<string,int>wordtonum={{"one",1},{"two",2},{"three",3},{"four",4},{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9},{"ten",10},{"eleven",11},{"twelve",12},{"thirteen",13},{"fourteen",14},{"fifteen",15},{"sixteen",16},{"seventeen",17},{"eighteen",18},{"nineteen",19},{"twenty",20},{"a",1},{"both",2},{"another",1},{"first",1},{"second",2},{"third",3}};
	for (int i=0;i<str.size();i++) {
		if (str[i]==' '||str[i]=='.'){
			auto it=wordtonum.find(in_str);
			if (it!=wordtonum.end()) {
				int z=it->second;
				lst[p]=z*z%100;
				/*if (l<10 && p!=0) {
					lst[p]=0;
					lst[p=p+1]=l;
				}
				else {
					lst[p]=l;
				}*/
				p++;
			}
			in_str="";
		}
		else {
			in_str+=str[i];
		}
	}
	if(p==0) {
		cout<<0;
		return 0;
	}
	sort(lst,lst+p);
	for (int i=0;i<p;i++) {
		if (lst[i]<10 && i!=0){
			cout<<"0"<<lst[i];
		}
		else{
			cout<<lst[i];
		}
	}
	return 0;
}