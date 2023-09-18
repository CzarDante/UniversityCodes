from Simbolos import Simbolos
from TabelaSimbolos import TabelaSimbolos

class Tokens():
    num_simbolos: int 
    num_tabela_simbolos: int
    line: int
    column: int
    tokens = []
    tabela_de_simbolos: TabelaSimbolos

    def __init__(self, tabela_de_simbolos):
        self.tabela_de_simbolos = tabela_de_simbolos

    
    def operadores(self, word):
        match word:
            case '<':
                enum = Simbolos['LEST']
                return enum.value
            case  '<=': 
                enum = Simbolos['LEQ']
                return enum.value
            case  '>=': 
                enum = Simbolos['GEQ']
                return enum.value
            case  '>':
                enum = Simbolos['GRT']
                return enum.value
            case  '+':
                enum = Simbolos['ADD']
                return enum.value
            case  '-':
                enum = Simbolos['SUB']
                return enum.value
            case  '/':
                enum = Simbolos['DIV']
                return enum.value
            case  '%':
                enum = Simbolos['MOD']
                return enum.value
            case  '*':
                enum = Simbolos['MULT']
                return enum.value
            case  '=':
                enum = Simbolos['ATR']
                return enum.value
            case  '==':
                enum = Simbolos['EQL']
                return enum.value
    
    def variaveis(self):
        enum = Simbolos['VAR']
        return enum.value
    
    def nova_linha(self):
        enum = Simbolos['LF']
        return enum.value
    
    def constante(self):
        enum = Simbolos['CONST']
        return enum.value
    
    def plv_reservada(self, word):
        name = word.upper()
        enum = Simbolos[name]
        return enum.value
    
    def add_token(self, valor_simbolos, valor_simbolos_tabela, line, column):
        if valor_simbolos_tabela == None:
            token = [valor_simbolos, (line, column)]
            self.tokens.append(token) 
        else:
            token = [valor_simbolos, valor_simbolos_tabela, (line, column)]
            self.tokens.append(token) 
        
    def __str__(self):
        return str(self.tokens)