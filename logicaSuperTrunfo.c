#include <stdio.h>

/*
  Super Trunfo – Nível Aventureiro
  Interatividade via menu (switch) + comparações com if / if-else (aninhadas).

  Cartas fixas (reaproveitando do desafio anterior):
    - Sao Paulo (SP)
    - Rio de Janeiro (RJ)

  Atributos:
    - Nome da cidade (string) [apenas exibição]
    - População (int)
    - Área (float, km²)
    - PIB (float, bilhões de R$)
    - Pontos turísticos (int)
    - Densidade demográfica (float, hab/km²)  [derivado]
    - PIB per capita (float, R$/hab)          [derivado]

  Regras:
    - Regra geral: maior valor vence
    - EXCEÇÃO: densidade demográfica -> MENOR valor vence
    - Empate: usa-se um DESEMPATE por "pontos turísticos" (maior vence).
      Persistindo empate, imprime "Empate!".
*/

static void linha(void) { printf("===========================================\n"); }

int main(void) {
    /* ====== Carta 1 – São Paulo ====== */
    const char estado1[]  = "SP";
    const char codigo1[]  = "A1";
    const char cidade1[]  = "Sao Paulo";
    const int  populacao1 = 12300000;   // ~12,3 mi
    const float area1     = 1521.0f;    // km²
    const float pib1      = 750.0f;     // bi R$
    const int  pontos1    = 25;

    /* ====== Carta 2 – Rio de Janeiro ====== */
    const char estado2[]  = "RJ";
    const char codigo2[]  = "B2";
    const char cidade2[]  = "Rio de Janeiro";
    const int  populacao2 = 6710000;    // ~6,71 mi
    const float area2     = 1200.0f;    // km²
    const float pib2      = 360.0f;     // bi R$
    const int  pontos2    = 20;

    /* ====== Derivados ====== */
    const float dens1 = (area1 > 0.0f) ? ( (float)populacao1 / area1 ) : 0.0f;
    const float dens2 = (area2 > 0.0f) ? ( (float)populacao2 / area2 ) : 0.0f;

    const float pcap1 = (populacao1 > 0) ? ( (pib1 * 1e9f) / (float)populacao1 ) : 0.0f;
    const float pcap2 = (populacao2 > 0) ? ( (pib2 * 1e9f) / (float)populacao2 ) : 0.0f;

    int opcao;

    /* Tela inicial com as cartas */
    linha();
    printf("CARTAS CADASTRADAS\n");
    linha();
    printf("Carta 1 — %s (%s) | Cod: %s\n", cidade1, estado1, codigo1);
    printf("Populacao: %d | Area: %.2f km² | PIB: %.2f bi R$ | Pontos: %d\n", populacao1, area1, pib1, pontos1);
    printf("Densidade: %.2f hab/km² | PIB per capita: R$ %.2f\n\n", dens1, pcap1);

    printf("Carta 2 — %s (%s) | Cod: %s\n", cidade2, estado2, codigo2);
    printf("Populacao: %d | Area: %.2f km² | PIB: %.2f bi R$ | Pontos: %d\n", populacao2, area2, pib2, pontos2);
    printf("Densidade: %.2f hab/km² | PIB per capita: R$ %.2f\n", dens2, pcap2);
    linha();

    do {
        /* ===== Menu interativo ===== */
        printf("MENU - Escolha o atributo para comparar:\n");
        printf(" 1 - Populacao (maior vence)\n");
        printf(" 2 - Area (maior vence)\n");
        printf(" 3 - PIB (maior vence)\n");
        printf(" 4 - Pontos Turisticos (maior vence)\n");
        printf(" 5 - Densidade Demografica (MENOR vence)\n");
        printf(" 6 - PIB per capita (maior vence)\n");
        printf(" 0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            /* entrada inválida: limpa buffer e força default */
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            opcao = -1;
        }

        linha();

        int vencedora = 0; /* 0=empate; 1=carta1; 2=carta2 */

        switch (opcao) {
            case 1: /* População - maior vence */
                printf("Comparacao por POPULACAO\n");
                printf("%s: %d  |  %s: %d\n", cidade1, populacao1, cidade2, populacao2);

                if (populacao1 > populacao2) {
                    vencedora = 1;
                } else if (populacao2 > populacao1) {
                    vencedora = 2;
                } else {
                    /* empate -> desempate por pontos turísticos (if aninhado) */
                    if (pontos1 > pontos2) vencedora = 1;
                    else if (pontos2 > pontos1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 2: /* Área - maior vence */
                printf("Comparacao por AREA\n");
                printf("%s: %.2f km²  |  %s: %.2f km²\n", cidade1, area1, cidade2, area2);

                if (area1 > area2) {
                    vencedora = 1;
                } else if (area2 > area1) {
                    vencedora = 2;
                } else {
                    if (pontos1 > pontos2) vencedora = 1;
                    else if (pontos2 > pontos1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 3: /* PIB - maior vence */
                printf("Comparacao por PIB\n");
                printf("%s: %.2f bi R$  |  %s: %.2f bi R$\n", cidade1, pib1, cidade2, pib2);

                if (pib1 > pib2) {
                    vencedora = 1;
                } else if (pib2 > pib1) {
                    vencedora = 2;
                } else {
                    if (pontos1 > pontos2) vencedora = 1;
                    else if (pontos2 > pontos1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 4: /* Pontos turísticos - maior vence */
                printf("Comparacao por PONTOS TURISTICOS\n");
                printf("%s: %d  |  %s: %d\n", cidade1, pontos1, cidade2, pontos2);

                if (pontos1 > pontos2) {
                    vencedora = 1;
                } else if (pontos2 > pontos1) {
                    vencedora = 2;
                } else {
                    /* se empatar em pontos turísticos, desempata por PIB per capita */
                    if (pcap1 > pcap2) vencedora = 1;
                    else if (pcap2 > pcap1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 5: /* Densidade - MENOR vence */
                printf("Comparacao por DENSIDADE DEMOGRAFICA (menor vence)\n");
                printf("%s: %.2f hab/km²  |  %s: %.2f hab/km²\n", cidade1, dens1, cidade2, dens2);

                if (dens1 < dens2) {
                    vencedora = 1; /* menor vence */
                } else if (dens2 < dens1) {
                    vencedora = 2;
                } else {
                    if (pontos1 > pontos2) vencedora = 1;
                    else if (pontos2 > pontos1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 6: /* PIB per capita - maior vence */
                printf("Comparacao por PIB PER CAPITA\n");
                printf("%s: R$ %.2f  |  %s: R$ %.2f\n", cidade1, pcap1, cidade2, pcap2);

                if (pcap1 > pcap2) {
                    vencedora = 1;
                } else if (pcap2 > pcap1) {
                    vencedora = 2;
                } else {
                    if (pontos1 > pontos2) vencedora = 1;
                    else if (pontos2 > pontos1) vencedora = 2;
                    else vencedora = 0;
                }
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        if (opcao >= 1 && opcao <= 6) {
            if (vencedora == 1) {
                printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
            } else if (vencedora == 2) {
                printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
            } else {
                printf("\nResultado: Empate!\n");
            }
            linha();
        }

    } while (opcao != 0);

    return 0;
}

