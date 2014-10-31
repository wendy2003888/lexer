%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>



	int lcnt=1;
%}

/*  regular definitions */
chars [a-zA-Z]
digit  [0-9]
id     {chars}({chars}|{digit})*
number {digit}+(\.{digit}+)?(E[+-]?{digit}+)?
delim [ \t]
line [\n]
ws     {delim}+
compare [><]=?|[!=]=
relation &&|\|\|
operator [\+\-\*\/\%\&\^\|\~\!\=]
other .
separate [\{\}\(\)\;]
%%

{ws} { /* do nothing*/ }
{line} {lcnt++;}
if  printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
then  printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
else  printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
while printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
int   printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
double printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
float  printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
const  printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
do     printf("Line: %d KEYWORD: %s\n",lcnt,yytext); 
return printf("Line: %d KEYWORD: %s\n",lcnt,yytext);
main   printf("Line: %d KEYWORD: %s\n",lcnt,yytext);
{id}  printf("Line: %d ID %s\n",lcnt,yytext); 
{number} {printf("Line: %d NUMBER %s\n",lcnt,yytext); }
{compare} printf("Line: %d CMP: %s\n",lcnt,yytext); 
{operator} printf("Line: %d OPERATOR %s\n",lcnt,yytext);
{relation}	printf("Line: %d RLT: %s\n",lcnt,yytext); 
{separate}  printf("Line: %d SPT: %s\n",lcnt,yytext); 
{other} printf("Line: %d OTHER %s\n",lcnt,yytext)	;


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

