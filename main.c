#include "Drone.c"
#include "Galpao.c"
#include "ListaPacote.c"
#include "Pacote.c"

int main(){
    // ABRE O ARQUIVO DE ENTRADA//
    FILE* arquivo;
    arquivo = fopen("C:\\Users\\mathe\\Downloads\\Ola Mundo\\Primeiro TP\\entrada.txt","r"); // Colocar o endereço do arquivo a ser lido //
    if (arquivo==NULL){
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }

    // ABRE O ARQUIVO DE SAIDA//
    FILE* arquivo2;
    arquivo2 = fopen("C:\\Users\\mathe\\Downloads\\Ola Mundo\\Primeiro TP\\saida.txt","w"); // Colocar o endereço do arquivo a ser escrito //
    if (arquivo==NULL){
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }


    // ● "Inicialização, criação de um TAD Galpão e um TAD Drone." ● //
    int PesoMaximo, numerodepacotes;
    fscanf(arquivo, "%d", &PesoMaximo); // LE O PESO MAXIMO DO DRONE //
    fscanf(arquivo, "%d", &numerodepacotes); // LE O NUMERO DE PACOTES //
    TDrone* drone1 = InicializarDrone(PesoMaximo); // INICIALIZA O DRONE1 //
    TGalpao* galpao1 = InicializaGalpao(); // INICIALIZA O GALPAO //

    
    // ● "Recebimento de Pacotes" ● //
    // LE OS PEDIDOS E ARMAZENA EM UMA LISTA "LISTAGEM" //
    char NomeProduto[100], NomeDestino[100];
    int PesoProduto, DistanciaDestino; 
    TPacote pacoteX;
    TLista listagem;
    FLVazia(&listagem);
    for(int i=0; i<numerodepacotes;i++){
        fscanf(arquivo,"%s %s %d %d", NomeProduto, NomeDestino, &PesoProduto, &DistanciaDestino);
        setNomeProduto(&pacoteX, NomeProduto);
        setNomeDestino(&pacoteX, NomeDestino);
        setPesoProduto(&pacoteX, PesoProduto);
        setDistanciaDestino(&pacoteX, DistanciaDestino);
        LInsere(&listagem,&pacoteX);
    }

    // PASSA OS PACOTES DA LISTA "LISTAGEM" PARA O GALPAO //
    RecebeGalpao(galpao1, &listagem);
    

    // ● "Coleta de Pacotes" -> "Calcular Distância" -> "Imprimir Entregas" ● //
    int i=1, a=0;
    while(galpao1->ListaGalpao->pPrimeiro!=NULL){
        CarregarDrone(drone1, galpao1); // CARREGA O DRONE COM O MÁXIMO DE PACOTES POSSÍVEL //
        a+=drone1->DistanciaTotal; // VARIAVEL A ARMAZENA A DISTANCIA TODAS DE TODAS AS ENTREGAS /
        Imprimir(drone1, i, arquivo2); // IMPRIME A ENTREGA FEITA COM NUMERO DA ENTREGA, AS ENTREGAS E A DISTANCIA PERCORRIDA //
        drone1->DistanciaTotal=drone1->DistanciaTotal;
        Entregas(drone1); // FAZ AS ENTREGAS E ARMAZENA A DISTANCIA PERCORRIDA NAQUELA ENTREGA //
        i++;
    }

    a+=drone1->DistanciaTotal; // ADICIONA NA VARIAVEL A DISTANCIA DA ULTIMA ENTREGA FEITA //
    fprintf(arquivo2,"Total de Quilômetros Percorridos no Dia: %dKM.", a); // IMPRIME A DISTANCIA TOTAL PERCORRIDA DO DIA //


    fclose (arquivo2); // FECHA O ARQUIVO DE SAIDA //
    fclose (arquivo); // FECHA O ARQUIVO DE ENTRADA //
    system("pause");
    return 0;
}
