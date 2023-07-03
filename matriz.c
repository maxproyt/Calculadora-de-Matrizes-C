
#include <stdio.h>
#include <locale.h>
#define INVALIDO "Op��o Inv�lida!, digite uma op��o dentre as dispon�veis.\n"

int main()
{
    int matrix[3][3], opcao, d1prod, d2prod, detsarrus, transposta[3][3], laplace_00, laplace_10, laplace_20, det_laplace, constante, matrix_b[3][3], controlador = 0, soma = 0, matrix_c[3][3], op5;
    setlocale(LC_ALL, "Portuguese");
    printf("*********************************************CALCULADORA DE MATRIZES************************************\n");
    printf("Bem vindo ao programa calculador de matriz(3x3) transposta e determinante, desenvolvido por Victor Motta.\n");
    printf("\n");
    printf("A determinante da matriz pode ser calculada de duas maneiras atrav�s desse programa, por Laplace ou Sarrus.\n");
    printf("\n");
    printf("Para come�ar, digite a matriz 3x3 para a qual deseja aplicar as opera��es.\n");
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            scanf("%d", &matrix[linha][coluna]);
        }
    }
    int n = 2;
    printf("\n");
    printf("Agora escolha a opera��o desejada:\n");
    printf("\n");
    printf("Digite 1 para multiplicar a matriz por uma constante determinada posteriormente.\n");
    printf("Digite 2 para transpor a matriz inserida.\n");
    printf("Digite 3 para obter a determinante pelo m�todo de Sarrus.\n");
    printf("Digite 4 para obter a determinante pelo m�todo de Laplace.\n");
    printf("Digite 5 para multiplicar a matriz inserida(principal) por uma matriz 3x3 definida posteriormente.\n");
    printf("Digite 0 para sair do programa e visualizar a matriz formada pelas opera��es.\n");
    printf("\n");
    while (n > 1)
    {

        scanf("%d", &opcao);

        if (opcao == 2) // TRANSPOSTA
        {

            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    transposta[coluna][linha] = matrix[linha][coluna];
                }
            }
            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    matrix[linha][coluna] = transposta[linha][coluna];
                }
            }
            printf("\n");
            printf("Opera��o de transposi��o feita!\n");
            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    printf("%d ", matrix[linha][coluna]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Insira a pr�xima op��o...\n");
        }
        if (opcao == 3) // SARRUS
        {
            d1prod = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]);
            d2prod = -(matrix[0][2] * matrix[1][1] * matrix[2][0]) - (matrix[0][0] * matrix[1][2] * matrix[2][1]) - (matrix[0][1] * matrix[1][0] * matrix[2][2]);
            detsarrus = d1prod + d2prod;
            printf("\n");
            printf("Diagonal 1: %d  Diagonal 2: %d.\n", d1prod, d2prod);
            printf("(M�todo de Sarrus) O valor da determinante � %d.\n", detsarrus);
            printf("\n");
            printf("Insira a pr�xima op��o...\n");
        }
        if (opcao == 4) // LAPLACE
        {
            laplace_00 = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
            laplace_10 = matrix[1][0] * ((matrix[0][1] * matrix[2][2]) - (matrix[0][2] * matrix[2][1]));
            laplace_20 = matrix[2][0] * ((matrix[0][1] * matrix[1][2]) - (matrix[1][1] * matrix[0][2]));
            det_laplace = laplace_00 - laplace_10 + laplace_20;
            laplace_10 = laplace_10 * -1;
            printf("\n");
            printf("Os cofatores de Laplace para a determinante s�o: %d %d %d.\n", laplace_00, laplace_10, laplace_20);
            printf("(M�todo de Laplace) O valor da determinante � %d\n", det_laplace);
            printf("\n");
            printf("Insira a pr�xima op��o...\n");
        }
        if (opcao == 0) // EXIBIR MATRIZ
        {
            printf("\n");
            printf("A matriz resultante das opera��es feitas � a seguinte:\n");
            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    printf("%d ", matrix[linha][coluna]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Obrigador por utilizar o programa!\n");
            system("pause");
            return 0;
        }
        if (opcao == 1)
        {
            printf("Digite a constante que multiplicar� a matriz:\n");
            scanf("%d", &constante);
            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    matrix[linha][coluna] = matrix[linha][coluna] * constante;
                }
            }

            printf("\n");
            printf("Matriz gerada:\n");

            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    printf("%d ", matrix[linha][coluna]);
                }
                printf("\n");
            }
            printf("\n");
            printf("A multiplica��o foi feita, insira a pr�xima op��o.\n");
        }

        if (opcao == 5)
        {
            printf("\n");
            printf("Digite a Matriz que deseja multiplicar pela matriz principal, definida anteriormente.\n");

            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    scanf("%d", &matrix_b[linha][coluna]);
                }
            }

            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    soma = 0;
                    for (controlador = 0; controlador < 3; controlador++)
                    {

                        soma = soma + matrix[linha][controlador] * matrix_b[controlador][coluna];
                        matrix_c[linha][coluna] = soma;
                    }
                }
            }
            printf("\n");
            printf("A matriz gerada pela multiplica��o das matrizes inseridas � a seguinte:");
            printf("\n");
            for (int linha = 0; linha < 3; linha++)
            {
                for (int coluna = 0; coluna < 3; coluna++)
                {
                    printf("%d ", matrix_c[linha][coluna]);
                }
                printf("\n");
            }
            printf("\n");
            printf("Voc� deseja substituir a matriz principal pela matriz gerada na multiplica��o?\n");
            printf("Digite 1 para Sim.\n");
            printf("Digite 2 para N�o.\n");
            op5 = 0;
            scanf("%d", &op5);
            if (op5 == 1)
                ;
            {
                for (int linha = 0; linha < 3; linha++)
                {
                    for (int coluna = 0; coluna < 3; coluna++)
                    {
                        matrix[linha][coluna] = matrix_c[linha][coluna];
                    }
                }
                printf("A matriz resultante foi definida como principal, escolha a pr�xima op��o de c�lculo sobre ela.\n");
                printf("\n");
            }
        }

        if (opcao > 5 || opcao < 0)
        {
            printf(INVALIDO);
        }
    }
}
