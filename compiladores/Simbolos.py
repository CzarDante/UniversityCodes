from enum import Enum

#Especificação das classes de tokens
class Simbolos(Enum):

    # Delimitadores
    LF = 10 # Nova linha
    EOF = 3 # Fim do texto

    # Operadores 
    ATR = 11 # Atribuição

    # Operadores aritméticos
    ADD = 21 # Adição
    SUB = 22 # Subtração
    MULT = 23 # Multiplicação
    DIV = 24 # Divisão inteira
    MOD = 25 # Resto da divisão

    # Operadores relacionais
    EQL = 31 # Igual a (==)
    DIF = 32 # Diferente de (!=)
    GRT = 33 # Maior que (>)
    LEST = 34 # Menor que (<)
    GEQ = 35 # Maior ou igual que (>=)
    LEQ = 36 # Menor ou igual que (<=)
    
    # Identificadores
    VAR = 41 # Variáveis

    # Constantes 
    CONST = 51 # Constantes numéricas inteiras
    
    # Palavras reservadas 
    REM = 61 # Comentário
    INPUT = 62 # Input
    LET = 63 # Let
    PRINT = 64 # Print
    GOTO = 65 # Goto
    IF = 66 # If
    END = 67 # End
    ERR = 99 # Erro

