 #  __________     __________     _________    _________
 # |___    ___|   |   _______|   |   ______|   |   ___  \
 #     |  |       |  |_______    |  |______    |  |___|  |
 #     |  |       |   _______|   |______   |   |   ___  /
 #  ___|  |___    |  |_______     ______|  |   |  |___| \
 # |__________|   |__________|   |_________|   |_______ /
def tracos():
    print("-"*30)
    return tracos
def cadastro():
    nome, curso, carro, modelo, ano, cor = input("Qual seu nome: "), input("Qual seu curso: "), input("Qual seu carro: "), input("Qual o modelo so seu carro: "), int(input("Qual o ano do seu carro: ")), input("Qual a cor do seu carro: ")
    return nome, curso, carro, modelo, ano, cor

selecao = 1
while selecao != 0:
    tracos()
    print("Bem-Vindo ao sistema do IESB Services de stationnement\n")
    print("Escolha uma opção abaixo:")
    print("0 - Para sair do programa")
    print("1 - Para cadastrar novo cliente")
    tracos()
    selecao = int(input())
    if selecao == 0:
        tracos()
        print("Obrigado por usar nossos sisitema, a IESB Services de stationnement")        
    elif selecao == 1:
        tracos()
        nome, curso, carro, modelo, ano, cor = cadastro()
        print("\n")
        print(f"Nome: {nome}")
        print(f"Curso: {curso}")
        print(f"Carro: {carro}")
        print(f"Modelo: {modelo}")
        print(f"Ano: {ano}")
        print(f"Cor: {cor}")
        print("Cadastro Realizado com Sucesso")        