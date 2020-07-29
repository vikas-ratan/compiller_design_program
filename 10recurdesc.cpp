#include<iostream>
#include<string>
using namespace std;
bool E1(int i,string str);
bool E(int i,string str){
    if(str=="\0")
    	return 0;
    else if(str[i]=='+')
    	E1(++i,str);
    else
    	return 0;
}
bool E1(int i,string str){
	if(str=="\0")
		return 1;
	else if(str[i]=='i')
		E1(++i,str);
	else
		return 0;
}
int main()
{
	string str;
	cout<<"Production is\n";
	cout<<"E->+E'\n";
	cout<<"E'->iE'|$\n";
	cout<<"enter the string to check\n";
	cin>>str;
    if(str=="\0")
    {
    	cout<<"string is empty";
    }
    else{
(E(0,str)) ? cout<<"The inserted string is accepted \n" : 
             cout<<"The inserted string is not accepted\n";
    }
}