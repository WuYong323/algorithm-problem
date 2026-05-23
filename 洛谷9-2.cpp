#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long out=0;
	for (int q=1;q<=3;q++){
		for (int w=1;w<=3;w++){
			for (int e=1;e<=3;e++){
				for (int t=1;t<=3;t++){
					for (int y=1;y<=3;y++){
						for (int a=1;a<=3;a++){
							for (int s=1;s<=3;s++){
								for (int d=1;d<=3;d++){
									for (int f=1;f<=3;f++){
										for (int g=1;g<=3;g++){
											if(q+w+e+t+y+a+s+d+f+g==n){
												out++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<out<<endl;
	for (int q=1;q<=3;q++){
		for (int w=1;w<=3;w++){
			for (int e=1;e<=3;e++){
				for (int t=1;t<=3;t++){
					for (int y=1;y<=3;y++){
						for (int a=1;a<=3;a++){
							for (int s=1;s<=3;s++){
								for (int d=1;d<=3;d++){
									for (int f=1;f<=3;f++){
										for (int g=1;g<=3;g++){
											if(q+w+e+t+y+a+s+d+f+g==n){
												cout<<q<<" "<<w<<" "<<e<<" "<<t<<" "<<y<<" "<<a<<" "<<s<<" "<<d<<" "<<f<<" "<<g<<" "<<endl;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}