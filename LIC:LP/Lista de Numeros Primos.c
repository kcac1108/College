//Kaua Cordeiro Cavalheiro
//lista de numeros primos

#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printPrimes(int n) {
    int counter = 1;
    int prime = 2;
    int prevPrime = 0;
    int diff = 0;

    printf("Contador | Numero Primo | Diferenca | Grafico\n");
    printf("----------------------------------------------\n");

    while (counter <= n) {
        if (isPrime(prime)) {
            diff = prime - prevPrime;

            printf("   %2d        %4d           %2d        ", counter, prime, diff);

            for (int i = 0; i < diff; i++) {
                printf("*");
            }
            printf("\n");

            prevPrime = prime;
            counter++;
        }

        prime++;
    }
}

int main() {
    int N;

    do {
        printf("Digite a quantidade de números primos que deseja exibir (ou 0 para sair): ");
        scanf("%d", &N);

        if (N > 0) {
            printPrimes(N);
        }
    } while (N != 0);

    return 0;
}