
#M = 3 do pai 3 ultimos da mae
#F = 3 primeiros da mae e 3 ultimos do pai


a,b,c = input().split()
nome = ""
if c=="F":
    nome = b[:3]+a[-3::1]
    d, e = input().split()
    if e == "F":
        nome1 = nome[:3]+d[-3::1]
        f, g = input().split()
        if g == "F":
            nome2 = nome1[:3]+f[-3::1]
            print(nome2)
        else:
            nome2 = f[:3]+nome1[-3::1]
    else:
        nome1 = d[:3]+nome[-3::1]
        f, g = input().split()
        if g == "F":
            nome2 = nome1[:3]+f[-3::1]
            print(nome2)
        else:
            nome2 = f[:3]+nome1[-3::1]
else:
    nome = a[:3]+b[-3::1]
    d, e = input().split()
    if e == "F":
        nome1 = nome[:3]+d[-3::1]
        f, g = input().split()
        if g == "F":
            nome2 = nome1[:3]+f[-3::1]
            print(nome2)
        else:
            nome2 = f[:3]+nome1[-3::1]
    else:
        nome1 = d[:3]+nome[-3::1]
        f, g = input().split()
        if g == "F":
            nome2 = nome1[:3]+f[-3::1]
            print(nome2)
        else:
            nome2 = f[:3]+nome1[-3::1]