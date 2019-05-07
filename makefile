
all: build run clean

build:
	python escribe_archivo.py
	python Leer_archivo.py
	python reemplazo.py
	python tabulacion_cambios.py
	python leer_tabulacion_cambios.py

run:
	cat *.rep
	cat *.tab
clean:
