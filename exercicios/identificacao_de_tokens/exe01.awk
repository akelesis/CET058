#!/usr/bin/awk -f
# Escreva um script que irá tentar retirar o máximo
# de tokens do código C que está no arquivo
# ./inputs/ex01.in, a saída deve ser na forma
# <tipo_token, "valor"> um token por linha como
# no exemplo3-padroes_multiplos.awk.

BEGIN {print "-- Iniciando Análise Léxica"}
{
	while(match($0, /[a-zA-Z][a-zA-Z0-9]*/)){
		print "<identificador, "substr($0,RSTART,RLENGTH)" >"; 
        $0=substr($0,RSTART+RLENGTH);
	}
}

{
	while(match($0, /=/)){
		print "<atribuição, "substr($0, RSTART, RLENGTH)" >";
		$0 = substr($0, RSTART + RLENGTH);
	}
}

{
	while(match($0, /[0-9]+/)){
		print "<valor, "substr($0, RSTART, RLENGTH)" >";
		$0 = substr($0, RSTART + RLENGTH);
	}
}
END {print "-- Fim da análise Léxica"}
