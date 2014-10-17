%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>



	int flag=0;
%}

/*  regular definitions */
chars [a-zA-Z]
digit  [0-9]
id     {chars}({chars}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
delim [ \t\n]
ws     {delim}+
oprator [\+\-\*\/\%]
other .
%%

{ws} { /* do nothing*/ }
if  printf("IF %s\n",yytext); 
then  printf("THEN %s\n",yytext); 
else  printf("ELSE %s\n",yytext); 
{id}  printf("ID %s\n",yytext); 
{number} {printf("NUMBER %s\n",yytext); }
"<" {printf("RELOP %s\n",yytext); }
"<=" {printf("RELOP %s\n",yytext); }
"=" {printf("RELOP %s\n",yytext); }
"<>" {printf("RELOP %s\n",yytext); }
">" {printf("RELOP %s\n",yytext); }
">=" {printf("RELOP %s\n",yytext); }
{oprator} printf("OPT %s\n",yytext);	
{other} printf("OTHER %s\n",yytext)	;


%%



int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
        yylex(); 
        return 0;
}

int yywrap()
{
	return 1;
}

