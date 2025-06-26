#include <stdio.h>

int main()
{
    // carta 01
    char estado1;
    char codigocarta1[4];
    char nomecidade1[50];
    unsigned long int populacao1;
    int pontostur1;
    float pib1, area_km1;

    // carta 02
    char estado2;
    char codigocarta2[4];
    char nomecidade2[50];
    unsigned long int populacao2;
    int pontostur2;
    float pib2, area_km2;

    // variáveis calculadas
    float densidade1, pib_per_capita1, super_poder1;
    float densidade2, pib_per_capita2, super_poder2;

    // Codigo da Carta 01
    printf("Primeiramente iremos inserir as informações correspondentes a Carta 01!! \n");

    printf("Digite uma letra maiúscula entre A e H (ela irá corresponder à carta 01): \n");
    scanf(" %c", &estado1);

    printf("Digite o codigo da carta (sendo o código correspondente a letra inserida anteriormente + um numero de 01 a 04): \n");
    scanf(" %s", codigocarta1);

    printf("Digite o nome da cidade que a carta corresponderá: \n");
    scanf(" %s", nomecidade1);

    printf("Digite a quantidade da populacao dessa cidade: \n");
    scanf(" %lu", &populacao1);

    printf("Digite a area em km2 da cidade: \n");
    scanf(" %f", &area_km1);

    printf("Digite o pib da cidade: \n");
    scanf(" %f", &pib1);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf(" %i", &pontostur1);

    printf("OK! Você já inseriu os dados da carta 01.\n");

    // Codigo da Carta 02
    printf("Agora iremos inserir as informações correspondentes a Carta 02!! \n");

    printf("Digite uma letra maiúscula entre A e H (ela irá corresponder à carta 02): \n");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta (sendo o código correspondente a letra inserida anteriormente + um numero de 01 a 04): \n");
    scanf(" %s", codigocarta2);

    printf("Digite o nome da cidade que a carta corresponderá: \n");
    scanf(" %s", nomecidade2);

    printf("Digite a quantidade da populacao dessa cidade: \n");
    scanf(" %lu", &populacao2);

    printf("Digite a area em km2 da cidade: \n");
    scanf(" %f", &area_km2);

    printf("Digite o pib da cidade: \n");
    scanf(" %f", &pib2);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf(" %i", &pontostur2);

    // Cálculos
    densidade1 = populacao1 / area_km1;
    pib_per_capita1 = pib1 / populacao1;

    densidade2 = populacao2 / area_km2;
    pib_per_capita2 = pib2 / populacao2;

    super_poder1 = (float)populacao1 + area_km1 + pib1 + pontostur1 + pib_per_capita1 + (1.0f / densidade1);
    super_poder2 = (float)populacao2 + area_km2 + pib2 + pontostur2 + pib_per_capita2 + (1.0f / densidade2);

    // Saída
    printf("\nAs respectivas cartas são:\n\n");

    // Carta 01
    printf("Carta 01: \n");
    printf("Estado: %c \n", estado1);
    printf("Codigo: %s \n", codigocarta1);
    printf("Nome da cidade: %s \n", nomecidade1);
    printf("Quantidade da populacao: %lu \n", populacao1);
    printf("Area em km2: %.2f km²\n", area_km1);
    printf("Pib da cidade: %.2f bilhões de reais\n", pib1);
    printf("Quantidade de pontos turisticos: %i \n", pontostur1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n\n", super_poder1);

    // Carta 02
    printf("Carta 02: \n");
    printf("Estado: %c \n", estado2);
    printf("Codigo: %s \n", codigocarta2);
    printf("Nome da cidade: %s \n", nomecidade2);
    printf("Quantidade da populacao: %lu \n", populacao2);
    printf("Area em km2: %.2f km²\n", area_km2);
    printf("Pib da cidade: %.2f bilhões de reais\n", pib2);
    printf("Quantidade de pontos turisticos: %i \n", pontostur2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparações
    printf("\nComparação de Cartas:\n\n");
    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area_km1 > area_km2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontostur1 > pontostur2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder1 > super_poder2);

    return 0;
}