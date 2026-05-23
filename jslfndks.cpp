#include<bits/stdc++.h>
int n,a[1010],res[1010],cnt;
void multiply1(){ //高精度乘法模板1
    int tmp[1010]={0};
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++) tmp[i+j]+=res[i]*a[j];
    }
    int t=0;
    for(int i=0;i<500;i++){
        tmp[i]+=t;
        res[i]=tmp[i]%10;
        t=tmp[i]/10;
    }
}
void multiply2(){ //高精度乘法模板2
    int tmp[1010]={0};
    for(int i=0;i<500;i++){
        for(int j=0;j<500;j++) tmp[i+j]+=a[i]*a[j];
    }
    int t=0;
    for(int i=0;i<500;i++){
        tmp[i]+=t;
        a[i]=tmp[i]%10;
        t=tmp[i]/10;
    }
}
void quick_pow(int p){ //快速幂
    res[0]=1,a[0]=2;
    while(p){
        if(p&1) multiply1();
        multiply2();
        p>>=1;
    }
}
int main(){
    scanf("%d",&n);
    int length=n*log10(2)+1;
    printf("%d\n",length);
    quick_pow(n);
    res[0]-=1; //为什么能减1？因为不可能退位
    for(int i=499;i>=0;i--){
        if(cnt==50) printf("\n"),cnt=0; //每50个要记得换行
        printf("%d",res[i]);
        cnt++;
    }
    return 0;
}
