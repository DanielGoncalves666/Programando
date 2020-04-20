hi, mi, hf, mf = input().split()
hi = int(hi)
mi = int(mi)
hf = int(hf)
mf = int(mf)

horas = 0
minutos = 0

if hi == hf:
	if mi == mf:
		horas = 24
		minutos = 0
	elif mi < mf:
		horas = 0
		minutos = mf - mi
	elif mi > mf:
		horas = 23
		minutos = 60 - mi + mf
elif hi < hf:
	if mi == mf:
		horas = hf - hi
		minutos = 0
	else:
		horas = hf - (hi + 1)
		minutos = 60 - mi + mf
elif hi > hf:
	horas = 24 - (hi + 1) + hf
	minutos = 60 - mi + mf

if minutos >= 60:
	minutos -= 60
	horas += 1

print("O JOGO DUROU {} HORA(S) E {} MINUTO(S)".format(horas, minutos))