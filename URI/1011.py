pi = 3.14159

def volume_esfera(raio):
	return (4/3.0)*pi*(raio**3)

volume = volume_esfera(int(input()))
print("VOLUME = {:.3f}".format(volume))