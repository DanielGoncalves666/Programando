inicial, final = input().split()

inicial = int(inicial)
final = int(final)

if inicial < final:
	print("O JOGO DUROU {} HORA(S)".format(final-inicial))
elif inicial > final:
	print("O JOGO DUROU {} HORA(S)".format(24 - inicial + final))
elif inicial == final:
	print("O JOGO DUROU 24 HORA(S)")