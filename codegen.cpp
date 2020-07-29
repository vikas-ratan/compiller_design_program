#include<bits/stdc++.h>
struct table
{
char op[5],arg1[5],arg2[5];
}t[10];
void main()
{
clrscr();
int i,j=0,k=0;
char s[30];
cout<<"\n Generation of 3 addr code triple implementation";
while(1)
{
cout<<"\n For exit press ~ \n else enter the expression";
gets(s);
if(!strcmp(s,"~"))
break;
i=strlen(s)-1;
t[j].arg2[k]=s[i];
t[j].op[k]=s[i-1];
t[j].arg1[k]=s[i-2];
coutif(l==8)
cout<<"+";
else
cout<<"-";
for( i=strlen(s)-4;i>0;i-=2)
{
t[j].op[k]=s[i];
t[j].arg1[k]=s[i-1];
itoa(j-1,t[j].arg2,10);
cout}
}
cout<<"the end";
//getch();
}