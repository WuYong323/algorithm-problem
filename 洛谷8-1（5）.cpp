#include<bits/stdc++.h>
using namespace std;

int a[100];
int n;

void quickSort(int left,int right){
	if(left>=right) return;
	int i=left;
	int j=right;
	int mid=(left+right)/2;
	int p=a[mid];
	while (i<=j){
		while (a[i]<p) i++;
		while (a[j]>p) j--;
		if(i<=j) {
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(left<j) quickSort(left,j);
	if(i<right) quickSort(i,right);
}
int main()
{
	
}