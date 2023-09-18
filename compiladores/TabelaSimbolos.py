class TabelaSimbolos():
    simbolos: any
    tabela_de_simbolos = {}
    
    def add_tabela(self, simbolos):
        index = len(self.tabela_de_simbolos)
        if simbolos not in self.tabela_de_simbolos.values():
            self.tabela_de_simbolos[index+1] = simbolos

    def get_num_simbolos(self, simbolos):
        for key, value in self.tabela_de_simbolos.items():
            if simbolos == value:
                return key

    def __str__(self):
        return str(self.tabela_de_simbolos)