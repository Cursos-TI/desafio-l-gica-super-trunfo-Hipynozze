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

    // Entrada de dados: Carta 1
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

    // Entrada de dados: Carta 2
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

    // Validação das áreas para evitar divisão por zero
    if (areaKm1 <= 0 || areaKm2 <= 0) {
        printf("Erro: A área de uma cidade não pode ser zero ou negativa.\n");
        return 1;
    }

    // Cálculo da densidade demográfica
    densidade1 = populacao1 / areaKm1;
    densidade2 = populacao2 / areaKm2;

    // ---------- Escolha dos dois atributos ----------
    int atributo1, atributo2;
    int atributosUsados[6] = {0};

    printf("\n=========== MENU DE ATRIBUTOS ===========\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica (menor vence)\n");
    printf("Digite a opção: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 1;
    }

    atributosUsados[atributo1] = 1;

    printf("\nEscolha o SEGUNDO atributo para comparar:\n");
    for (int i = 1; i <= 5; i++) {
        if (!atributosUsados[i]) {
            switch(i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos turísticos\n"); break;
                case 5: printf("5 - Densidade demográfica (menor vence)\n"); break;
            }
        }
    }
    printf("Digite a opção: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida! Encerrando o programa.\n");
        return 1;
    }

    // ---------- Comparação ----------
    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;

    // Atribuição dos valores conforme escolha
    switch(atributo1) {
        case 1: valor1_attr1 = populacao1; valor2_attr1 = populacao2; break;
        case 2: valor1_attr1 = areaKm1; valor2_attr1 = areaKm2; break;
        case 3: valor1_attr1 = pib1; valor2_attr1 = pib2; break;
        case 4: valor1_attr1 = pontosTur1; valor2_attr1 = pontosTur2; break;
        case 5: valor1_attr1 = densidade1; valor2_attr1 = densidade2; break;
        default: printf("Erro ao escolher o primeiro atributo.\n"); return 1;
    }

    switch(atributo2) {
        case 1: valor1_attr2 = populacao1; valor2_attr2 = populacao2; break;
        case 2: valor1_attr2 = areaKm1; valor2_attr2 = areaKm2; break;
        case 3: valor1_attr2 = pib1; valor2_attr2 = pib2; break;
        case 4: valor1_attr2 = pontosTur1; valor2_attr2 = pontosTur2; break;
        case 5: valor1_attr2 = densidade1; valor2_attr2 = densidade2; break;
        default: printf("Erro ao escolher o segundo atributo.\n"); return 1;
    }

    // Resultado
    printf("\n========== RESULTADO DA COMPARAÇÃO ==========\n");
    printf("Cidade 1: %s (%s)\n", nomecidade1, estado1);
    printf("Cidade 2: %s (%s)\n\n", nomecidade2, estado2);

    char *nomeAtributo[6] = {
        "", "População", "Área", "PIB", "Pontos Turísticos", "Densidade Demográfica"
    };

    printf("1º Atributo: %s\n", nomeAtributo[atributo1]);
    printf("  %s: %.2f\n", nomecidade1, valor1_attr1);
    printf("  %s: %.2f\n\n", nomecidade2, valor2_attr1);

    printf("2º Atributo: %s\n", nomeAtributo[atributo2]);
    printf("  %s: %.2f\n", nomecidade1, valor1_attr2);
    printf("  %s: %.2f\n\n", nomecidade2, valor2_attr2);

    // Regra: maior vence, exceto densidade (menor vence)
    float soma1 = 0, soma2 = 0;

    if (atributo1 == 5) {
        soma1 += -valor1_attr1;
        soma2 += -valor2_attr1;
    } else {
        soma1 += valor1_attr1;
        soma2 += valor2_attr1;
    }

    if (atributo2 == 5) {
        soma1 += -valor1_attr2;
        soma2 += -valor2_attr2;
    } else {
        soma1 += valor1_attr2;
        soma2 += valor2_attr2;
    }

    // Soma real (para exibir corretamente)
    float somaReal1 = (atributo1 == 5 ? -valor1_attr1 : valor1_attr1) + (atributo2 == 5 ? -valor1_attr2 : valor1_attr2);
    float somaReal2 = (atributo1 == 5 ? -valor2_attr1 : valor2_attr1) + (atributo2 == 5 ? -valor2_attr2 : valor2_attr2);

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", nomecidade1, somaReal1);
    printf("  %s: %.2f\n", nomecidade2, somaReal2);

    printf("\nResultado final: ");
    if (soma1 > soma2)
        printf("%s venceu!\n", nomecidade1);
    else if (soma2 > soma1)
        printf("%s venceu!\n", nomecidade2);
    else
        printf("Empate!\n");

    return 0;
}
