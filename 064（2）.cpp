#include<bits/stdc++.h>
using namespace std;

int n;
string str;

int main()
{
    cin>>n;
	getchar();
    while(n--){
        getline(cin,str);
        cout<<str<<endl;
        cout<<"AI: ";
        int t=str.length();
        int pos1,pos2;
        size_t pos;
        for(int i=0;i<t;++i){
            if(str[i]>='A'&&str[i]<='Z'&&str[i]!='I') str[i]+=32;
        }
        pos=str.find(" I ");
        if(pos!=string::npos){
            str.replace(pos,pos+2," you ");
        }
        pos=str.find(" me ");
        if(pos!=string::npos){
            str.replace(pos,pos+3," you ");
        }
        pos=str.find("?");
        if(pos!=string::npos){
            str.replace(pos,pos,"!");
        }
        pos=str.find("can you ");
        if(pos!=string::npos){
            str.replace(pos,pos+8,"I can ");
        }
        pos=str.find("could you ");
        if(pos!=string::npos){
            str.replace(pos,pos+10,"I could ");
        }
        pos=str.find("!");
        for(int i=pos-1;;i--){
            if(str[i]==' ') str.erase(i,1);
            else if(str[i]!=' ') break;
        }
        pos=str.find(",");
        for(int i=pos-1;;i--){
            if(str[i]==' ') str.erase(i,1);
            else if(str[i]!=' ') break;
        }
        t=str.length();
        for(pos1=0;pos1<t;++pos1){
            if(str[0]!=' ') break;
            if(str[pos1-1]==' '&&str[pos1]!=' ') break;
        }
        for(pos2=t-1;pos2>=0;--pos2){
            if(str[pos2]!=' ') break;
            if(str[pos2+1]==' '&&str[pos2]!=' ') break;
        }
        bool flag=0;
        for(int i=pos1;i<=pos2;++i){
            if(str[i]==' '){
            	if(!flag){
            		flag=1;
                	cout<<" ";
				}
				else continue;
            }
            else{
            	flag=0;
            	cout<<str[i];
			}
        }
        cout<<endl;
    }
    return 0;
}