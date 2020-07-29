digits [0-9]
letters [a-zA-Z]
plus [+]
minus [-]
mul [*]
div [/]

%%

({digits}+(.{digits}+)?(E(\+|\-))?({digits}+)?) printf("Entered token is a number.\n");
(>|>=|<|<=|=|==) printf("Entered token is relational operator.\n");
({plus}|{minus}|{mul}|{div}) printf("Entered token is Arthimetic operator.\n");
(if|else|elseif|int|float|printf) printf("enter no is Keyword");
{letters}({letters}|{digits})* printf("entered token is identifier");
.* printf("enter string is token.\n");

%%

int main()
{
	yylex();
	return 0;
}
int yywrap()
{
	return 1;
}