#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lstn[n];
	for (int z=0;z<n;z++) {
		scanf("%d",&lstn[z]);
	}
	char lst[5][4*n-1];
	for (int z=0;z<5;z++) {
		for (int m=0;m<4*n-1;m++) {
			lst[z][m]= "." ;
	    }
	}
	for (int z=0;z<n;z++) {
		if (lstn[z]==0) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[4][z*4]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==1) {
			lst[1][z*4+2]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4+2]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4+2]="X";
		}
		else if (lstn[z]==2) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==3) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==4) {
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4+2]="X";
			lst[2][z*4]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4+2]="X";
		}
		else if (lstn[z]==5) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==6) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
    		lst[1][z*4]="X";
			lst[2][z*4]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==7) {
			lst[1][z*4]="X";
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4+2]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4+2]="X";
		}
		else if (lstn[z]==8) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
		else if (lstn[z]==9) {
			lst[1][z*4+1]="X";
			lst[1][z*4+2]="X";
			lst[1][z*4]="X";
			lst[2][z*4]="X";
			lst[2][z*4+2]="X";
			lst[3][z*4]="X";
			lst[3][z*4+2]="X";
			lst[3][z*4+1]="X";
			lst[4][z*4+2]="X";
			lst[5][z*4]="X";
			lst[5][z*4+2]="X";
			lst[5][z*4+1]="X";
		}
	}
	for (int i=0;i<5;i++) {
		for (int j=0;j<4*n-1;j++) {
			printf("%s",lst[i][j]);
		}
		printf("\n");
	}
	return 0;
}