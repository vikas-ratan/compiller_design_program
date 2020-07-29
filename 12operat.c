#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
 char stack[20],ip[20],opt[10][10][1],ter[10]={'+','-','*','(',')','i','$'};
 int i,j,k,n=7,top=0,col,row;
 /*for(i=0;i<10;i++)
 {
  stack[i]=NULL;
  ip[i]=NULL;
  for(j=0;j<10;j++)
  {
   opt[i][j][0]=NULL;
  }
 }*/
 printf("The production is\n");
 printf("E->E+E\nE->E-E\nE->E*E\nE->(E)\nE->i\n");
 printf("\nEnter the table values:\n");
 for(i=0;i<n;i++)
{
   for(j=0;j<n;j++)
  {
     printf("Enter the value for %c %c:",ter[i],ter[j]);
     scanf(" %s",opt[i][j]);
   }
}
printf("\nOPERATOR PRECEDENCE TABLE:\n");
for(i=0;i<n;i++)
{
  printf("\t%c",ter[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
    printf("\n%c",ter[i]);
    for(j=0;j<n;j++)
    {
        printf("\t%c",opt[i][j][0]);

     }
  }
  stack[top]='$';
  printf("\nEnter the input string:");
  scanf(" %s",ip);
  i=0;
  printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
  printf("\n%s\t\t\t%s\t\t\t",stack,ip);
  while(i<=strlen(ip))
 {
 for(k=0;k<n;k++)
 {
  if(stack[top]==ter[k])
  row=k;
  if(ip[i]==ter[k])
  col=k;
 }
 if((stack[top]=='$')&&(ip[i]=='$')){
  printf("String is accepted");
  break;
}
 else if((opt[row][col][0]=='<') ||(opt[row][col][0]=='='))
 {
  stack[++top]=opt[row][col][0];
  stack[++top]=ip[i];
  printf("Shift %c",ip[i]);
  i++;
 }
 else
 {
  if(opt[row][col][0]=='>')
  {
   while(stack[top]!='<')
   --top;
   top=top-1;
   printf("Reduce");
  }
  else
  {
   printf("\nString is not accepted");
   break;
  }
 }
 printf("\n");
 for(k=0;k<=top;k++)
          printf("%c",stack[k]);
        printf("\t\t\t");
 for(k=i;k<strlen(ip);k++)
  printf("%c",ip[k]);

 printf("\t\t\t");
}
getch();
}