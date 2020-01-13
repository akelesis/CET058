%{

/* Código C, use para #include, variáveis globais e constantes
 * este código ser adicionado no início do arquivo fonte em C
 * que será gerado.
 */

#include <stdio.h>
#include <stdlib.h>

void yyerror(char *c);
int yylex(void);


typedef struct TNode {
    char token[50];
    int childrenCount;
    struct TNode** children;
} Node;


enum types{INT, FLOAT, CHAR, STRING};

typedef struct registerToTable {
    char token[50];
    char lexema[50];
    int type;
    int addr;
} RegTable;

#define TABLE_LENGHT 1024
RegTable symbol_table[TABLE_LENGHT];
int nextPosition = 0;
int nextFreeMem = 0;
    

Node* allocNode();
void freeNode(Node* node);
void printTree(Node* root);
Node* newNode(char[50], Node**, int);
void printTable(RegTable*);
void insertIntoTable(RegTable);

%}

/* Declaração de Tokens no formato %token NOME_DO_TOKEN */

%union 
{
    int number;
    char symbol[50];
    struct Node* node;
}


%type <symbol> NUM ADD EOL ID EQ LPAR RPAR
%type <node> program stmts stmt expr block var_decl func_decl funcArgs
%type <node> identifier number callArgs

%token NUM ADD EOL ID IGUAL LCBRACES RCBRACES EQ LPAR RPAR
%token COMMA



%%
/* Regras de Sintaxe */

program : stmts                 {printf("Leitura Finalizada!");}

        ;
stmts : stmt                    {printf("Leitura stmt!");}
    | stmts stmt                {printf("Leitura stmt2!");}
    ;

stmt : var_decl | func_decl
    | expr                      {printf("%s\n", $1);}
    ;

block: LCBRACES stmts RCBRACES  {printf("%s\n", $2);}
    | LCBRACES RCBRACES         {printf("bloco vazio\n");}
    ;
var_decl : identifier identifier                {printf("%s\n", $2);}
    | identifier identifier EQ expr             {printf("%s %s %s %s\n", $1, $2, $3, $4);}
    ;

func_decl : identifier identifier LPAR funcArgs RPAR block   {printf("%s %s %s %s %s %s\n", $1, $2, $3, $4, $5, $6);}
    ;

funcArgs :                      {printf("sem argumentos");}
    | var_decl                  {printf("%s\n", $1);}
    | funcArgs COMMA var_decl   {printf("%s\n", $3);}
    ;

identifier : ID                 {printf("%s\n", $1);}
    ;

number : NUM                    {printf("%s\n", $1);}
    ;

expr : identifier EQ expr       {printf("%s %s %s\n", $1, $2, $3);}
    | identifier LPAR callArgs RPAR {printf("%s %s %s %s\n", $1, $2, $3, $4);}
    | identifier                {printf("%s\n", $1);}
    | number                    {printf("%s\n", $1);}
    ;

callArgs :                      {printf("no args\n");}
    | expr                      {printf("%s\n", $1);}
%%

/* Código C geral, será adicionado ao final do código fonte 
 * C gerado.
 */

Node* allocNode(int childrenCount) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->childrenCount = childrenCount;
    if (node->childrenCount == 0) {
        node->children = NULL;
    }

    return node;
    
}

void freeNode(Node* node) {
    free(node);
}

Node* newNode(char token[50], Node** children, int childrenCount) {
   Node* node = allocNode(childrenCount);
   node->children = children;
   snprintf(node->token, 50, "%s", token);

   return node;
}

void printTree(Node* root) {
    if(root->children != NULL) {
        printf("[%s", root->token);
        for(int i = 0; i < root->childrenCount; i++) {
            printTree(root->children[i]);
        }
        printf("]");
    }
    else {
        printf("[%s]", root->token);
    }
}

void insertIntoTable(RegTable reg) {
    if (nextPosition == TABLE_LENGHT) {
        printf("Erro! Tabela de Símbolos Cheia!");
        return;
    }
    symbol_table[nextPosition] = reg;
    nextPosition++;
}

void printTable(RegTable *symbol_table) {
    printf("----------- Tabela de Símbolos ---------------\n");
    for(int i = 0; i < nextPosition; i++) {
        printf("{%s} -> {%s} -> {%d} -> {%x}\n", symbol_table[i].token, \
                                               symbol_table[i].lexema, \
                                               symbol_table[i].type, \
                                               symbol_table[i].addr);
        printf("---------\n");
    }
    printf("----------------------------------------------\n");
}

void yyerror(char *c){
    printf("meu erro foi: %s\n", c);
}

int main(int argc, char** argv) {
    yyparse();
    return 0;
}
