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
%token ABERTURA_PAR
%token ABERTURA_CHAVE
%token ABERTURA_COLCHETE
%token FECHAMENTO_PAR
%token FECHAMENTO_CHAVE
%token FECHAMENTO_COLCHETE
%token STRING
%token CARACTER
%token FUNCAO
%token VETOR
%token TAMANHO_VETOR
%token ELSE
%token EOL
%token VIRGULA
%token PV

%type<no> prog
%type<no> fator
%type<no> exp
%type<no> termo
%type<no> stmt
%type<no> operador
%type<no> abertura
%type<no> fechamento
%type<no> primitivas
%type<no> args
%type<no> arg
%type<no> else

%type<simbolo> LOOP
%type<simbolo> OPERACAO_LOGICA
%type<simbolo> OPERADOR_ATRIBUICAO
%type<simbolo> OPERADOR_SOMA
%type<simbolo> OPERADOR_MUL
%type<simbolo> OPERADOR_DIV
%type<simbolo> CONDICIONAL
%type<simbolo> ABERTURA_PAR
%type<simbolo> ABERTURA_CHAVE
%type<simbolo> ABERTURA_COLCHETE
%type<simbolo> FECHAMENTO_PAR
%type<simbolo> FECHAMENTO_CHAVE
%type<simbolo> FECHAMENTO_COLCHETE
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
%type<simbolo> ELSE
%type<simbolo> VIRGULA
%type<simbolo> PV


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
    | CONDICIONAL abertura exp fechamento abertura stmt  fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $5;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | CONDICIONAL abertura exp fechamento abertura stmt  fechamento else{
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $5;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | LOOP abertura exp fechamento abertura stmt  fechamento{
                            No** filhos = (No**) malloc(sizeof(No*) * 3);
                            filhos[0] = novo_no("while", NULL, 0);
                            filhos[1] = $3;
                            filhos[2] = $6;

                            $$ = novo_no("stmt", filhos, 3);
    }
    | termo abertura fechamento  {                          
                            No** filhos = (No**) malloc(sizeof(No*));
                            filhos[0] = novo_no($1, NULL, 0);
                            $$ = novo_no("funcao", filhos, 1); 
    }
    | termo abertura args fechamento  {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = $1;
                            filhos[1] = $3;

                            $$ = novo_no("funcao", filhos, 2);
    }
    | primitivas fator abertura args fechamento abertura stmt  fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 4);
                            filhos[0] = novo_no($2, NULL, 0);
                            filhos[1] = $4;
                            filhos[2] = $5;
                            filhos[3] = $7;

                            $$ = novo_no("funcao", filhos, 4);
    }
    | primitivas fator abertura fechamento abertura stmt  fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = novo_no($2, NULL, 0);
                            filhos[1] = $6;

                            $$ = novo_no("funcao", filhos, 2);
    }
;
else:
    | ELSE abertura stmt fechamento {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = novo_no("if", NULL, 0);
                            filhos[1] = $3;

                            $$ = novo_no("stmt", filhos, 2);
    }
;
args: arg                   {
                            No** filhos = (No**) malloc(sizeof(No*) * 1);
                            printf("teste args");
                            filhos[0] = $1;

                            $$ = novo_no("args", filhos, 1);
}
    | args VIRGULA arg     {
                            No** filhos = (No**) malloc(sizeof(No*) * 2);
                            filhos[0] = $1;
                            filhos[1] = $3;

                            $$ = novo_no("args", filhos, 2);

}
;
arg:                   
    | primitivas termo {
                        No** filhos = (No**) malloc(sizeof(No*) * 2);
                        filhos[0] = $1;
                        filhos[1] = novo_no($2, NULL, 0);;

                        $$ = novo_no("arg", filhos, 2);
    }
    | termo             {
                        No** filhos = (No**) malloc(sizeof(No*) * 1);
                        filhos[0] = $1;

                        $$ = novo_no("arg", filhos, 1);
    }
exp: fator
    | exp OPERADOR_SOMA fator  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("+", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
                            }
    | exp OPERADOR_SUB fator  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("-", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
                            }
    | exp OPERADOR_LOGICO_ADD fator  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("&&", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | exp OPERADOR_LOGICO_OR fator  {
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

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp($2, tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", $2);
                                    return;
                                }
                            }

                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, $2, 50);
                            strncpy(registro.tipo, $1, 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            prox_mem_livre += 4;

                            $$ = novo_no("exp", filhos, 4);
    }
    | exp OPERADOR_ATRIBUICAO stmt  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = novo_no("=", NULL, 0);
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | exp operador fator  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);
    }
    | abertura exp fechamento  {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = $2;
                            filhos[2] = $3;

                            $$ = novo_no("exp", filhos, 3);  
    }
    | primitivas fator  {
                            No** filhos = (No**) malloc(sizeof(No*)*2);
                            filhos[0] = $1;
                            filhos[1] = $2;

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp($2, tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", $2);
                                    return;
                                }
                            }
                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, $2, 50);
                            strncpy(registro.tipo, $1, 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            if(strcmp($1, "int") == 0){
                                prox_mem_livre += 4;
                                break;
                            }
                            if(strcmp($1, "int") == -3){
                                prox_mem_livre += 32;
                                break;
                            }
                            if(strcmp($1, "int") == -5){
                                prox_mem_livre += 64;
                                break;
                            }
                            if(strcmp($1, "int") == -6){
                                prox_mem_livre += 4;
                                break;
                            }
                            

                            $$ = novo_no("exp", filhos, 2);  
    }
    |primitivas abertura exp fechamento exp {
                            No** filhos = (No**) malloc(sizeof(No*)*3);
                            filhos[0] = $1;
                            filhos[1] = $3;
                            filhos[2] = $5;

                            for(int i = 0; i < prox_posicao_livre; i++){
                                if(!strcmp($5, tabela_de_simbolos[i].lexema)){
                                    printf("Variavel ja declarada! %s", $5);
                                    return;
                                }
                            }
                            RegistroTS registro;
                            strncpy(registro.token, "ID", 50);
                            strncpy(registro.lexema, $5, 50);
                            strncpy(registro.tipo, $1, 50);
                            registro.endereco = prox_mem_livre;
                            inserir_na_tabela_de_simbolos(registro);
                            if(strcmp($1, "int") == 0){
                                prox_mem_livre += (4 * atoi($3));
                                break;
                            }
                            if(strcmp($1, "int") == -3){
                                prox_mem_livre += (32 * atoi($3));
                                break;
                            }
                            if(strcmp($1, "int") == -5){
                                prox_mem_livre += (64 * atoi($3));
                                break;
                            }
                            if(strcmp($1, "int") == -6){
                                prox_mem_livre += (4 * atoi($3));
                                break;
                            }

                            $$ = novo_no("exp", filhos, 3);  
    }
    | termo abertura termo fechamento OPERADOR_ATRIBUICAO exp {
                            No** filhos = (No**) malloc(sizeof(No*)*4);
                            filhos[0] = $2;
                            filhos[1] = $4;
                            filhos[2] = novo_no("=", NULL, 0);
                            filhos[3] = $6;

                            $$ = novo_no("exp", filhos, 4);
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
abertura: ABERTURA_PAR { $$ = novo_no($1, NULL, 0); }
    | ABERTURA_CHAVE { $$ = novo_no($1, NULL, 0); }
    | ABERTURA_COLCHETE { $$ = novo_no($1, NULL, 0); }
    ;
fechamento: FECHAMENTO_PAR { $$ = novo_no($1, NULL, 0); }
    | FECHAMENTO_CHAVE { $$ = novo_no($1, NULL, 0); }
    | FECHAMENTO_COLCHETE { $$ = novo_no($1, NULL, 0); }
    ;
operador: OPERACAO_LOGICA { $$ = novo_no($1, NULL, 0); }
    ;
termo: NUMBER { $$ = novo_no($1, NULL, 0);}
    | NUMBER_FLOAT { $$ = novo_no($1, NULL, 0); }
    | VARIAVEL { $$ = novo_no($1, NULL, 0); }
    | STRING { $$ = novo_no($1, NULL, 0); }
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

