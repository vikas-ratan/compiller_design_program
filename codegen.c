#include<stdio.h>
#include<string.h>
void pm();
void plus();
void div();
int i,ch,j,l,addr=100;
char ex[10],exp[10],exp1[10],id1[5],op[5],id2[5];
void main()
{
printf("\nEnter the expression : ");
scanf("%s",ex);
strcpy(exp,ex);
l=strlen(exp);
exp1[0]='\0';
for(i=0;i<l;i++)
{
if(exp[i]=='+'||exp[i]=='-')
{
if(exp[i+2]=='/'||exp[i+2]=='*')
{
pm();
break;
}
else
{
plus();
break;
}
}
else if(exp[i]=='/'||exp[i]=='*')
{
div();
break;
}
}
}
void pm()
{
strrev(exp);
j=l-i-1;
strncat(exp1,exp,j);
strrev(exp1);
printf("Three address code:\nt1=%s\nt2=%c%ct1\n",exp1,exp[j+1],exp[j]);
printf("a=t2");
}
void div()
{
strncat(exp1,exp,i+4);
printf("Three address code:\nt1=%s\nt2=t1%c%c\n",exp1,exp[i+2],exp[i+3]);
}
void plus()
{
strncat(exp1,exp,i+4);
printf("Three address code:\nt1=%s\nt2=t1%c%c\n",exp1,exp[i+2],exp[i+3]);
printf("a=t2");
}

