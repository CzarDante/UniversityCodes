from TabelaSimbolos import TabelaSimbolos
from Tokens import Tokens
from Simbolos import Simbolos

class AnaliseSintatica():
    def __init__(self, tabela_de_simbolos, linhas):
        self.tabela_de_simbolos = tabela_de_simbolos
        self.linhas = linhas

    def Inicializador_linhas(self):
        t = Tokens(tabela_de_simbolos=self.tabela_de_simbolos)
        linha = []
        numero_linha = 0
        for token in t.tokens:
            if token[0] != 10 and token[0] != 3: #Se for diferente de LF ou EOF
                linha.append(token[0])
                if isinstance(token[1], tuple): #função retorna True se o objeto especificado for do tipo especificado, caso contrário, False
                    numero_linha = token[1][0]
            else:
                linha.append(token[0])
                self.analisador_sintatico(linha, numero_linha)
                linha.clear()
                numero_linha = 0 
    
    def return_linha(self, index):
        return self.linhas[index]

    def analisador_sintatico(self, linha, numero_linha): #ANALISA LINHA POR LINHA
        linha_doc = self.return_linha(numero_linha) #PEGA O CONTEUDO DA LINHA ANALISADA
        match linha[:2]: #TESTA PARA TODAS AS POSICOES APOS A TERCEIRA POSICAO, IGNORA LABEL
            case [51, 61]: #CONST + REM > IGNORA REM
                pass 
            case [51, 62]: #CONST + INPUT > CASO ESPERADO
                self.input(linha, numero_linha)
            case [51, 63]: #CONST + LET > CASO ESPERADO
                self.let(linha, numero_linha)
                pass 
            case [51, 64]: #CONST + PRINT > CASO ESPERADO
                self.print(linha, numero_linha)
                pass 
            case [51, 65]: #CONST + GOTO > CASO ESPERADO 
                self.goto(linha, numero_linha)
                pass 
            case [51, 66]: #CONST + IF > CASO ESPERADO
                self.if_(linha, numero_linha)
                pass 
            case [51, 67]: #CONST + END > CASO ESPERADO
                self.end(linha, numero_linha)
                pass
            case _:
                #FAZER COMPARATIVOS PARA TODAS AS POSIBILIDADES
                print(f'Há um erro\n')

    def input(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:                
            case [41, 10]: #VAR + LF
                pass
            case _:
                print(f'Erro na linha({numero_linha+1}): {linha_doc}')
                if linha[2] != 41:
                    print(f'Falta a variavel\n')                

    def let(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:
            case [41, 11, 41, 10]: #VAR ATR VAR LF
                pass
            case [41, 11, 51, 10]: #VAR ATR CONST LF
                pass
            case [41, 11, 41, (21 | 22 | 23 | 24 | 25), 41, 10]: #VAR ATR VAR OPERACAO VAR LF
                pass
            case [41, 11, 41, (21 | 22 | 23 | 24 | 25), 51, 10]: #VAR ATR VAR OPERACAO CONST LF
                pass
            case _:
                #FAZER COMPARATIVOS PARA TODAS AS POSIBILIDADES
                print(f'Erro na linha({numero_linha+1}): {linha_doc}\n')
    
    def print(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:
            case [41, 10]:
                pass
            case _:
                print(f'Erro na linha({numero_linha+1}): {linha_doc}')
    
    def goto(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:
            case [51, 10]:
                #ADICIONA FUNCAO PARA VERIFICAR SE ENDERECO GOTO EXISTE
                pass
            case _:
                print(f'Erro na linha({numero_linha}): {linha_doc}\n')
    
    def if_(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:
            case [(41 | 51), (31 | 32 | 33 | 34 | 35 | 36 ), (41 | 51), 65, 51, 10]:
                pass
            case _:
                print(f'Erro na linha({numero_linha+1}): {linha_doc}\n')

                if linha[2] != 41 and linha[2] != 51:
                    print(f'Constante ou Variavel esperada na Operacao: {linha[0]} {linha[1]} ? {linha[2]} {linha[3]} {linha[4]} {linha[5]}\n')
                    return

                if linha[3] != 31 and linha[3] != 32 and linha[3] != 33 and linha[3] != 34 and linha[3] != 35 and linha[3] != 36:
                    print(f'Operador relacional esperada na Operacao: {linha[0]} {linha[1]} {linha[2]} ? {linha[3]} {linha[4]} {linha[5]}\n')
                    return
                
                if linha[4] != 41 and linha[4] != 51:
                    print(f'Constante ou Variavel esperada na Operacao: {linha[0]} {linha[1]} {linha[2]} {linha[3]} ? {linha[4]} {linha[5]}\n')
                    return 

                if linha[5] != 65:
                    print(f'GOTO esperado na Operacao: {linha[0]} {linha[1]} {linha[2]} {linha[3]} {linha[4]} ? {linha[5]}\n')
                    return
                                        
                if linha[6] != 51:
                    print(f'Local GOTO esperado na Operacao: {linha[0]} {linha[1]} {linha[2]} {linha[3]} {linha[4]} {linha[5]} ?')
                    return                    
    
    def end(self, linha, numero_linha):
        linha_doc = self.return_linha(numero_linha)
        match linha[2:]:
            case [3]:
                exit()
            case _:
                pass
