notaP1 = float(input("Nota P1:"))
notaP2 = float(input("Nota P2:"))
mediaFinal = notaP1*0.4 + notaP2*0.6

if mediaFinal >= 5:
    print("Aprovado")
    print(f"Média final:{mediaFinal: .1f}")
elif mediaFinal < 5:
    print("Média não foi suficiente.")
    notaP3 = float(input("nota P3:"))

    substituiP1 = notaP3*0.4 + notaP2*0.6
    substituiP2 = notaP1*0.4 + notaP3*0.6
    
    if substituiP1 >= 5:
        print("Aprovado")
        mediaFinal = notaP3*0.4 + notaP2*0.6
        print(f"Média Final:{mediaFinal: .1f}")
    elif substituiP2 >= 5:
        print("Aprovado")
        mediaFinal = notaP1*0.4 + notaP3*0.6
        print(f"Média Final:{mediaFinal: .1f}")
    elif substituiP1 < 5 and substituiP2 < 5:
        print("Reprovado")
        if substituiP1 > substituiP2:
            print(f"Média Final:{substituiP1: .1f}")
        else:
            print(f"Média Final:{substituiP2: .1f}")
