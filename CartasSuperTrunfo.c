#include <stdio.h>

int main()
{
    // variáveis para armazenar as informações das cartas
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
    // (population1 é int, então forçamos o cast pra float pra não truncar a divisão)
    float pibPerCapita1 = pib1 / (float)populacao1;
    float pibPerCapita2 = pib2 / (float)populacao2;

    printf("escolha o numero da carta: opção 1 ou opção 2\n");
    printf("\n");

    // carta 1
    scanf("%d", &carta1);
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

    printf("escolha o numero da carta: opção 1 ou opção 2\n");
    printf("\n");

    // carta 2
    scanf("%d", &carta2);
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

    printf("\n");
    return 0;
}
