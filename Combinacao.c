#include <stdio.h>
#include <stdlib.h>
#include "../ListaPacote/ListaPacote.h"

void combinar_lista_e_avaliar_k(
    Apontador pCelulaAtual, 
    int k,                  
    TPacote data[],         
    int data_i,
    int peso_maximo,
    int *max_prioridade,         
    TPacote **melhor_comb_pacotes, 
    int *melhor_comb_num         
) {
    if (k == 0) {
        int peso_total = 0;
        int prioridade_total = 0;

        for (int i = 0; i < data_i; i++) {
            peso_total += data[i].PesoProduto;
            prioridade_total += data[i].Prioridade;
        }

        if (peso_total <= peso_maximo && prioridade_total > *max_prioridade) {
            *max_prioridade = prioridade_total;

            if (*melhor_comb_pacotes != NULL) {
                free(*melhor_comb_pacotes);
            }

            *melhor_comb_pacotes = (TPacote*)malloc(data_i * sizeof(TPacote));
            if (*melhor_comb_pacotes == NULL) return; 

            memcpy(*melhor_comb_pacotes, data, data_i * sizeof(TPacote));
            *melhor_comb_num = data_i;
        }
        return;
    }

    if (pCelulaAtual == NULL) {
        return;
    }

    TPacote primeiro_item = pCelulaAtual->Item;
    Apontador resto_da_lista = pCelulaAtual->pProx;

    data[data_i] = primeiro_item; 
    combinar_lista_e_avaliar_k(resto_da_lista, k - 1, data, data_i + 1,
                               peso_maximo, max_prioridade, melhor_comb_pacotes, melhor_comb_num);

    combinar_lista_e_avaliar_k(resto_da_lista, k, data, data_i, 
                               peso_maximo, max_prioridade, melhor_comb_pacotes, melhor_comb_num);
}

void planejar_viagens(TLista *pacotes_disponiveis, int peso_maximo_drone, TLista *viagens) {
    TLista pacotes_restantes;
    FPVazia(&pacotes_restantes);
    
    Apontador p = pacotes_disponiveis->pPrimeiro->pProx;
    while(p != NULL) {
        InsereLista(p->Item, &pacotes_restantes);
        p = p->pProx;
    }

    int n_max_pacotes = TamanhoLista(*pacotes_disponiveis);
    TPacote *combinacao_atual = (TPacote*)malloc(n_max_pacotes * sizeof(TPacote));
    if (combinacao_atual == NULL) return;

    while (!Vazia(pacotes_restantes)) {
        
        TPacote *melhor_combinacao_pacotes = NULL;
        int max_prioridade_para_viagem = -1;
        int melhor_combinacao_num = 0; 

        int n_restante = TamanhoLista(pacotes_restantes);
        
        for (int tamanho_combinacao = 1; tamanho_combinacao <= n_restante; tamanho_combinacao++) {
            
            combinar_lista_e_avaliar_k(
                pacotes_restantes.pPrimeiro->pProx, 
                tamanho_combinacao, 
                combinacao_atual, 
                0, 
                peso_maximo_drone,
                &max_prioridade_para_viagem,
                &melhor_combinacao_pacotes,
                &melhor_combinacao_num
            );
        }

        if (melhor_combinacao_num > 0) {
            InsereViagem(melhor_combinacao_pacotes, melhor_combinacao_num, max_prioridade_para_viagem, viagens);
            
            for (int i = 0; i < melhor_combinacao_num; i++) {
                TPacote pacote_removido;
                RetiraLista(melhor_combinacao_pacotes[i].NomeProduto, &pacotes_restantes, &pacote_removido);
            }
        } else {
            if (melhor_combinacao_pacotes != NULL) {
                free(melhor_combinacao_pacotes);
            }
            break;
        }
    }
    
    free(combinacao_atual);
}