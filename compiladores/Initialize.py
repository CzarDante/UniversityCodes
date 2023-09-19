# Require Python 3.10.9+
#Eduardo Cézar Pereira Fernandes - 2012130068

import sys
import re

from TabelaSimbolos import TabelaSimbolos

from Tokens import Tokens

from AnalisaSintatica import AnaliseSintatica

from AnalisaLexica import AnalisaLexica

tabela = TabelaSimbolos()
token = Tokens(tabela_de_simbolos=tabela)
numero_linha = 0

def open_file(): #Abre txt com codigo SIMPLE
    global linhas
    with open(sys.argv[1], 'r') as file:
        linhas = file.readlines()
        verify_linhas(linhas)

def verify_linhas(linhas):
    count_linha = 0
    for linha in linhas:
        if not re.search('rem', linha): #Verifica se a linha é um comentario
            AnalisaLexica.q0(linha.split(), linha, count_linha)  
            count_linha += 1
            Ordem_Label(linha.split())
        else:
            nova_linha = linha.split()
            rem = nova_linha.index('rem')
            nova_linha[:rem+1] # Descarta linha
            AnalisaLexica.q0(nova_linha, linha, count_linha)
            count_linha += 1
            Ordem_Label(nova_linha)
        if re.search('\n', linha):
            AnalisaLexica.q5(count_linha, re.search('\n', linha).start())

def Ordem_Label(linha):
    global numero_linha
    try: 
        label = int(linha[0])
        if label == 0:
            print(f"Erro({numero_linha}): O número do label não pode ser igual a 0.\n")
            exit()
        elif label > numero_linha:
            numero_linha = label
        else:
            print(f"Erro na linha({numero_linha+1}): Label fora de ordem.\n")
            
    except ValueError:
        print(f"Erro na linha({numero_linha+1}): Label não é numérico.\n")
        

def return_line(index):
    return linhas[index]

def analisador_sintatico():
    a = AnaliseSintatica(tabela.tabela_de_simbolos, linhas)
    a.Inicializador_linhas()

open_file()
analisador_sintatico()
