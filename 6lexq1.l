a [aA]
b [bB]
c [cC]
d [dD]
%%
(({a}|{b})*({c}|{d})*)+|{a}{b}*{c}*{d} printf("ACCEPTED\n");
.* printf("NOT ACCEPTED\n");
%%
int main(){
yylex();
return 0;
}
int yywrap(){
return 1;
}