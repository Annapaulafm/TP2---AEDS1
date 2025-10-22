#ifndef Galpao
#define Galpao
#include "../ListaPacote/ListaPacote.h"

//TAD GALPÃO
typedef struct{
    TLista *ListaGalpao;
} TGalpao;

//Operações galpão
TGalpao* InicializaGalpao();
void RecebeGalpao(TGalpao* Galpao1, TLista* listadiaria);
int  CarregamentoGalpao(TGalpao* Galpao);
void ImprimePacotesGalpao(TGalpao* Galpao);

#endif
