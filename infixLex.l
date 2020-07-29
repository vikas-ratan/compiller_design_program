%{
    #include<stdlib.h>
    void yyerror(char *);
    #include"infixYacc.tab.h"
%}
%%
[0-9]+ {
    yylval=atoi(yytext);
    return INTEGER;
}
[-%()+*\/\n] return *yytext;
[\t] ;
. yyerror("Invalid Token");
%%
int yywrap(void){
    return 1;
}