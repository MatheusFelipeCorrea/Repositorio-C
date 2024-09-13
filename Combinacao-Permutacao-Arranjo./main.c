#include <stdio.h>
#include <stdlib.h>

int fatorial(int N1) {
    int fat = 1;
    while (N1 > 1) {
        fat *= N1;
        N1--;
    }
    return fat;
}

void arranjosimples(int N1, int P1) {
    if (N1 >= P1) {
        int arranjo = fatorial(N1) / fatorial(N1 - P1);
        printf("O resultado do arranjo= %d\n", arranjo);
    }
}

void combinacao(int N1,int P1){
    int combinacao;
    combinacao= fatorial(N1)/(fatorial(P1)*fatorial(N1-P1));
    printf("O resultado da combinacao= %d\n", combinacao);
}

void permutacao(int N1){
    int fat = 1;
    while (N1 > 1) {
        fat *= N1;
        N1--;
    }
    printf("O resultado da permutação simples= %d\n", fat);
}

int main() {
    int N;
    int P;
    int opcao;
    int cn=1;

    while(cn==1) {
        printf("Qual operacao sera feita?\n");
        printf("(1) Arranjo Simples\n");
        printf("(2) Combinacao\n");
        printf("(3) Permutacao\n");
        scanf("%d",&opcao);

        switch(opcao) {
            case 1:
                printf("Insira o valor de N\n");
                scanf("%d",&N);

                printf("insira o valor de P\n");
                scanf("%d",&P);

                arranjosimples(N,P);
                break;
            case 2:
                printf("Insira o valor de N\n");
                scanf("%d",&N);

                printf("insira o valor de P\n");
                scanf("%d",&P);
                combinacao(N,P);
                break;
            case 3:
                printf("Insira o valor de N\n");
                scanf("%d",&N);

                permutacao(N);
        }

        printf("Deseja continuar? (1) sim // (2) não");
        scanf("%d",&cn);
    }
    return 0;
}
