#include "Pacote.h"

// Inicialização do Pacote //
TPacote* InicializarPacote(char *NomeProduto, char *NomeDestino, int PesoProduto, int DistanciaDestino){
    TPacote* Pacote1 = (TPacote*)malloc(sizeof(TPacote));
    strcpy(Pacote1 -> NomeProduto, NomeProduto);
    strcpy(Pacote1 -> NomeDestino, NomeDestino);
    Pacote1 -> PesoProduto = PesoProduto;
    Pacote1 -> DistanciaDestino = DistanciaDestino;
    return Pacote1;
}
 
// Operações set do Pacote //
void setNomeProduto(TPacote *pacote, char *NomeProduto){
    strcpy(pacote -> NomeProduto, NomeProduto);
}
void setNomeDestino(TPacote *pacote, char *NomeDestino){
    strcpy(pacote -> NomeDestino, NomeDestino);
}
void setPesoProduto(TPacote *pacote, int PesoProduto){
    pacote -> PesoProduto = PesoProduto;
}
void setDistanciaDestino(TPacote *pacote, int DistanciaDestino){
    pacote -> DistanciaDestino = DistanciaDestino;
}
void setPrioridade(TPacote *pacote, int prioridade){
    pacote -> Prioridade = prioridade;
}

// Operações get do Pacote //
char* getNomeProduto(TPacote *pacote){
    return pacote -> NomeProduto;
}
char* getNomeDestino(TPacote *pacote){
    return pacote -> NomeDestino;
}
int getPesoProduto(TPacote *pacote){
    return pacote -> PesoProduto;
}
int getDistanciaDestino(TPacote *pacote){
    return pacote -> DistanciaDestino;
}
int getPrioridade(TPacote *pacote){
    return pacote -> Prioridade;
}
