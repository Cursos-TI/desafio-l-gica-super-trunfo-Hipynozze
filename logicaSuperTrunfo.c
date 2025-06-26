#include <stdio.h>

int main() {
    // Dados da Carta 1
    char estado1[3];
    char codigocarta1[5];
    char nomecidade1[50];
    unsigned long int populacao1;
    int pontosTur1;
    float pib1, areaKm1;

    // Dados da Carta 2
    char estado2[3];
    char codigocarta2[5];
    char nomecidade2[50];
    unsigned long int populacao2;
    int pontosTur2;
    float pib2, areaKm2;

    // Variáveis derivadas
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;

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

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // ----- Comparação por um único atributo: População -----
    printf("\n============================================\n");
    printf("Comparação de Cartas (Atributo: População)\n");
    printf("============================================\n");

    printf("Carta 1 - %s (%s): %lu habitantes\n", nomecidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu habitantes\n", nomecidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomecidade1);
    } else if (populacao2 > populacao1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomecidade2);
    } else {
        printf("\nResultado: Empate! Ambas as cidades têm a mesma população.\n");
    }

    return 0;
}
