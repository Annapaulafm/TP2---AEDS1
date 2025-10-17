#include "Drone.h"
// Inicializa o Drone //
TDrone* InicializarDrone(int PesoMaximo){
    TDrone* drone1 = (TDrone*)malloc(sizeof(TDrone));
    if(drone1 == NULL){
        printf("Erro na alocação da função malloc");
        system("pause");
        exit(1);
    }
    drone1 -> PesoCarregado = 0; // o drone começa descarregado //
    drone1 -> DistanciaTotal = 0;
    drone1 -> PesoMaximo = PesoMaximo;
    drone1 -> ListaPacotes = InicializaLista(drone1 -> ListaPacotes);
    return drone1;
}

// Careega o drone com o máximo de pacotes possível //
void CarregarDrone(TDrone *drone1, TGalpao *galpao1){
    while(galpao1->ListaGalpao->pPrimeiro != NULL && (drone1 -> PesoCarregado + galpao1 -> ListaGalpao -> pPrimeiro -> Item.PesoProduto) <= drone1 -> PesoMaximo){
        TCelula* aux;
        aux = galpao1 -> ListaGalpao -> pPrimeiro;
        if(drone1-> ListaPacotes ->pUltimo == NULL){
            drone1 -> ListaPacotes -> pUltimo = (Apontador) malloc(sizeof(TCelula));
            drone1 -> ListaPacotes -> pPrimeiro = drone1 -> ListaPacotes -> pUltimo;
        }
        else{
            drone1 -> ListaPacotes -> pUltimo-> pProx = (Apontador) malloc(sizeof(TCelula));
            drone1 -> ListaPacotes -> pUltimo = drone1 -> ListaPacotes -> pUltimo -> pProx;
        }
        drone1 -> ListaPacotes -> pUltimo -> pProx = NULL;
        drone1 -> ListaPacotes -> pUltimo -> Item = galpao1 -> ListaGalpao -> pPrimeiro -> Item;
        drone1 -> PesoCarregado += galpao1 -> ListaGalpao -> pPrimeiro -> Item.PesoProduto;
        galpao1 -> ListaGalpao -> pPrimeiro = galpao1 -> ListaGalpao -> pPrimeiro -> pProx;
        free(aux);
    }
}

// Realiza as entregas calculado a distancia total da rota //
void Entregas(TDrone *drone1, FILE* arquivo2){
    int atual = 0, total = 0; //Criação de váriaveis auxiliares para a distância//
    while(drone1 -> ListaPacotes ->pPrimeiro != NULL){
        if(atual == 0){
            atual = drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino;
            total += drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino;
        }
        else{
            if(atual < drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino){ // se a próxima entrega estiver mais distante do que o ponto atual //
                total += drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino - atual; // total += distancia do proximo - atual
                atual = drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino;
            }
            else{ // a próxima entrega é mais perto do galpão que a anterior //
                total += atual - drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino; // total += atual - distancia do proximo //
                atual = drone1 -> ListaPacotes -> pPrimeiro -> Item.DistanciaDestino;
            }
            
        }
        drone1->PesoCarregado-=drone1->ListaPacotes->pPrimeiro->Item.PesoProduto;
        LRetira(drone1 -> ListaPacotes); // Retira o pacote entregue do inventário do drone //
    }
    drone1 -> DistanciaTotal = total + atual;
    fprintf(arquivo2, "Distancia Total: %d\n\n", drone1 -> DistanciaTotal);
    // Soma a distância já percorrida com a distância para voltar ao galpão//
}
// Imprime o numero da viagem, as entregas e a distância percorrida naquele carregamento //
void Imprimir(TDrone *drone1, int i,FILE* arquivo2){ // recebe "i" para auxiliar na contagem de viagens //
    fprintf(arquivo2, "Viagem %d\n", i);
    while(drone1->ListaPacotes->pPrimeiro!=NULL){
        fprintf(arquivo2, "Entrega: \"%s\" para \"%s\"\n", getNomeProduto(&drone1->ListaPacotes->pPrimeiro->Item), getNomeDestino(&drone1->ListaPacotes->pPrimeiro->Item));
        drone1->ListaPacotes->pPrimeiro=drone1->ListaPacotes->pPrimeiro->pProx;
    }
}

ProblemaCarregamento(TDrone *drone, TGalpao* galpao, int n){

}
