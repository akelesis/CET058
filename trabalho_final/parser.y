%{

/* Código C, use para #include, variáveis globais e constantes
 * este código ser adicionado no início do arquivo fonte em C
 * que será gerado.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char token[50];
    int num_filhos;
    struct No** filhos;
} No;

enum tipos{INT, FLOAT, CHAR, STR};

typedef struct registro_da_tabela_de_simbolo {
    char token[50];
    char lexema[50];
    char tipo[50];
    int endereco;
} RegistroTS;

#define TAM_TABELA_DE_SIMBOLOS 1024

RegistroTS tabela_de_simbolos[TAM_TABELA_DE_SIMBOLOS];
int prox_posicao_livre = 0;
int prox_mem_livre = 0;

No* allocar_no();
void liberar_no(No* no);
void imprimir_arvore(No* raiz);
No* novo_no(char[50], No**, int);
void imprimir_tabela_de_simbolos(RegistroTS*);
void inserir_na_tabela_de_simbolos(RegistroTS);

%}

/* Declaração de Tokens no formato %token NOME_DO_TOKEN */

%union 
{
    int number;
    char simbolo[50];
    struct No* no;
}

%token PRIMITIVAS
%token PALAVRAS_RESERVADAS
%token ESTRUTURAS
%token CONDICIONAL
%token LOOP
%token NUMBER
%token NUMBER_FLOAT
%token VARIAVEL
%token OPERACAO_LOGICA
%token OPERADOR_SOMA
%token OPERADOR_MUL
%token OPERADOR_SUB
%token OPERADOR_DIV
%token OPERADOR_LOGICO_ADD
%token OPERADOR_LOGICO_OR
%token OPERADOR_LOGICO_COMPARACAO
%token OPERADOR_LOGICO_NOT
%token OPERADOR_UNARIO
%token OPERADOR_ATRIBUICAO
%token ABERTURA
%token FECHAMENTO
%token STRING
%token CARACTER
%token FUNCAO
%token VETOR
%token TAMANHO_VETOR
%token ENDERECO
%token EOL

%type<no> prog
%type<no> fator
%type<no> exp
%type<no> termo
%type<no> stmt
%type<no> operador
%type<no> abertura
%type<no> fechamento
%type<no> primitivas
%type<no> declaracao

%type<simbolo> LOOP
%type<simbolo> OPERACAO_LOGICA
%type<simbolo> OPERADOR_ATRIBUICAO
%type<simbolo> OPERADOR_SOMA
%type<simbolo> OPERADOR_MUL
%type<simbolo> OPERADOR_DIV
%type<simbolo> CONDICIONAL
%type<simbolo> ABERTURA
%type<simbolo> FECHAMENTO
%type<simbolo> OPERADOR_SUB
%type<simbolo> OPERADOR_LOGICO_ADD
%type<simbolo> OPERADOR_LOGICO_OR
%type<simbolo> OPERADOR_LOGICO_COMPARACAO
%type<simbolo> OPERADOR_LOGICO_NOT  
%type<simbolo> PRIMITIVAS
%type<simbolo> VARIAVEL
%type<simbolo> NUMBER
%type<simbolo> NUMBER_FLOAT
%type<simbolo> STRING
%type<simbolo> CARACTER
%type<simbolo> FUNCAO


%%
/* Regras de Sintaxe */

prog:                     
    | prog stmt EOL       { imprimir_arvore($2); 
                            printf("\n");
                            imprimir_tabela_de_simbolos(tabela_de_simbolos);
                            printf("\n"); }
    ;

stmt: exp
    | CONDICIONAL abertura exp fechamento stmt {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $5;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | CONDICIONAL abertura exp fechamento abertura stmt fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $5;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | CONDICIONAL abertura stmt fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = novo_no("else", NULL, 0);
                            filhos[1] = $3;

                            $$ = novo_no("stmt", filhos, 2);
    }
    | LOOP abertura exp fechamento abertura stmt fechamento{
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("while", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $6;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | fator abertura exp fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = $1;
                            filhos[1] = $3;

                            $$ = novo_no("stmt", filhos, 2);
    }
    | primitivas fator abertura primitivas fator fechamento abertura stmt fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 5);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = $4;
                            filhos[3] = $5;
                            filhos[4] = $8;

                            $$ = novo_no("stmt", filhos, 5);
    }
    | primitivas fator abertura fechamento abertura stmt fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("funcao", NULL, 0);

                            $$ = novo_no("stmt", filhos, 3);
    }
;
exp: fator
    | exp OPERADOR_SOMA fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("+", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
                            }
    | exp OPERADOR_SUB fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("-", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
                            }
    | exp OPERADOR_LOGICO_ADD fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("&&", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | exp OPERADOR_LOGICO_OR fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("||", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | exp OPERADOR_LOGICO_COMPARACAO fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("==", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | primitivas fator OPERADOR_ATRIBUICAO stmt {
                            No** filhos = (No**) malloc(sizeof(No*)*4);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = novo_no("=", NULL, 0);
                            filhos[3] = $4;

                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, $2, 50);
                            strncpy(registro.tipo, $1, 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            prox_mem_livre += 4;

                            $$ = novo_no("exp", filhos, 4);
    }
    | exp OPERADOR_ATRIBUICAO stmt {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("=", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | exp operador fator {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | abertura exp fechamento {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);  
    }
    ;

fator: termo 
    | fator OPERADOR_MUL termo {
                                No** filhos = (No**) malloc(sizeof(No*)*3);
                                filhos[0] = $1;
                                filhos[1] = novo_no("*", NULL, 0);
                                filhos[2] = $3;

                                $$ = novo_no("termo", filhos, 3);


                                }
    | fator OPERADOR_DIV termo {
                                No** filhos = (No**) malloc(sizeof(No*)*3);
                                filhos[0] = $1;
                                filhos[1] = novo_no("/", NULL, 0);
                                filhos[2] = $3;

                                $$ = novo_no("termo", filhos, 3);
                                }
    
    ;

primitivas: PRIMITIVAS { $$ = novo_no($1, NULL, 0); }
    ;
abertura: ABERTURA { $$ = novo_no($1, NULL, 0); }
    ;
fechamento: FECHAMENTO { $$ = novo_no($1, NULL, 0); }
    ;
operador: OPERACAO_LOGICA { $$ = novo_no($1, NULL, 0); }
    ;
termo: NUMBER { $$ = novo_no($1, NULL, 0);}
    | NUMBER_FLOAT { $$ = novo_no($1, NULL, 0); }
    | VARIAVEL { $$ = novo_no($1, NULL, 0); }
    | STRING {$$ = novo_no($1, NULL, 0); }
    ;

%%

/* Código C geral, será adicionado ao final do código fonte 
 * C gerado.
 */

No* allocar_no(int num_filhos) {
    return (No*) malloc(sizeof(No)* num_filhos);
}

void liberar_no(No* no) {
    free(no);
}

No* novo_no(char token[50], No** filhos, int num_filhos) {
    No* no = allocar_no(1);    
    snprintf(no->token, 50, "%s", token);
    no->num_filhos= num_filhos;
    no->filhos = filhos;

    return no;
}

void imprimir_arvore(No* raiz) {
    
     if(raiz->filhos != NULL) {
        printf("[%s", raiz->token);
        for(int i = 0; i < raiz->num_filhos; i++) {
            imprimir_arvore(raiz->filhos[i]);
        }
        printf("]");
    }
    else {
        printf("[%s]", raiz->token);
    }
}

void inserir_na_tabela_de_simbolos(RegistroTS registro) {
    if (prox_posicao_livre == TAM_TABELA_DE_SIMBOLOS) {
        printf("Erro! Tabela de Símbolos Cheia!");
        return;
    }
    for(int i = 0; i < prox_posicao_livre; i++){
        if(tabela_de_simbolos[i].lexema == registro.lexema){
            printf("Erro! Variável já declarada!");
            return;
        }
    }
    tabela_de_simbolos[prox_posicao_livre] = registro;
    prox_posicao_livre++;
}

void imprimir_tabela_de_simbolos(RegistroTS *tabela_de_simbolos) {
    printf("----------- Tabela de Símbolos ---------------\n");
    for(int i = 0; i < prox_posicao_livre; i++) {
        printf("{%s} -> {%s} -> {%s} -> {%x}\n", tabela_de_simbolos[i].token, \
                                               tabela_de_simbolos[i].lexema, \
                                               tabela_de_simbolos[i].tipo, \
                                               tabela_de_simbolos[i].endereco);
        printf("---------\n");
    }
    printf("----------------------------------------------\n");
    printf("%d - %d", prox_mem_livre, prox_posicao_livre);
}

int main(int argc, char** argv) {
    yyparse();
}

yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
}

