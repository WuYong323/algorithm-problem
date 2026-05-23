#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int lsta[a],lstb[b];
	int counta=0,countb=0;
	for (int i=0;i<a;i++) {
		cin>>lsta[i];
	}
	for (int i=0;i<b;i++) {
		cin>>lstb[i];
	}
	for (int i=0;i<n;i++ ){
		if(lsta[i%a]==0) {
			if (lstb[i%b]==1) {
				countb++;
			}
			else if (lstb[i%b]==2) {
				counta++;
			}
			else if(lstb[i%b]==3) {
				counta++;
			}
			else if(lstb[i%b]==4) {
				countb++;
			}
		}
		else if (lsta[i%a]==1) {
			if(lstb[i%b]==2){
				countb++;
			}
			else if(lstb[i%b]==3) {
				counta++;
			}
			else if (lstb[i%b]==4){
				countb++;
			}
			else if (lstb[i%b]==0) {
				counta++;
			}
		}
		else if(lsta[i%a]==2) {
			if (lstb[i%b]==3) {
				countb++;
			}
			else if(lstb[i%b]==4) {
				counta++;
			}
			else if(lstb[i%b]==0) {
				countb++;
			}
			else if(lstb[i%b]==1) {
				counta++;
			}
		}
		else if(lsta[i%a]==3) {
			if(lstb[i%b]==4) {
				counta++;
			}
			else if(lstb[i%b]==0) {
				countb++;
			}
			else if(lstb[i%b]==1) {
				countb++;
			}
			else if(lstb[i%b]==2) {
				counta++;
			}
		}
		else if(lsta[i%a]==4) {
			if(lstb[i%b]==0) {
				counta++;
			}
			else if(lstb[i%b]==1) {
				counta++;
			}
			else if(lstb[i%b]==2) {
				countb++;
			}
			else if(lstb[i%b]==3) {
				countb++;
			}
		}
	}
	cout<<counta<<" "<<countb;
	return 0;
}