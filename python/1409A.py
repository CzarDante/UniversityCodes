def read_ints():
    return map(int, input().split(' '))

t = int(input())
for i in range(t):
    a, b = read_ints()
    distancia = abs(a - b)
    vezes = distancia // 10
    if distancia % 10 != 0:
        vezes+=1
    print(vezes)
