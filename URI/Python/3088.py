while(True):
	try:
		string = input()
		
		string = string.replace(" ,",",")
		string = string.replace(" .",".")
		
		print(string)
	except EOFError:
		break

