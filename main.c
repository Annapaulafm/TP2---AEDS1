#include "Drone/Drone.c"
#include "Galpao/Galpao.c"
#include "Listapacote/ListaPacote.c"
#include "Pacote/Pacote.c"
#include <time.h>

int main(){
    printf("Digite a entrada arquivo ou digitar:\n");
    char escolha[8];
    int PesoMaximo, numerodepacotes;
    TLista listagem;
    scanf("%s", escolha);
    if(strcmp(escolha, "arquivo")==0){
        // ABRE O ARQUIVO DE ENTRADA//
        FILE* arquivo;
        arquivo = fopen("C:\\Users\\mathe\\Downloads\\Ola Mundo\\Segundo TP\\entrada.txt","r"); // Colocar o endereço do arquivo a ser lido //
        if (arquivo==NULL){
            printf("Erro na abertura do arquivo");
            system("pause");
            exit(1);
        }
        fscanf(arquivo, "%d", &PesoMaximo); // LE O PESO MAXIMO DO DRONE //
        fscanf(arquivo, "%d", &numerodepacotes); // LE O NUMERO DE PACOTES //
        // ● "Recebimento de Pacotes" ● //
        // LE OS PEDIDOS E ARMAZENA EM UMA LISTA "LISTAGEM" //
        char NomeProduto[100], NomeDestino[100];
        int PesoProduto, DistanciaDestino, prioridade; 
        TPacote pacoteX;
        FLVazia(&listagem);
        for(int i=0; i<numerodepacotes;i++){
            fscanf(arquivo,"%s %s %d %d %d", NomeProduto, NomeDestino, &PesoProduto, &DistanciaDestino, &prioridade);
            setNomeProduto(&pacoteX, NomeProduto);
            setNomeDestino(&pacoteX, NomeDestino);
            setPesoProduto(&pacoteX, PesoProduto);
            setDistanciaDestino(&pacoteX, DistanciaDestino);
            setPrioridade(&pacoteX, prioridade);
            LInsere(&listagem,&pacoteX);
        }
        fclose (arquivo); // FECHA O ARQUIVO DE ENTRADA //
    }

    else if(strcmp(escolha, "digitar")==0){
        printf("Digite os dados:\n");
        scanf("%d", &PesoMaximo); // LE O PESO MAXIMO DO DRONE //
        scanf("%d", &numerodepacotes); // LE O NUMERO DE PACOTES //
        char NomeProduto[100], NomeDestino[100];
        int PesoProduto, DistanciaDestino; 
        TPacote pacoteX;
        FLVazia(&listagem);
        for(int i=0; i<numerodepacotes;i++){
            scanf("%s %s %d %d", NomeProduto, NomeDestino, &PesoProduto, &DistanciaDestino);
            setNomeProduto(&pacoteX, NomeProduto);
            setNomeDestino(&pacoteX, NomeDestino);
            setPesoProduto(&pacoteX, PesoProduto);
            setDistanciaDestino(&pacoteX, DistanciaDestino);
            LInsere(&listagem,&pacoteX);
        }
    }

    else{
        printf("Entrada invalida\n");
        system("pause");
    }

    // ABRE O ARQUIVO DE SAIDA//
    FILE* arquivo2;
    arquivo2 = fopen("C:\\Users\\mathe\\Downloads\\Ola Mundo\\Segundo TP\\saida.txt","w"); // Colocar o endereço do arquivo a ser escrito //
    if (arquivo2==NULL){
        printf("Erro na abertura do arquivo");
        system("pause");
        exit(1);
    }


    // ● "Inicialização, criação de um TAD Galpão e um TAD Drone." ● //
    TDrone* drone1 = InicializarDrone(PesoMaximo); // INICIALIZA O DRONE1 //
    TGalpao* galpao1 = InicializaGalpao(); // INICIALIZA O GALPAO //

    // PASSA OS PACOTES DA LISTA "LISTAGEM" PARA O GALPAO //
    RecebeGalpao(galpao1, &listagem);
    

    // ● "Coleta de Pacotes" -> "Calcular Distância" -> "Imprimir Entregas" ● //
    int i=1, a=0;
    clock_t tempo_inicio, tempo_final;

    tempo_inicio = clock(); // Começa a marcar o tempo de ínicio da função "chave" do código //
    while(galpao1->ListaGalpao->pPrimeiro!=NULL){
        CarregarDrone(drone1, galpao1); // CARREGA O DRONE COM O MÁXIMO DE PACOTES POSSÍVEL //
        a+=drone1->DistanciaTotal; // VARIAVEL A ARMAZENA A DISTANCIA TODAS DE TODAS AS ENTREGAS //
        Entregas(drone1, i, arquivo2); // FAZ AS ENTREGAS E ARMAZENA A DISTANCIA PERCORRIDA NAQUELA ENTREGA //      
        i++;
    }
    tempo_final = clock();
    double tempo_total = (double)(tempo_final - tempo_inicio) / CLOCKS_PER_SEC; // Para de medir o tempo e nos dá o tempo da rodagem do programa //

    a+=drone1->DistanciaTotal; // ADICIONA NA VARIAVEL A DISTANCIA DA ULTIMA ENTREGA FEITA //
    fprintf(arquivo2,"Total de Quilômetros Percorridos no Dia: %dKM.", a); // IMPRIME A DISTANCIA TOTAL PERCORRIDA DO DIA //
    fprintf(arquivo2, "Tempo total de execucao: %.4f segundos\n", tempo_total);

    fclose (arquivo2); // FECHA O ARQUIVO DE SAIDA //
    system("pause");
    return 0;
}
