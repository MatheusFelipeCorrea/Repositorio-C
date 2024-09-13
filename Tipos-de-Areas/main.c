#include <stdio.h>

void Quadrado(int aresta1) {
    int area = aresta1 * aresta1;
    printf("Area do quadrado = %d\n", area);
}

void Retangulo(int base1, int altura1) {
    int area = base1 * altura1;
    printf("Area do retângulo = %d\n", area);
}

void Cubo(int base1, int altura1) {
    int area = 6 * (base1 * altura1);
    printf("Area do cubo = %d\n", area);
}

void Triangulo(int base1, int altura1) {
    int area = (base1 * altura1) / 2;
    printf("Area do triângulo = %d\n", area);
}

int main() {
    int base, altura, opcao, cn = 1, aresta;

    while (cn == 1) {
        printf("Selecione a opção:\n");
        printf("(1) Area do quadrado\n");
        printf("(2) Area do retângulo\n");
        printf("(3) Area do cubo\n");
        printf("(4) Area do triângulo retângulo\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Entre com o valor da aresta: ");
                scanf("%d", &aresta);
                Quadrado(aresta);
                break;
            case 2:
                printf("Entre com o valor da Altura: ");
                scanf("%d", &altura);
                printf("Entre com o valor da Base: ");
                scanf("%d", &base);
                Retangulo(base, altura);
                break;
            case 3:
                printf("Entre com o valor da Altura: ");
                scanf("%d", &altura);
                printf("Entre com o valor da Base: ");
                scanf("%d", &base);
                Cubo(base, altura);
                break;
            case 4:
                printf("Entre com o valor da Altura: ");
                scanf("%d", &altura);
                printf("Entre com o valor da Base: ");
                scanf("%d", &base);
                Triangulo(base, altura);
                break;
        }

        printf("Deseja continuar? (1) Sim // (2) Não: ");
        scanf("%d", &cn);
    }

    return 0;
}