A, B = map(float, input().split())
nota = (A + B) / 2
if nota < 5:
    print('reprovado')
if nota > 8:
    print('aprovado com SS')
elif nota >=5:
    print('aprovado com MS')
