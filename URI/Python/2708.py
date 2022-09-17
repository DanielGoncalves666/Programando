jipes = 0
turistas = 0

while(1):
    try:
        string, valor = input().split()
        valor = int(valor)

        if string == "SALIDA":
            jipes += 1
            turistas += valor
        if string == "VUELTA":
            jipes -= 1
            turistas -= valor

    except ValueError:
        print(turistas)
        print(jipes)
        break;

