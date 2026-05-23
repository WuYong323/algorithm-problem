#include<iostream>
using namespace std;

int main()
{
	char lst[11][11];
	for (int i=1;i<=10;i++) {
		for (int j=1;j<=10;j++) {
			cin>>lst[i][j];
		}
		getchar();
	}
	int fx,fy,cx,cy;
	for (int i=1;i<=10;i++) {
		for (int j=1;j<=10;j++) {
			if(lst[i][j]=='F') {
				fx=i;
				fy=j;
				lst[i][j]='.';
			}
			if(lst[i][j]=='C') {
				cx=i;
				cy=j;
				lst[i][j]='.';
			}
		}
	}
	int pfx=fx,pfy=fy,pcx=cx,pcy=cy;
	int ff=0;
	int cc=0;
	int pointf=1;
	int pointc=1;
	int time=0;
	while(fx!=cx || fy!=cy) {
		if(pointf==1){
			if(lst[fx-1][fy]=='.' && fx>1) {
				fx--;
			}
			else if(lst[fx-1][fy]=='*' || fx<=1) {
				pointf=2;
			}
		}
		else if(pointf==2){
			if(lst[fx][fy+1]=='.' && fy<10) {
				fy++;
			}
			else if(lst[fx][fy+1]=='*' || fy>=10) {
				pointf=3;
			}
		}
		else if(pointf==3){
			if(lst[fx+1][fy]=='.' && fx<10) {
				fx++;
			}
			else if(lst[fx+1][fy]=='*' || fx>=10) {
				pointf=4;
			}
		}
		else if(pointf==4){
			if(lst[fx][fy-1]=='.' && fy>1) {
				fy--;
			}
			else if(lst[fx][fy-1]=='*' || fy<=1) {
				pointf=1;
			}
		}
		if(pointc==1){
			if(lst[cx-1][cy]=='.' && cx>1) {
				cx--;
			}
			else if(lst[cx-1][cy]=='*' || cx<=1) {
				pointc=2;
			}
		}
		else if(pointc==2){
			if(lst[cx][cy+1]=='.' && cy<10) {
				cy++;
			}
			else if(lst[cx][cy+1]=='*' || cy>=10) {
				pointc=3;
			}
		}
		else if(pointc==3){
			if(lst[cx+1][cy]=='.' && cx<10) {
				cx++;
			}
			else if(lst[cx+1][cy]=='*' || cx>=10) {
				pointc=4;
			}
		}
		else if(pointc==4){
			if(lst[cx][cy-1]=='.' && cy>1) {
				cy--;
			}
			else if(lst[cx][cy-1]=='*' || cy<=1) {
				pointc=1;
			}
		}
		if(pfx==fx && pfy==fy &&pcx==cx && pcy==cy &&pointf==1 &&pointc==1) {
			time=-1;
			break;
		}
		
		time++;
		if(time>10000){
			break;
		}
	}
	if(time==-1 || time>10000) {
		printf("0");
	}
	else{
		printf("%d",time);
	}
	return 0;
}