#include <stdio.h>
#include <string.h>

typedef struct { 
    char filme_escolhido[80];
    char sessao_escolhida[80];
    int assento_escolhido;
} INFO_FILME;

void imprimir_informacoes(INFO_FILME pes, int idade) {
    printf("\n---INFORMACOES DO INGRESSO---\n");
    printf("Filme escolhido: %s\n", pes.filme_escolhido);
    printf("Sessao escolhida: %s\n", pes.sessao_escolhida);
    printf("Assento escolhido: %d\n", pes.assento_escolhido);
    if(idade<18){
      printf("Total a pagar: 5 REAIS\n\n");
    }else{
         printf("Total a pagar: 10 REAIS\n\n");
    }
}


int assento[3]={0,0,0};

//funçao para imprimir os assentos
void imprimir_assento(){
    printf("---ASSENTOS---\n");
    
    for(int i = 0; i < 3; i++){
        printf("ASSENTO:%d\n",assento[i]);
        if(assento[i]==0){printf("DISPONIVEL\n\n");
          }else{printf("INDISPONIVEL\n\n");}
        
    }
}
int esc_assento;//variavel de escolha do assento

void escolher_assento(){
    int op_assento=1;
    do{
    printf("ESCOLHA UM ASSENTO ENTRE 1 A 3\n");
    scanf("%d",&esc_assento);
    
    if(esc_assento<1 || esc_assento>3){
        printf("ASSENTO INEXISTENTE! TENTE NOVAMENTE\n");
        continue;
    }
  
    
    if(assento[esc_assento-1]==0){//o assento[]começa em 0 ou seja se a escolha for 1 o valor iria para o assento 2 
        assento[esc_assento-1]=1;
        printf("---ASSENTO %d RESERVADO---\n",esc_assento);
      //  printf("DESEJA CONSULTAR O INGRESSO?\n-SIM(1)\n-NAO(0)\n");
        op_assento=0;
    
    }else{printf("---ASSENTO JA FOI RESERVADO---\n");
        printf("VC DESEJA ESCOLHER OUTRO ASSENTO?\n-SIM(1)\n-NAO(0)\n");
        scanf("%d",&op_assento);}
    
   } while(op_assento==1);
}

typedef struct { // Struct chamada FILME
    char Titulo_Filme[2][80];
    char genero[2][80];
    char ator_papel[2][80];
} FILME;

typedef struct { // Struct chamada SALA
    int capacidade_sala;
    int CLA_indicativa[2];
    FILME filme;
} SALA;

void consultar_FILME(SALA pes) {
    printf("INFORMACOES DA SALA ESCOLHIDAA:\n");
    for (int i = 0; i < 2; i++) {
        printf("FILME: %s\n", pes.filme.Titulo_Filme[i]);
        printf("CAPACIDADE: %d\n", pes.capacidade_sala);
        printf("GENERO: %s\n", pes.filme.genero[i]);
        printf("ATOR: %s\n", pes.filme.ator_papel[i]);
        printf("CLASSIFICACAO INDICATIVA: %d\n\n", pes.CLA_indicativa[i]);
    }
}

/*typedef struct { // Struct chamada SESSAO
    double valor_int;
    double valor_mei;
} SESSAO;*/

/*typedef struct { // Struct chamada INGRESSO
    char cod_ass_ING[80];
    int tipo_ING;
} INGRESSO;*/


void imprimir_filme(SALA sala) {
    consultar_FILME(sala); //imprimir a funçao consultar filmes
}

int opcao =1;
int main() {
INFO_FILME pes = {"", "", 0};//inicializando pra n dar problemas novamente no strcpy
	do{
	
    int sua_idade, esc_sala;
	printf("\n");
    printf("SALAS DO CINEMA:\nSALA01 - SESSAO DAS 12h-13h & 14h-15h\nSALA02 - SESSAO DAS 16h-17h & 18h-19h\n");
    printf("INGRESSO PADRAO: 10 REAIS\n");
    printf("-------------------------");
    printf("\n");

    printf("DIGITE SUA IDADE:\n");
    scanf("%d", &sua_idade);

    printf("SELECIONE UMA SALA\nSALA01(1)\nSALA02(2)\n");
    scanf("%d", &esc_sala);

    // PRIMEIRA ETAPA DE APRESENTAR O CINEMA
    if (sua_idade < 18 && esc_sala == 2) {
        printf("SALA 2 ESTA DISPONIVEL APENAS PARA MAIORES DE IDADE:\n");
    } else {
        SALA sala1 = {
            .capacidade_sala = 3,
            .CLA_indicativa = {12, 12},
            .filme = {
                .Titulo_Filme = {"Batman", "Homem-formiga"},
                .genero = {"Acao", "Acao"},
                .ator_papel = {"Christian Bale como Batman", "Paul Rudd como Homem-formiga"}
            }
        };
        
        SALA sala2 = {
            .capacidade_sala = 3,
            .CLA_indicativa = {18, 18},
            .filme = {
                .Titulo_Filme = {"O Exorcista", "Atividade Paranormal"},
                .genero = {"Terror", "Terror"},
                .ator_papel = {"Linda Blair como Regan", "Katie Featherston como Katie"}
            }
        };
int esc_filme;
        switch (esc_sala) {
            case 1:
                imprimir_filme(sala1);
    printf("ESCOLHA O FILME:\n");
    printf("DIGITE (1) PARA O FILME DO Batman\nDIGITE (2) PARA O FILME DO Homem-Formiga\n");
     scanf("%d",&esc_filme);
     
            if (esc_filme == 1) {
                
                 imprimir_assento();
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala1.filme.Titulo_Filme[0]);
            strcpy(pes.sessao_escolhida, "SESSAO DAS 12h-13h");
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);  
        
            }else if (esc_filme == 2) {
                 
                  imprimir_assento();
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala1.filme.Titulo_Filme[1]);
            strcpy(pes.sessao_escolhida, "SESSAO DAS 14h-15h");
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);
    
        }
                break;
            case 2:
                imprimir_filme(sala2);
                printf("ESCOLHA O FILME:\n");
    printf("DIGITE (1) PARA O FILME DO O Exorcista\nDIGITE (2) PARA O FILME DO Atividade Paranormal\n");
     scanf("%d",&esc_filme);
            if (esc_filme == 1) {
                
                 imprimir_assento();
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala2.filme.Titulo_Filme[0]);//funçaode copia a string armazenada em sala2.filme.Titulo_Filme[0] e por ai vai 
            strcpy(pes.sessao_escolhida, "SESSAO DAS 16h-17h");
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);
                   
                 
            }else if (esc_filme == 2) {
                
                 imprimir_assento();
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala2.filme.Titulo_Filme[1]);
            strcpy(pes.sessao_escolhida, "SESSAO DAS 18h-19h");
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);
                  
                
                 
        }
                break;
            default:
                printf("SALA INVALIDA\n");
                break;
        }
    }
    printf("EXISTE MAIS ALGUM CLIENTE?\n1-(sim)\n2-(nao)\n");
    scanf("%d",&opcao);

}while(opcao==1);

    return 0;
}
