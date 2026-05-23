#include<stdio.h>

int xa(int num);
int uim(int num);
int xb(int num);
int zm(int num);

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d %d %d %d", xa(x), uim(x), xb(x), zm(x));
    return 0;
}

int xa(int num) 
{
    if (num % 2 == 0 && num > 4 && num <= 12) {
        return 1;
    } 
	else {
        return 0;
    }
}

int uim(int num) 
{
    if (num % 2 == 0 || (num > 4 && num <= 12)) {
        return 1;
    } 
	else {
        return 0;
    }
}

int xb(int num) 
{
    if (num % 2 == 0 && !(num > 4 && num <= 12)) {
        return 1;
    } 
    else if (num % 2 != 0 && (num > 4 && num <= 12)) {
    	return 1;
	}
	else {
        return 0;
    }
}

int zm(int num) 
{
    if (num % 2 != 0 && !(num > 4 && num <= 12)) {
        return 1;
    } 
	else {
        return 0;
    }
}