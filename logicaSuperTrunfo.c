#include <stdio.h>
#include <string.h>

int main() {
    // Dados da Carta 1
    char estado1[3], codigocarta1[5], nomecidade1[50];
    unsigned long int populacao1;
    int pontosTur1;
    float pib1, areaKm1;

    // Dados da Carta 2
    char estado2[3], codigocarta2[5], nomecidade2[50];
    unsigned long int populacao2;
    int pontosTur2;
    float pib2, areaKm2;

    // Variáveis derivadas
    float densidade1, densidade2;

    // ----- Entrada de dados: Carta 1 -----
    printf("Cadastro da Carta 1:\n");
    printf("Digite a sigla do estado (ex: SP): ");
    scanf(" %s", estado1);
    printf("Digite o código da carta: ");
    scanf(" %s", codigocarta1);
    printf("Digite o nome da cidade: ");
    scanf(" %s", nomecidade1);
    printf("Digite a populacao da cidade: ");
    scanf(" %lu", &populacao1);
    printf("Digite a area em km² da cidade: ");
    scanf(" %f", &areaKm1);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf(" %f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &pontosTur1);

    // ----- Entrada de dados: Carta 2 -----
    printf("\nCadastro da Carta 2:\n");
    printf("Digite a sigla do estado (ex: RJ): ");
    scanf(" %s", estado2);
    printf("Digite o código da carta: ");
    scanf(" %s", codigocarta2);
    printf("Digite o nome da cidade: ");
    scanf(" %s", nomecidade2);
    printf("Digite a populacao da cidade: ");
    scanf(" %lu", &populacao2);
    printf("Digite a area em km² da cidade: ");
    scanf(" %f", &areaKm2);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf(" %f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &pontosTur2);

    // ----- Cálculos -----
    densidade1 = populacao1 / areaKm1;
    densidade2 = populacao2 / areaKm2;

    // ----- Menu Interativo -----
    int opcao;
    printf("\n=========== MENU DE COMPARAÇÃO ===========\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    printf("\n========== RESULTADO DA COMPARAÇÃO ==========\n");
    printf("Cidade 1: %s (%s)\n", nomecidade1, estado1);
    printf("Cidade 2: %s (%s)\n", nomecidade2, estado2);

    switch(opcao) {
        case 1: // População
            printf("\nComparando População:\n");
            printf("%s: %lu habitantes\n", nomecidade1, populacao1);
            printf("%s: %lu habitantes\n", nomecidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", nomecidade1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", nomecidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("\nComparando Área:\n");
            printf("%s: %.2f km²\n", nomecidade1, areaKm1);
            printf("%s: %.2f km²\n", nomecidade2, areaKm2);
            if (areaKm1 > areaKm2)
                printf("Resultado: %s venceu!\n", nomecidade1);
            else if (areaKm2 > areaKm1)
                printf("Resultado: %s venceu!\n", nomecidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("\nComparando PIB:\n");
            printf("%s: R$ %.2f bilhões\n", nomecidade1, pib1);
            printf("%s: R$ %.2f bilhões\n", nomecidade2, pib2);
            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", nomecidade1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", nomecidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("\nComparando Pontos Turísticos:\n");
            printf("%s: %d pontos\n", nomecidade1, pontosTur1);
            printf("%s: %d pontos\n", nomecidade2, pontosTur2);
            if (pontosTur1 > pontosTur2)
                printf("Resultado: %s venceu!\n", nomecidade1);
            else if (pontosTur2 > pontosTur1)
                printf("Resultado: %s venceu!\n", nomecidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (regra invertida)
            printf("\nComparando Densidade Demográfica (menor vence):\n");
            printf("%s: %.2f hab/km²\n", nomecidade1, densidade1);
            printf("%s: %.2f hab/km²\n", nomecidade2, densidade2);
            if (densidade1 < densidade2)
                printf("Resultado: %s venceu!\n", nomecidade1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu!\n", nomecidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
