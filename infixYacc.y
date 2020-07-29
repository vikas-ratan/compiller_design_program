%{
    #include<stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%token INTEGER
%%
P: P E '\n' {
    printf("\n");
}
|
;
E: E '+' T {printf("+"); }
| E '-' T { printf("-"); }
| T { $$=$1; }
T: T '*' F {   printf("*"); }
| T '/' F { printf("/");}
| T '%' F { printf("\%"); }
| F {   $$=$1;}
;
F: '(' E ')' {   $$=$2; }
| INTEGER {   $$=$1; printf("%d",$1);}
;
%%
void yyerror(char *s){
    fprintf(stderr,"%s\n",s);
}
int main(void){
    yyparse();
    return 0;
}