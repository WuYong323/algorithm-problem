#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int lsth1[5000];
	int lstp1[5000];
	int lsth2[4000];
	int lstp2[4000];
	int hua1=0;
	int pos1=0;
	int hua2=0;
	int pos2=0;
	int z=0,p=0,m;
	while (getline(cin,str)) {
		for (m=0;m<str.size();m++){
			if (str[m]=='W') {
				hua1++;
				hua2++;
			}
			else if (str[m]=='L') {
				pos1++;
				pos2++;
			}
			if (str[m]=='E') {
				break;
			}
			if ((hua1>=11 || pos1>=11) && abs(hua1-pos1)>=2) {
				lsth1[z]=hua1;
				lstp1[z]=pos1;
				hua1=0;
				pos1=0;
				z++;
			}
			if ((hua2>=21 || pos2>=21) && abs(hua2-pos2)>=2) {
				lsth2[p]=hua2;
				lstp2[p]=pos2;
				hua2=0;
				pos2=0;
				p++;
			}
		}
		lsth1[z]=hua1;
		lstp1[z]=pos1;
		lsth2[p]=hua2;
		lstp2[p]=pos2;
		if (str[m]=='E') {
			break;
		}
	}
	for (int k=0;k<=z;k++) {
		printf("%d:%d\n",lsth1[k],lstp1[k]);
	}
	printf("\n");
	for (int k=0;k<=p;k++) {
		printf("%d:%d\n",lsth2[k],lstp2[k]);
	}
	return 0;
}