z [0]
o [1]
%%
({z}|{o})*|({z}*{o}*) printf("ACCEPTED\n");
.* printf("NOT ACCEPTED\n");
%%
int main(){
yylex();
return 0;
}
int yywrap(){
return 1;
}