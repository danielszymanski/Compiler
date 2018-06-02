%{
#include <stdlib.h>
#include <string.h>
#include "def.tab.hh"
extern int yylineno;
int yyerror(const char *msg,...);
%}
%%
"int"				{return INT;}
"float"			{return FLOAT;}
"if"				{return IF;}
"else"			{return ELSE;}
"print"			{return PRINT;}
"read"			{return READ;}
"for"				{return FOR;}
"@"			{return '@';};
\,			{return ',';}
\{			{return '{';}
\}			{return '}';}
\[			{return '[';}
\]			{return ']';}
\(			{return '(';}
\)			{return ')';}
\^			{return '^';}
\*			{return '*';}
\/			{return '/';}
\+			{return '+';}
\-			{return '-';}
\.			{return '.';}
\<			{return LT;}
\>			{return GT;}
\<\=			{return LE;}
\>\=			{return GE;}
\=\=			{return EQ;}
\=			{return '=';}
\;			{return ';';}



[1-9][0-9]*[.][0-9]+|0[.][0-9]+	{yylval.fval = atof(yytext);return LZ;}
0|[1-9][0-9]*		{yylval.ival = atoi(yytext);return LC;}
[A-Za-z_][A-Za-z0-9_]*	{yylval.text = strdup(yytext);return ID;}
\"[^\"]*\"			 {yylval.text = strdup(yytext); return STRING;}
\ |\t			{;}
\n			{yylineno++ ;}
.			{yyerror("Blad leksykalny\n");}
%%
int yyerror(const char *msg,...)
{
	printf("%d: %s", yylineno, msg);
	exit(1);
}
