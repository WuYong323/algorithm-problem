#include<bits/stdc++.h>
using namespace std;

string str,in_str;
int lst[6],p=0;
int main()
{
	getline(cin,str);
	for (int i=0;i<str.size();i++) {
		if (str[i]==' '||str[i]=='.'){
			if (in_str=='one') {
				lst[p]=1*1%100;
				p++;
			}
			else if (in_str=='two') {
				lst[p]=2*2%100;
				p++;
			}
			else if (in_str=='three') {
				lst[p]=3*3%100;
				p++;
			}
			else if (in_str=='four') {
				lst[p]=4*4%100;
				p++;
			}
			else if (in_str=='five') {
				lst[p]=5*5%100;
				p++;
			}
			else if (in_str=='six') {
				lst[p]=6*6%100;
				p++;
			}
			else if (in_str=='seven') {
				lst[p]=7*7%100;
				p++;
			}
			else if (in_str=='eight') {
				lst[p]=8*8%100;
				p++;
			}
			else if (in_str=='nine') {
				lst[p]=9*9%100;
				p++;
			}
			else if (in_str=='ten') {
				lst[p]=10*10%100;
				p++;
			}
			else if (in_str=='eleven') {
				lst[p]=11*11%100;
				p++;
			}
			else if (in_str=='twelve') {
				lst[p]=12*12%100;
				p++;
			}
			else if (in_str=='thirteen') {
				lst[p]=13*13%100;
				p++;
			}
			else if (in_str=='fourteen') {
				lst[p]=14*14%100;
				p++;
			}
			else if (in_str=='fifteen') {
				lst[p]=15*15%100;
				p++;
			}
			else if (in_str=='sixteen') {
				lst[p]=16*16%100;
				p++;
			}
			else if (in_str=='seventeen') {
				lst[p]=17*17%100;
				p++;
			}
			else if (in_str=='eighteen') {
				lst[p]=18*18%100;
				p++;
			}
			else if (in_str=='nineteen') {
				lst[p]=19*19%100;
				p++;
			}
			else if (in_str=='twenty') {
				lst[p]=20*20%100;
				p++;
			}
			in_str="";
		}
		else {
			in_str+=str[i];
		}
	}
	sort(lst.begin(),lst.end());
	for (int i=0;i<lst.size();i++) {
		cout<<lst[i];
	}
	return 0;
}