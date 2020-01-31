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
Explicar em detalhes a implementação do seu parser, explicar os principais elementos da implementação
especialmente o que diz respeito à análise léxica e sintática, como tokens e produções.
Conclusão
