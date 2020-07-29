#include<bits/stdc++.h>
using namespace std;
int main(){
	int flag=0,i=0;
	string s;
	cin>>s;
	while(s[i]!='\0'){
		if(s[i]=='a' and (s[i+1]=='b' or s[i+1]=='c')){
			int j=i+1;
			while(s[j]=='b'){
				j++;
			}
			if(s[j]=='c'){
				flag=1;
				i=j+1;
				continue;
			}
			else{
				flag=0;
				break;
			}
		}
		else if(s[i]=='a' and (s[i+1]=='a' or s[i+1]=='d')){
			int j=i+1;
			while(s[j]=='a'){
				j++;
			}
			if(s[j]=='d'){
				continue;
				j++;
				while(s[j]=='d'){
					j++;
				}
				if(s[j]=='e'){
					flag=1;
					i=j+1;
				}
			}
			else{
				flag=0;
				break;
			}
		}
		else if(s[i]=='d' and s[i+1]=='e' and s[i+2]=='f'){
			flag=1;
			i=i+3;
		}
		else if(s[i]=='d'){
			int j=i+1;
			while(s[j]=='d'){
				j++;
			}
			if(s[j]=='e'){
				flag=1;
				i=j+1;
			}
			else{
				flag=0;
				break;
			}
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<"ACCEPTED\n";
	}
	else{
		cout<<"NOT ACCEPTED\n";
	}

}
