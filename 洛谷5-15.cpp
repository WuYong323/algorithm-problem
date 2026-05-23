#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str,in_str;
	int p,i;
	getline(cin,in_str);
	getline(cin,str);
	for (int k=0;k<strlen(str);k++) {
		if (str[k]<='Z') {
			str[k]=str[k]+32;
		}
	}
	for (int k=0;k<strlen(in_str);k++) {
		if (in_str[k]<='Z') {
			in_str[k]=in_str[k]+32;
		}
	}
	char *result=strstr(str,in_str);
	if (result) {
		p=1;
		i=result-str;
	}
	else {
		p=-1;
		cout<<p;
	}
	while (strstr(result,in_str)!=NULL) {
		result=strstr(result,in_str);
		p++;
	}
	if (p>0){
		cout<<p<<i<<endl;
	}
	return 0;
}