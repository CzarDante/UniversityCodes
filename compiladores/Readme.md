# compiladores
Repositorio de codigos para o projeto Academico para obtenção de nota relativa a matéria Compiladores.

Este compilador foi criado utilizando o Python 3.10.9 64-bits
Portanto para executar ele é necessario está versão ou superior.

Método de execução:

Dentro da pasta raiz onde o codigo está localizado, disponibilize um arquivo .txt contendo o codigo em linguagem SIMPLE a ser compilado.

No terminal da mesma pasta execute o seguinte comando

``
py .\Initialize.py seu_arquivo.txt
``

Eduardo Cézar Pereira Fernandes - 2012130068
Ciencia da Computação - 8º Semestre

Sobre o programa:

Este compilador serve exclusivamente para a Linguagem SIMPLE(http://www.ybadoo.com.br/tutoriais/cmp/11/01/)
Ele faz a leitura do arquivo a ser compilado, lendo linha a linha, ignorando quaisquer comentarios.
Ele verifica tambem se o Label, ordem de instrução está em ordem alfabetica.

Para cada função o compilador verifica se a sentença está imcompleta ou incorreta.
Os valores dos Tokens podem ser verificados em, Simbolos.py , Estes Tokens foram retirados da documentação da linguagem SIMPLE, link acima.

O Analisador Lexico, AnalisaLexica.py, verifica se a palavra na linha que está sendo analisada é uma constante, uma variavel, uma palavra reservada ou um operador matematico.
O Analisador Sintatico, AnalisaSintatica.py, verifica se a ordem de tokens está sendo seguida. Exemplo:
Em uma operação de if a entrada esperada pode ser: 150, o label, + if + Constante ou Variavel + Operador relacional + Constante ou Variavel + GOTO + Endereco Label

Se alguma detes campos estiver errado ou ausente, o compilador deve indicar que existe um erro na sentença