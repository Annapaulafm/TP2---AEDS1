#ifndef Drone
#define Drone
#include "ListaPacote.h"
#include "Galpao.h"

// Criação do Drone //
typedef struct Drone
{
    int PesoMaximo;
    int PesoCarregado;
    int DistanciaTotal;
    TLista *ListaPacotes;
} TDrone;

// Operações do Drone //
TDrone* InicializarDrone(int PesoMaximo);
void CarregarDrone(TDrone *drone, TGalpao* galpao);
void Entregas(TDrone *drone);
void Imprimir(TDrone *drone, int i, FILE* arquivo2);

#endif