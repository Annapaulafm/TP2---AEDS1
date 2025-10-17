#include "Galpao.h"
#include "ListaPacote.h"
#include <stdio.h>
#include <stdlib.h>


//Inicialização Galpão
TGalpao* InicializaGalpao()
{
    TGalpao* Galpao1 = (TGalpao*)malloc(sizeof(TGalpao));
    if(Galpao1 == NULL){
        printf("Erro na alocação da função malloc");
        system("pause");
        exit(1);
    }
    Galpao1 -> ListaGalpao = NULL;
    return Galpao1;
}

//Recebimentos de pacotes 
void RecebeGalpao(TGalpao* Galpao1, TLista* listadiaria)
{
    Galpao1 -> ListaGalpao = listadiaria;
}

//Carregamentos de pacotes 
int CarregamentoGalpao(TGalpao* Galpao1)
{
    return LRetira(Galpao1 -> ListaGalpao);
}

//Impressão lista de pacotes entregues no dia
void ImprimePacotesGalpao(TGalpao* Galpao1)
{
    printf("Pacotes no galpao:\n");
    LImprime(Galpao1->ListaGalpao);
}