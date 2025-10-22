# Define a regra padrão
all: compile-run

compile-run: Drone/Drone.c Galpao/Galpao.c Listapacote/ListaPacote.c Pacote/Pacote.c main.c
	gcc -o run Drone/Drone.c Galpao/Galpao.c Listapacote/ListaPacote.c Pacote/Pacote.c main.c -lm && .\run.exe

# Limpar arquivos compilados
clean:
	del /Q run.exe *.o 2>nul
