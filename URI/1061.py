lista_1 = input().split()
lista_2 = input().split(" : ")
lista_3 = input().split()
lista_4 = input().split(" : ")

dia_i = int(lista_1[1])
dia_f = int(lista_3[1])
hora_i = int(lista_2[0])
hora_f = int(lista_4[0])
min_i = int(lista_2[1]) 
min_f = int(lista_4[1])
seg_i = int(lista_2[2])
seg_f = int(lista_4[2])

tempo = [0,0,0,0]
segundos = 0

if dia_i == dia_f:
	if hora_i == hora_f:
		if min_i == min_f:
			segundos +=  seg_f - seg_i
		else:
			segundos += (min_f - (min_i + 1))*60
			segundos += seg_f + (60 - seg_i)
	else:
		segundos += (hora_f - (hora_i + 1))*60*60
		segundos += ((60 - (min_i + 1)) + min_f)*60
		segundos += seg_f + (60 - seg_i)
else:
	segundos += (dia_f - (dia_i + 1))*24*60*60
	segundos += ((24 - (hora_i + 1)) + hora_f)*60*60
	segundos += ((60 - (min_i + 1)) + min_f)*60
	segundos += seg_f + (60 - seg_i)

tempo[0] = segundos//(24*3600)
segundos -= tempo[0]*(24*60*60)
tempo[1] = segundos//(60*60)
segundos -= tempo[1]*(60*60)
tempo[2] = segundos//60
segundos -= tempo[2]*60
tempo[3] = segundos

print("{} dia(s)".format(tempo[0]))
print("{} hora(s)".format(tempo[1]))
print("{} minuto(s)".format(tempo[2]))
print("{} segundo(s)".format(tempo[3]))