#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	unordered_map<char,int>wordtonum;
	for (char c='A';c<='Z';c++) {
		wordtonum[c]=0;
	}
	for (int i=1;i<=4;i++) {
		getline(cin,str);
		for(int j=0;j<str.size();j++) {
			auto it=wordtonum.find(str[j]);
			if (it!=wordtonum.end()) {
				it->second++;
			}
		}
	}
	int ma=0;
	for (char i='A';i<='Z';i++) {
		if(ma<wordtonum[i]) {
			ma=wordtonum[i];
		}
	}
	for (int i=0;i<ma;i++){
		for (char j='A';j<='Z';j++) {
			if (i>=ma-wordtonum[j]) {
				printf("* ");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
	for (char i='A';i<='Z';i++) {
		printf("%c ",i);
	}
	return 0;
}
