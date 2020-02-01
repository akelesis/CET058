Trabalho Final de Compiladores
==============================
Introdução
----------
Um compilador é a ferramenta utilizada para realizar a tradução de uma linguagem de programação para a linguagem de máquina e assim permitir a produção de programas e sistemas computacionais como nós conhecemos hoje em dia.

Apesar de ser popularmente conhecido por este termo único o que tratamos como compilador é na verdade uma série de programas que possuem funcionalidades que, unidas, são capazes de realizar tal tradução.

Os autores costumam tratar as fases de compilação em dois grupos: a fase de análise e a fase de síntese.
Na fase de análise existem as análises léxica, sintática e semântica, enquanto que a fase de síntese fica responsavel pela geração de código intermediário, otimização e geração de código objeto.

O analisador léxico é o responsável por reconhecer os simbolos aceitos na linguagem de programação, separar eles de forma unitária e entregar para o analizador sintático.

O analizador sintático é responsável por verificar as regras gramaticais relacionadas à formação das instruções. Caso, por exemplo, em um programa C seja escrito **printf ;** O analisador léxico aceitaria, porém o analizador sintático acusaria erro por entender que após um **printf** é necessário que haja uma abertura de parêntese.

O analizador semântico analisa a árvore sintática para a informação context-sensitive, gerada pelo analisador sintático em busca de inconsistências semânticas. Por exemplo, se no mesmo programa em C estiver escrito **i = 3;** o analisador sintático vai aceitar, porém no analisador semântico ele falharia caso a variável **i** não tivesse sido previamente declarada.

Após toda a fase de análise o código passa para o processo de sintese que basicamente irá gerar um código intermediário ou em notação pós fixada ou em código de 3 endereços, passará para a fase de otimização onde busca-se por redundâncias de dados e repetições de operações e, por fim, terá a geração de código objeto que é o arquivo que possui as localizações de memória para cada variável usada e os códigos de máquina correspondentes às operações contidas nas instruções intermediárias.

Só após este processo é que o programa computacional estará pronto para uso.

---

Ferramentas
-----------
Para o projeto foram utilizadas as ferramentas Flex e Bison em conjuto com a linguagem C de forma a facilitar o desenvolvimento das duas primeiras etapas citadas acima.

O Flex é um software para a geração de scanners (programas que reconhecem padrões léxicos no texto) e o Bison é um gerador de propósito geral que converte uma gramatica livre de contexto em um parser de liguagem regular deterministica ou generalizada a partir da tabela de parser LALR.

No projeto o Flex foi fundamental para a análise léxica da linguagem proposta. Por meio de expressões regulares foram criados scanners capazes de verificar os tokens e separa-los no código de input.

O Bison por sua vez, foi utilizado para a criação de regras de gramática para reconhecimento de estruturas da linguagem e para a geração da árvore sintática contendo essas estruturas. 

---

A Solução
---------
* **A ESTRUTURA**

O projeto conta com a seguinte estrutura de linguagem de programação:

- Declaração de funções
- Chamada de funções
- Declaração de variáveis não inicializadas
- Declaração de variáveis inicializadas
- Declaração de Vetores
- Atribuição à variáveis
- Estrutura de repetição _While_
- Estrutura de controle _if_*

Além destas estruturas, os tipos primitivos presentes na pseudo-linguagem são:
- Inteiro (int) - com 4 bytes;
- Float (float) - com 32 bytes;
- Double (double) - com 64 bytes;
- Caractere (char) - com 4 bytes;


* **O ANALISADOR LÉXICO**

O analisador léxico possui diversos scanners que possibilitam, por exemplo, identificar algumas palavras reservadas e categoriza-las de acordo com o sub grupo de utilização ao qual elas pertencem evitando assim ambiguidade. Um bom exemplo disto são as estruturas que chamo de _PRIMITIVAS_ e _PALAVRAS\_RESERVADAS_ a primeira engloba os tipos de dados primitivos utilizados na declaração de funções e variáveis, a segunda por sua vez é utilizada para controle de fluxo dentro de rotinas de decisão ou de repetição. Apesar de ambas se categorizarem como palavras reservadas existe uma clara divisão na utilização de cada sub-categoria, e por isso foram feitos scanners especificos para cada sub categoria.

Para a análise de variáveis foi feita a verificação através de Regex para verificar qualquer estrutura que contenha uma letra, maiúscula ou minuscula, seguida de nada ou mais letras, números ou underlines.

Algo interessante de notar na gramática gerada é que, apesar de ser bastante baseada na linguagem C, esta não possui ponto e vírgula ao final das sentenças. 

* **O ANALISADOR SINTÁTICO**
O analizador sintático ao ser desenvolvido precisou ser pensado cuidadosamente para abarcar todas as possibilidades, principalmente quando se tratava de declarações, tanto para variáveis quanto para funções, desta forma este tem regras para declaração de funções com e sem argumentos e declaração de variáveis com e sem atribuíção.

Uma peculiaridade da implementação se deve à uma dificuldade encontrada durante o desenvolvimento da regra para declaração de vetores em que foi necessario o uso de uma sintaxe alternativa para que este funcionasse da forma correta.


Conclusão
--------

O trabalho, apesar de não estar perfeito consegue atender adequadamente às demandas solicitadas e representa bem as etapas em um processo de analise léxica e sintática para a geração de uma gramática não ambígua.

Posso concluir que o trabalho foi bastante proveitoso e esclarecedor para os fins que se propós, uma vez que através dele foi possível compreender o processo responsável pela geração de gramáticas livre de contexto que permitem a geração de novas linguagens de programação.

