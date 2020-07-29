
//Write a program to parse a string BY SLR Parser
//Program is:

#include<bits/stdc++.h>
#define present(c, x) (c.find(x) != c.end())
using namespace std;
string to_string(char x) 
{ 
    string s(1, x); 
    return s;    
}

int main()
{
	cout<<"The production is:"<<endl;
	cout<<"E->E+T"<<endl;
	cout<<"E->T"<<endl;
	cout<<"T->T*F"<<endl;
	cout<<"F"<<endl;
	cout<<"F->(E)"<<endl;
	cout<<"F->id"<<endl;

    string inputState[12]={"0","1","2","3","4","5","6","7","8","9","10","11"};
    string inputSymbol[9]={"+","*","i","(",")","$","E","T","F"};
    map< pair<string,string>, string > mp;
    cout<<"Enter parse Table \n";
    string s;
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<"I"<<inputState[i]<<" "<<inputSymbol[j]<<" : ";
            cin>>s; 
            mp[make_pair(inputState[i],inputSymbol[j])]=s;
        }
    }
    
    stack<string> stk;
    stk.push("$");
    stk.push("0");
    string InputBuffer;
    cout<<"\nEnter the string to be parsed ";
    cin>>InputBuffer;
    InputBuffer+="$";
    cout<<"The TABLE is :"<<endl;
	 for(int i=0;i<12;i++)
   {
       for(int j=0;j<9;j++)
       {
           cout<<mp[make_pair(inputState[i],inputSymbol[j])]<<"\t";
       }
       cout<<endl;
   }
    int i=0;
    map<string,pair<int,string> > m;
    m["1"]={3,"E"};
    m["2"]={1,"E"};
    m["3"]={3,"T"};
    m["4"]={1,"T"};
    m["5"]={3,"F"};
    m["6"]={1,"F"};
    while(InputBuffer[i]!='\0')
    {
        cout<<stk.top()<<" "<<to_string(InputBuffer[i])<<endl;
        if(!present(mp,make_pair(stk.top(),to_string(InputBuffer[i]))))
            {cout<<"Error\n"<<endl;exit(0);}
        auto it=mp.find(make_pair(stk.top(),to_string(InputBuffer[i])));
        string temp=it->second;
            if(temp[0]=='A')
                {cout<<"Input is successfully parsed\n"; exit(0);}
            else if(temp[0]=='s')
                {
                    stk.push(to_string(InputBuffer[i]));
                    stk.push(to_string(temp[1]));
                    i++;
                }
            else if(temp[0]=='r')
            {
                string t=to_string(temp[1]);
                int tt=2*(m[t].first);
                while(tt--)
                    stk.pop();
                string prev=stk.top();
                stk.push(m[t].second);
                auto itt=mp.find(make_pair(prev,stk.top()));
                stk.push(itt->second);
            }
            else
                {   cout<<"Error string cant be parsed \n";exit(0);}
    }
    return 0;
}
