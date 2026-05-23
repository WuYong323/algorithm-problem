#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char lst[1000];
	scanf("%s",lst);
	const char *lst1[10][5]={
		{"XXX", "X.X", "X.X", "X.X", "XXX"},
		{"..X", "..X", "..X", "..X", "..X"},
		{"XXX", "..X", "XXX", "X..", "XXX"}, 
        {"XXX", "..X", "XXX", "..X", "XXX"}, 
        {"X.X", "X.X", "XXX", "..X", "..X"}, 
        {"XXX", "X..", "XXX", "..X", "XXX"}, 
        {"XXX", "X..", "XXX", "X.X", "XXX"}, 
        {"XXX", "..X", "..X", "..X", "..X"}, 
        {"XXX", "X.X", "XXX", "X.X", "XXX"}, 
        {"XXX", "X.X", "XXX", "..X", "XXX"}
	};
	for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            int a = lst[i]-'0';
            printf("%s", lst1[a][row]);
            if (i < n - 1) {
                printf(".");
            }
        }
        printf("\n");
    }
	return 0;
}