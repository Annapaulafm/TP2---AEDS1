#ifndef Pacote
#define Pacote
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Criação do Pacote //
typedef struct pacote
{
    char NomeProduto[100];
    char NomeDestino[100];
    int PesoProduto;
    int DistanciaDestino;
} TPacote;

// Inicialização do Pacote //
TPacote* InicializarPacote(char *NomeProduto, char *NomeDestino, int PesoProduto, int DistanciaDestino);

// Operações de set do Pacote //
void setNomeProduto(TPacote *pacote, char *NomeProduto);
void setNomeDestino(TPacote *pacote, char *NomeDestino);
void setPesoProduto(TPacote *pacote, int PesoProduto);
void setDistanciaDestino(TPacote *pacote, int DistanciaDestino);

// Operações de get do Pacote //
char* getNomeProduto(TPacote *pacote);
char* getNomeDestino(TPacote *pacote);
int getPesoProduto(TPacote *pacote);
int getDistanciaDestino(TPacote *pacote);

#endif