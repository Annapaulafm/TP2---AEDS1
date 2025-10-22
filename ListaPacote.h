#ifndef ListaPacote // evita que um mesmo arquivo do .h seja incluido várias vezes //
#define ListaPacote
#include "../Pacote/Pacote.h"

// Lista pacotes //
typedef struct Celula* Apontador;
typedef struct Celula {
    TPacote Item;
    Apontador pProx;
} TCelula;

typedef struct {
    Apontador pPrimeiro;
    Apontador pUltimo;
} TLista;

// Operações lista pacotes //
void FLVazia(TLista *pLista);
void LInsere(TLista* pLista,TPacote *pItem);
int LRetira(TLista* pLista);
void LImprime(TLista* pLista);
int LEhVazia(TLista* pLista);
TLista* InicializaLista();

#endif
