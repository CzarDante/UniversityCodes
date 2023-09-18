
import re
from TabelaSimbolos import TabelaSimbolos
from Tokens import Tokens

tabela = TabelaSimbolos()
token = Tokens(tabela_de_simbolos=tabela)
line_number = 0

class AnalisaLexica():
    def q0(splitted_line, line, count_line):
        # A linha já está separada por palavras
        for word in splitted_line:
            if word in ('+', '-', '%', '*', '/'):
                column = re.search(r"\+|\-|\%|\*|\/", line).start()
            elif re.search(r"[\+|\-|\%|\*|\/]+", word):
                pass
            else: 
                column = re.search(word, line).start() 
            if word in ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'): #ALFABETO Q1
                AnalisaLexica.q1(word, count_line, column)
            elif re.search(r'^-?[0-9]\d*(\.\d+)?$', word): #CONSTANTES Q2
                AnalisaLexica.q2(word, count_line, column) 
            elif word in ('if', 'input', 'end', 'goto', 'let', 'print'): #PALAVRAS RESERVADAS Q3
                AnalisaLexica.q3(word, count_line, column)
            elif word in ('<', '<=', '>=', '>', '+', '-', '/', '%', '*', '=', '=='): #OPERADORES LOGICOS Q4
                AnalisaLexica.q4(word, count_line, column)
            elif word == 'rem':
                AnalisaLexica.q3(word, count_line, column)
                break
            else:
                print(word + ' : Erro: Palavra inválida')
                exit()

    def q1(word, line, column): #ALFABETO Q1
        tabela.add_tabela(simbolos=word)
        num_tabela_simbolos = tabela.get_num_simbolos(word)
        num_simbolos = token.variaveis()
        token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=num_tabela_simbolos, line=line, column=column)
    
    def q2(word, line, column): #CONSTANTES Q2
        constante = int(word)
        if constante >= 0:
            tabela.add_tabela(simbolos=constante)
        num_tabela_simbolos = tabela.get_num_simbolos(constante)
        num_simbolos = token.constante()
        token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=num_tabela_simbolos, line=line, column=column)

    def q3(word, line, column): #RESERVED WORDS
        if word == 'end':
            num_simbolos = token.plv_reservada(word)
            token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=None, line=line, column=column)
            EOF = token.plv_reservada('eof')
            token.add_token(valor_simbolos=EOF, valor_simbolos_tabela=None, line=line, column=column+1)
        else:     
            num_simbolos = token.plv_reservada(word)
            token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=None, line=line, column=column)
        
    def q4(word, line, column): #MATH simbolosS
        num_simbolos = token.operadores(word)
        token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=None, line=line, column=column)

    def q5(line, column): #\N
        num_simbolos = token.nova_linha()
        token.add_token(valor_simbolos=num_simbolos, valor_simbolos_tabela=None, line=line, column=column)
