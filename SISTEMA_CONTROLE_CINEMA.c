#include <stdio.h>
#include <string.h>
//STRUCT CRIADA PARA GUARDAR AS ESCOLHAS DO CLIENTE
typedef struct { 
    char filme_escolhido[80];
    char sessao_escolhida[80];
    int assento_escolhido;
} INFO_FILME;
/*FUNCAO PARA IMPRIMIR AS INFORMACOES COM OS PARAMETROS DE IDADE DO CLIENTE E DO STRUCT DE INFO_FILME*/
void imprimir_informacoes(INFO_FILME pes, int idade) {
    printf("\n---INFORMACOES DO INGRESSO---\n");
    printf("Filme escolhido: %s\n", pes.filme_escolhido);
    printf("Sessao escolhida: %s\n", pes.sessao_escolhida);
    printf("Assento escolhido: %d\n", pes.assento_escolhido);
    if(idade<18){//SE O CLIENTE FOR MENOR DE IDADE ELE PAGA METADE DO VALOR PADRAO DO INGRESSO Q NO CASO É 10 REAIS
      printf("Total a pagar: 5 REAIS\n\n");
    }else{
         printf("Total a pagar: 10 REAIS\n\n");//SENAO O VALOR A SER PAGO E 10 REAIS
    }
}


int assento[3]={0,0,0};//ARRAY DE ASSENTO COM 3 LUGARES. ESSE ARRAY É GLOBAL OU SEJA ELE VALE PARA TODO O CODIGO

//funçao para imprimir os assentos
void imprimir_assento(){
    printf("---ASSENTOS---\n");
    
    for(int i = 0; i < 3; i++){/*LOOP PARA PERCORRER OS ASSENTOS*/
        printf("ASSENTO:%d\n",assento[i]);
        if(assento[i]==0){printf("DISPONIVEL\n\n");//CASO O ASSENTO ELE SEJA IGUAL A 0, ELE É DISPONIVEL... PRIMEIRAMENTE TDOS SAO DISPONOVEIS DE INICIO
          }else{printf("INDISPONIVEL\n\n");}//CASO CONTRARIO E NEGATIVO
        
    }
}
int esc_assento;//MAIS UMA VARIAVEL GLOBAL. DESSA VEZ ELA SERVE PARA GUARDAR A ESCOLHA DO ASSENTO

void escolher_assento(){//FUNÇÃO DA ESCOLHA DO ASSENTO
    int op_assento=1;/*VARIAVEL PARA CONTROLAR DO WHILE... ELE SE INICIA EM 1 E CASO SEJA DIFERENTE ELE TERMINA. É SIMPLES*/
    do{//INICIO DO "LOOP"
    printf("ESCOLHA UM ASSENTO ENTRE 1 A 3\n");
    scanf("%d",&esc_assento);//ESCOLHA DO ASSENTO
    
    if(esc_assento<1 || esc_assento>3){//CASO O CLIENTE ESCOLHA UM ASSENTO Q N EXISTA TIPO 7
        printf("ASSENTO INEXISTENTE! TENTE NOVAMENTE\n");
        continue;//CONTINUE RETORNA PARA O INICIO DO DO WHILE... RETOMANDD A CHANCE DE ESCOLHA DE ASSENTO
    }
  
    
    if(assento[esc_assento-1]==0){//o assento[]começa em 0 ou seja se a escolha for 1 o valor iria para o assento 2 
        assento[esc_assento-1]=1;//SUPOMOS QUE ESC_ASSENTO SEJA 2, NO ARRAY SERIA O {0,0,0} O ASSENTO 3... ENTAO E NECESSARIO E PRATICO SUBTRAIR PARA IMPRIMIR O ASSENTO CORRETO
        printf("---ASSENTO %d RESERVADO---\n",esc_assento);//IMPRIME CORRETAMENTE O ASSENTO 
      //  printf("DESEJA CONSULTAR O INGRESSO?\n-SIM(1)\n-NAO(0)\n");
        op_assento=0;// E CONCLUI O LOOP 
    
    }else{printf("---ASSENTO JA FOI RESERVADO---\n");
        printf("VC DESEJA ESCOLHER OUTRO ASSENTO?\n-SIM(1)\n-NAO(0)\n");//CASO O ASSENTO JA TENHA DONO, ELE DA A CHANCE DE RETOMAR A ESCOLHA
        scanf("%d",&op_assento);}
    
   } while(op_assento==1);//ENQUANTO FOR 1 ELE SE REPETE.
}

typedef struct { // STRUCT DO FILME. GUARDANDO O TITULO ETC
    char Titulo_Filme[2][80];
    char genero[2][80];
    char ator_papel[2][80];
} FILME;

typedef struct { // STRUCT DA SALA... 
    int capacidade_sala;
    int CLA_indicativa[2];
    FILME filme;// O STRUCT DO FILME ESTA AQ DENTRO OU SEJA TUDO NO STRUCT FILME ESTARIA JUNTO COM A SALA OBVIAMENTE
} SALA;

void consultar_FILME(SALA pes) {//PARAMENTRO DA SALA
    printf("INFORMACOES DA SALA ESCOLHIDAA:\n");
    for (int i = 0; i < 2; i++) {
        printf("FILME: %s\n", pes.filme.Titulo_Filme[i]);//EU GERALMENTE USO "pes" POR PURO COSTUME MEU MESMO
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


void imprimir_filme(SALA sala) {//FUNCAO COM UNICO PROPOSITO DE DEIXAR MAIS ORGANIZADO O CODIGO MESMO
    consultar_FILME(sala); //IMPRIME A FUNÇAO DE CONSULTA COM PARAMETRO SALA
}

int opcao =1;//VARIAVEL GLOBAL PARA DO WHILE DENTRO DO MAIN
int main() {
INFO_FILME pes = {"", "", 0};//inicializando pra n dar problemas novamente no strcpy
	do{//INICIO DO LOOP 
	
    int sua_idade, esc_sala;//VARIAVEIS DE IDADE E ESCOLHA DA SALA
	printf("\n");
    printf("SALAS DO CINEMA:\nSALA01 - SESSAO DAS 12h-13h & 14h-15h\nSALA02 - SESSAO DAS 16h-17h & 18h-19h\n");
    printf("INGRESSO PADRAO: 10 REAIS\n");
    printf("-------------------------");
    printf("\n");

    printf("DIGITE SUA IDADE:\n");
    scanf("%d", &sua_idade);//LENDO A IDADE

    printf("SELECIONE UMA SALA\nSALA01(1)\nSALA02(2)\n");
    scanf("%d", &esc_sala);//LENDO A ESCOLHA DA SALA

    // PRIMEIRA ETAPA DE APRESENTAR O CINEMA
    if (sua_idade < 18 && esc_sala == 2) {
        printf("SALA 2 ESTA DISPONIVEL APENAS PARA MAIORES DE IDADE:\n");//A SALA 2 É EXCLUSIVA PARA MAIORES DE IDADE
    } else {/*CASO CONTRARIO É INICIALIZADO AS INFO DA SALA 1 E 2... ACHEI MAIS FACIL ASSIM MAS DEVE TER OUTRA MANEIRA*/
        SALA sala1 = {
            .capacidade_sala = 3,
            .CLA_indicativa = {12, 12},
            .filme = {//FILME JA É UMA STRUCT DENTRO DE OUTRA POR ISSO A { } 
                .Titulo_Filme = {"Batman", "Homem-formiga"},
                .genero = {"Acao", "Acao"},
                .ator_papel = {"Christian Bale como Batman", "Paul Rudd como Homem-formiga"}
            }
        };
        
        SALA sala2 = {//A MESMA COISA DA SALA 1 ACIMA SO MUDANDO AS INFO
            .capacidade_sala = 3,
            .CLA_indicativa = {18, 18},
            .filme = {
                .Titulo_Filme = {"O Exorcista", "Atividade Paranormal"},
                .genero = {"Terror", "Terror"},
                .ator_papel = {"Linda Blair como Regan", "Katie Featherston como Katie"}
            }
        };
int esc_filme;//VARIAVEL DA ESCOLHA DO FILME
        switch (esc_sala) {//EXISTEM DOIS CASES PARA ESTE SWITCH
            case 1://PRIMEIRO CASE
                imprimir_filme(sala1);/*IMPRIME ASS INFORMACOES DA SAALA 1*/
    printf("ESCOLHA O FILME:\n");
    printf("DIGITE (1) PARA O FILME DO Batman\nDIGITE (2) PARA O FILME DO Homem-Formiga\n");
     scanf("%d",&esc_filme);//LENDO A ESCOLHA DO FILME
     
            if (esc_filme == 1) {//SE A ESCOLHA FOR O FILME 1
                
                 imprimir_assento();
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala1.filme.Titulo_Filme[0]);
            strcpy(pes.sessao_escolhida, "SESSAO DAS 12h-13h");
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);  
        
            }else if (esc_filme == 2) {//SE A ESCOLHA FOR O FILME 2
                 
                  imprimir_assento();//IMPRIME AS FUNCOES DE MAIS CEDO
                 escolher_assento();
            strcpy(pes.filme_escolhido, sala1.filme.Titulo_Filme[1]);//STRCPY É UMA FERRAMENTA DA BIBLIOTECA STRING.H E SERVE PARA COPIAR UMA STRING
            strcpy(pes.sessao_escolhida, "SESSAO DAS 14h-15h");//NESTE CASO SO TA ACRESCENTANDO NA STRING sessao_escolhida
            pes.assento_escolhido = esc_assento;
            imprimir_informacoes(pes, sua_idade);/*STRUCT DAS INFO NOVAMENTE QUE IMPRIME AS INFO COM OS PARAMETROS DE PES E A IDADE*/
    
        }
                break;
            case 2:
            	//ESSA PARTE É A PRIMEIRA PARTE APENAS MUDANDO AS INFORMAÇOES DA SESSAO E FILME
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
                printf("SALA INVALIDA\n");//CASO O CASE N SEJA ESCOLHIDO CERTO ELE QUEBRA O CODIGO
                break;
        }
    }
    printf("EXISTE MAIS ALGUM CLIENTE?\n1-(sim)\n2-(nao)\n");//E DEPOIS PERGUNTA SE EXISTE MAIS UM CLIENTE
    scanf("%d",&opcao);//VARIAVEL DE CONTROLE DO DO WHILE

}while(opcao==1);

    return 0;
}
