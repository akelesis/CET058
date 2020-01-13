%{

#include "parser.tab.h"
%}

/* Definições */
NUMBER [0-9]+
ID [a-zA-Z_][a-zA-Z_]*
TIPO ['int' | 'float' | 'string']+
LOGICA ['<' | '<=' | '>' | '=>' | '==' | '!=']


/* Início das Regras */
%%
{NUMBER}     {strncpy(yylval.symbol, yytext, 50); return NUM;}
{ID}         {strncpy(yylval.symbol, yytext, 50); return ID;}
[=]          {return EQ;}
[+]          {return ADD;}
"\n"         {return EOL;}
"{"          {return LCBRACES;}
"}"          {return RCBRACES;}
"("          {return LPAR;}
")"          {return RPAR;}
","          {return COMMA;}
.            {printf("Token desconhecido!"); yyterminate();}

%%
/* Fim das Regras */
/* Código C abaixo será incluído nos fontes. */

int yywrap() {}

