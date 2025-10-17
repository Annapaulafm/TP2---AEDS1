#include "ListaPacote.h"

//Operações da encadeada //
void FLVazia(TLista *pLista){
    pLista->pPrimeiro = NULL;
    pLista->pUltimo = NULL;
}

TLista* InicializaLista(){
    TLista* pLista = (TLista*)malloc(sizeof(TLista));
    if(pLista == NULL){
        printf("Erro na alocação da função malloc");
        system("pause");
        exit(1);
    }
    pLista->pPrimeiro = NULL;
    pLista->pUltimo = NULL;
    return pLista;
}

void LInsere(TLista* pLista,TPacote *pItem){
    if (pLista->pUltimo == NULL){
        pLista->pUltimo = (Apontador) malloc(sizeof(TCelula));
        pLista->pPrimeiro = pLista->pUltimo; }
    else{
        pLista->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula));
        pLista->pUltimo = pLista->pUltimo->pProx;
    }
    pLista->pUltimo->Item = *pItem;
    pLista->pUltimo->pProx = NULL;
}

int LRetira(TLista* pLista){
    TCelula* pAux;
    if (LEhVazia(pLista)) return 0;
    pAux = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    if (pLista->pPrimeiro == NULL) pLista->pUltimo = NULL;
    return 1;
}

void LImprime(TLista* pLista){
    Apontador pAux;
    pAux = pLista->pPrimeiro;
    while (pAux != NULL){
        printf("Produto: %s\n", pAux->Item.NomeProduto);
        printf("Destino: %s\n", pAux->Item.NomeDestino);
        printf("Peso: %d\n", pAux->Item.PesoProduto);
        printf("Distancia: %d\n", pAux->Item.DistanciaDestino);
        printf("\n");
        pAux = pAux->pProx;
    }
}

int LEhVazia(TLista* pLista){
    return (pLista->pUltimo == NULL);
}