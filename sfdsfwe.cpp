#include<stdio.h>
#include<string.h>

int main() 
{
    char lst[3][10];
    char temp[10];
    for(int i=0; i<3;i++){
        scanf("%s",lst[i]);
    }
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            if(strcmp(lst[i],lst[j])>0){
                strcpy(temp,lst[i]);
                strcpy(lst[i],lst[j]);
                strcpy(lst[j],temp);
            }
        }
    }
    for(int i=0;i<3;i++) {
        printf("%s ",lst[i]);
    }
    printf("\n");
    return 0;
}