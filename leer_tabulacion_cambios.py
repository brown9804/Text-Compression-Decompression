archivo = open("Tabla_cambios.tab", "r")
for linea in archivo:
	hilera = linea.replace("\n","")
	print(hilera)
archivo.close()
