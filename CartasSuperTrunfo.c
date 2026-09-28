
#include <stdio.h>

int main()
{
    // variáveis para armazenar as informações das cartas
    int opcao;
    int carta1 = 1, carta2 = 2;
    char estado1[20] = "A", estado2[20] = "B";
    char codigo1[20] = "A01", codigo2[20] = "B02";
    char cidade1[20] = "FORTALEZA", cidade2[20] = "MANAUS";
    int populacao1 = 2686612, populacao2 = 2255903;
    float area1 = 314.93, area2 = 11401.09;
    float pib1 = 74.12, pib2 = 15.89;
    int ndp1 = 18, ndp2 = 24;

    // densidade populacional = população / área
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // PIB per capita = PIB / população
    float pibPerCapita1 = pib1 / (float)populacao1;
    float pibPerCapita2 = pib2 / (float)populacao2;

    // Super Poder: soma de todos os atributos numéricos, com o inverso da densidade
    float superPoder1 = (float)populacao1 + area1 + pib1 + (float)ndp1 + pibPerCapita1 + (1.0f / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + (float)ndp2 + pibPerCapita2 + (1.0f / densidade2);

    // ===== EXIBIÇÃO DAS CARTAS =====
    printf("\n");
    printf("       ### Jogo SuperTrunfo ###\n");
    printf("\n");

    printf("carta 1\n");
    printf("codigo: %s\n", codigo1);
    printf("estado: %s\n", estado1);
    printf("cidade: %s\n", cidade1);
    printf("população: %d\n", populacao1);
    printf("área: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("número de pontos turísticos: %d\n", ndp1);
    printf("densidade populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.6f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);
    printf("\n");

    printf("carta 2\n");
    printf("codigo: %s\n", codigo2);
    printf("estado: %s\n", estado2);
    printf("cidade: %s\n", cidade2);
    printf("população: %d\n", populacao2);
    printf("área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("número de pontos turísticos: %d\n", ndp2);
    printf("densidade populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.6f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);
    printf("\n");

    // ===== MENU INTERATIVO =====
    printf("         - Menu principal - \n");
    printf("Escolha o atributo para comparar as cartas:\n");
    printf("  1. População\n");
    printf("  2. Área\n");
    printf("  3. PIB\n");
    printf("  4. Pontos turísticos\n");
    printf("  5. Densidade populacional (vence o MENOR valor)\n");
    printf("  Escolha a opção: ");

    // se o usuário digitar letra ou símbolo, encerra com aviso
    if (scanf("%d", &opcao) != 1)
    {
        printf("\nEntrada inválida! Digite apenas números.\n");
        return 1;
    }
    printf("\n");

    // variáveis usadas na comparação (double comporta int e float)
    double valor1 = 0, valor2 = 0;
    const char *atributo = "";
    int casasDecimais = 2; // quantidade de casas ao exibir o valor
    int menorVence = 0;    // 0 = maior vence | 1 = menor vence (densidade)

    // ===== SELEÇÃO DO ATRIBUTO =====
    switch (opcao)
    {
    case 1:
        atributo = "População";
        valor1 = populacao1;
        valor2 = populacao2;
        casasDecimais = 0; // valor inteiro
        break;
    case 2:
        atributo = "Área (km²)";
        valor1 = area1;
        valor2 = area2;
        break;
    case 3:
        atributo = "PIB";
        valor1 = pib1;
        valor2 = pib2;
        break;
    case 4:
        atributo = "Pontos turísticos";
        valor1 = ndp1;
        valor2 = ndp2;
        casasDecimais = 0; // valor inteiro
        break;
    case 5:
        atributo = "Densidade populacional (hab/km²)";
        valor1 = densidade1;
        valor2 = densidade2;
        menorVence = 1; // regra invertida
        break;
    default:
        printf("Opção inválida! Escolha um número de 1 a 5.\n");
        return 1;
    }

    // ===== EXIBIÇÃO DO RESULTADO =====
    printf("=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("Atributo: %s\n", atributo);
    printf("%s: %.*f\n", cidade1, casasDecimais, valor1);
    printf("%s: %.*f\n", cidade2, casasDecimais, valor2);

    if (valor1 == valor2)
    {
        printf("Empate!\n");
    }
    else
    {
        // se menorVence for 1, a regra inverte (densidade)
        int carta1Vence = menorVence ? (valor1 < valor2) : (valor1 > valor2);
        printf("Carta vencedora: %s\n", carta1Vence ? cidade1 : cidade2);
    }

    return 0;
}
