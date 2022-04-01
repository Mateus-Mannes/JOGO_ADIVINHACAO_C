#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Imprime Cabecalho
    printf("**************************************\n");
    printf("Bem Vindo Ao Nosso Jogo De Adivinhacao\n");
    printf("**************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numeroGrande = rand();

    int numeroSecreto = numeroGrande % 100;
    int ganhou = 0;
    double pontos = 1000;
    int acertou = 0;
    int numeroTentativas;
    int tentativas = 0;

    int nivel;
    printf("Escolha um nivel Facil(1) Medio(2) Dificil(3): ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1: numeroTentativas = 20; break;
        case 2: numeroTentativas = 15; break;
        default: numeroTentativas = 6; break;
    }

    for(int i = 1; i <= numeroTentativas; i++){
        tentativas = i;
        int chute;
        printf("Chute %d\n", i);
        printf("Qual o seu chute? ");
        scanf("%d", &chute);
        if(chute < 0){
            printf("Voce nao pode usar numeros negativos\n");
            continue;
        }
        printf("Seu chute foi %d\n", chute);

        
        acertou = chute == numeroSecreto;

        if(acertou){
            break;
        }
        else
        {
            if(chute > numeroSecreto){
                printf("Seu chute foi maior\n");
            }
            else{
                printf("Seu chute foi menor\n");
            }
            double pontosPerdidos =  abs(chute - numeroSecreto)/(double)2;
            pontos = pontos - pontosPerdidos;
            
        }
    }

printf("Fim de jogo\n");
if(acertou){
printf("Voce acertou em %d tentativas\n", tentativas);
printf("Total de pontos: %.2f\n", pontos);
} else{
    printf("Voce perdeu, tente de novo");
}
            

}