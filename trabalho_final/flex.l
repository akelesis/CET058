/* 
Crie um Analisador Léxico utilizando Flex que consiga gerar os tokens
do arquivo de entrada "exercicio01.in" que consiste em um código na
linguagem C. O analisador deverá identificar todos os tokens referentes a:

1. Identificadores
2. Números Inteiros
3. Números de Ponto Flutuante
4. Palavras reservadas
5. Operadores Matemáticos e Relacionais
6. Chaves, Colchetes e Chaves

utilize os exemplos no diretório "flex" como ponto de partida.
*/

/* colocando identificadores */



%{
	#include "parser.tab.h"
%}

PRIMITIVAS									"int"|"float"|"char"|"double"|"unsigned"|"signed"|"void"|"string"
PALAVRAS_RESERVADAS							"break"|"return"|"continue"
ESTRUTURAS									"struct"|"typedef"
CONDICIONAL									"if"|"else"|"switch"|"case"|"default"
LOOP										"while"|"for"|"do"|"goto"
NUMBER										([0-9]+)
NUMBER_FLOAT								([0-9]+)*[.]([0-9]+)
VARIAVEL   									[_a-zA-Z][_a-zA-Z0-9]*
OPERADOR_LOGICO_ADD							"&&"
OPERADOR_LOGICO_OR							"||"
OPERADOR_LOGICO_COMPARACAO 					"=="
OPERADOR_LOGICO_NOT							"!"
OPERACAO_LOGICA								"<"|">"|"<="|">="
OPERADOR_UNARIO								("++"|"--"|"!")([a-zA-Z]*)|([a-zA-Z]*)("++"|"--"|"!")
OPERADOR_ATRIBUICAO							"="
ABERTURA									"\("|"\{"
FECHAMENTO									"\)"|"\}"
STRING										\"(\\.|[^"\\])*\"
CARACTER 									(\')(.)(\')
ENDERECO									[a-zA-Z]+|([a-zA-Z][_a-zA-Z0-9]*)(\[)([0-9]+|([a-zA-Z]+)(\]))
%%

{PRIMITIVAS}								{strncpy(yylval.simbolo, yytext, 50); return PRIMITIVAS;}
{PALAVRAS_RESERVADAS}						{return PALAVRAS_RESERVADAS;}
{CONDICIONAL} 								{strncpy(yylval.simbolo, yytext, 50); return CONDICIONAL;}
{LOOP}										{strncpy(yylval.simbolo, yytext, 50); return LOOP;}
{ESTRUTURAS}								{return ESTRUTURAS;}
{NUMBER}									{strncpy(yylval.simbolo, yytext, 50); return NUMBER;}
{NUMBER_FLOAT}								{strncpy(yylval.simbolo, yytext, 50); return NUMBER_FLOAT;}
{VARIAVEL}									{strncpy(yylval.simbolo, yytext, 50); return VARIAVEL;}
"\+"										{return OPERADOR_SOMA;}
"\*"										{return OPERADOR_MUL;}
"/"											{return OPERADOR_DIV;}
"\-"										{return OPERADOR_SUB;}
{OPERACAO_LOGICA}							{strncpy(yylval.simbolo, yytext, 50); return OPERACAO_LOGICA;}
{OPERADOR_LOGICO_ADD}						{return OPERADOR_LOGICO_ADD;}
{OPERADOR_LOGICO_OR}						{return OPERADOR_LOGICO_OR;}
{OPERADOR_LOGICO_COMPARACAO}				{return OPERADOR_LOGICO_COMPARACAO;}
{OPERADOR_LOGICO_NOT}						{return OPERADOR_LOGICO_NOT;}
{OPERADOR_UNARIO}							{return OPERADOR_UNARIO;}
{OPERADOR_ATRIBUICAO}						{return OPERADOR_ATRIBUICAO;}
{ABERTURA}									{strncpy(yylval.simbolo, yytext, 50); return ABERTURA;}
{FECHAMENTO}								{strncpy(yylval.simbolo, yytext, 50); return FECHAMENTO;}
{STRING}									{strncpy(yylval.simbolo, yytext, 50); return STRING;}
{CARACTER}									{strncpy(yylval.simbolo, yytext, 50); return CARACTER;}
{ENDERECO}									{return ENDERECO;}
"\n"                            			{return EOL;}

%%

int yywrap() {}
