#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int cn, j;
    int is_prime;

    printf("Digite um numero (para encerrar, digite 0): ");
    scanf("%d", &n);

    while (n != 0) {
        if (n < 2) {
            printf("Nao existem numeros primos neste intervalo.\n");
        } else {
            printf("Numeros primos no intervalo ate %d:\n", n);

            cn = 2;
            while (cn <= n) {
                is_prime = 1; // Assume que o número é primo
                j = 2;

                while (j <= cn / 2) {
                    if (cn % j == 0) {
                        is_prime = 0; // Não é primo se for divisível por algum número
                        break;
                    }
                    j++;
                }

                if (is_prime) {
                    printf("%d ", cn); // Imprime o número primo
                }
                cn++;
            }
            printf("\n");
        }

        printf("\nDigite um numero (para encerrar, digite 0): ");
        scanf("%d", &n);
    }

    return 0;
}
