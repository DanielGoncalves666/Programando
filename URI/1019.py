N = int(input())

horas = N/3600
N = N%3600

minutos = N/60
segundos = N%60

print("{}:{}:{}".format(int(horas),int(minutos),int(segundos)));