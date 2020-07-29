a [a]
b [b]
c [c]
d [d]
e [e]
f [f]
%%
({a}{b}*{c}|({d}{e}{f})+|({a}*{d}+{e}))+ printf("ACCEPTED\n");
.* printf("NOT ACCEPTED\n");
%%
int main(){
yylex();
return 0;
}
int yywrap(){
return 1;
}