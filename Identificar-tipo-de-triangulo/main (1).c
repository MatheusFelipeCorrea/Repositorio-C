#include <stdio.h>
#include <stdlib.h>

void identificartipotriangulo(float x1, float y1, float z1) {
    if (x1 < y1 + z1 && y1 < x1 + z1 && z1 < x1 + y1) {
        if (x1 == y1 && y1 == z1) {
            printf("O triangulo é equilátero\n");
        } else if (x1 == y1 || x1 == z1 || y1 == z1) {
            printf("O triangulo é isósceles\n");
        } else {
            printf("O triangulo é escaleno\n");
        }
    } else {
        printf("Não é possivel criar um triangulo.\n");
    }
}

int main() {
    float x, y, z;
    int cn = 1;

    while (cn == 1) {
        printf("Digite os valores do triângulo:\n ");
        scanf("%f %f %f", &x, &y, &z);

        identificartipotriangulo(x, y, z);

        printf("Deseja continuar? (1) sim // (2) não\n");
        scanf("%d", &cn);
    }

    return 0;
}