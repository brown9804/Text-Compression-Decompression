
archivo = open("Historia_principito.txt", "r")
for linea in archivo:
	hilera = linea.replace("\n","")
	print(hilera)
archivo.close()
