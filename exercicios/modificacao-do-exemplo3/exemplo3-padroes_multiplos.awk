#!/usr/bin/awk -f
# Este programa não captura o último identificador na última expressão do
# arquivo de entrada em ./input/exemplo3-padroes-multiplos.in
# Modifique o programa para que ele identifique todos os identificadores


BEGIN { print "- INICIO - Iniciando Análise" }

{
    {
        while(match($0, /[a-zA-Z][a-zA-Z0-9]*/)){
            print "<identificador, "substr($0,RSTART,RLENGTH)" >"; 
            $0=substr($1,RSTART+RLENGTH);
        }
    }
    {
        while(match($0, /=/)){
            print "<atribuição, "substr($0, RSTART, RLENGTH)" >";
            $0 = substr($1, RSTART + RLENGTH);
        }
    }
    {
        while(match($0, /[0-9]+/)){
            print "<valor, "substr($0, RSTART, RLENGTH)" >";
            $0 = substr($1, RSTART + RLENGTH);
        }

    }
}

END { print " - FIM -" }
