#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int contador = 0;
    char operacao; // M (multiplicacao) ou S (soma)
    float resultado = 0;
    int i, j;
    float numeros;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    float matriz[n][n];


    // Cria a matriz com números aleatórios entre 0 e 99
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            numeros = rand() % 100;
            matriz[i][j] = numeros;
        }
    }



    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == (n - 1) - i) { //diagonal secundária
                printf("\033[0;31m%.0f\033[0m\t", matriz[i][j]); //Vermelho

            } else if (j > (n - 1) - i) { //abaixo da diagonal
                printf("%.0f\t", matriz[i][j]); //Branco

            } else if(i + j < (n - 1)){ //acima da diagonal
                printf("\033[0;32m%.0f\033[0m\t", matriz[i][j]); //Verde
            }
        }
        printf("\n");
    }



    printf("Digite a operacao (S ou M): ");
    scanf(" %c", &operacao);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            if (i + j < (n - 1)) // Acima da diagonal secundária
            {
                resultado += matriz[i][j];
                contador += 1;
            }
        }
    }



    if (operacao == 'M') //média
    {
        resultado /= contador;
    }

    printf("%.1f\n", resultado);

    return 0;
}
