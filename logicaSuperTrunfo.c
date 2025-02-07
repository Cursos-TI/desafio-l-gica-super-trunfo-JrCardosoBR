#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 10 // Limite de cidades a serem armazenadas

// Definindo uma estrutura para armazenar os dados de cada cidade
typedef struct {
    char codigo_estado[10];
    char codigo_cidade[10];
    char cidade[50];
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float pibcapita;
    float densidadep;
} Cidade;

float calcular_super_poder(Cidade cidade) {
    // A soma de todas as propriedades para calcular o "Super Poder"
    return cidade.pib + cidade.pibcapita + cidade.densidadep + cidade.area + cidade.populacao + cidade.pontos_turisticos;
}

void comparar_cartas(Cidade cidade1, Cidade cidade2) {
    printf("\nComparação entre as Cidades:\n");

    // Comparando Densidade Populacional (Vence a carta com menor valor)
    printf("Densidade Populacional:\n");
    if (cidade1.densidadep < cidade2.densidadep) {
        printf("%s vence com %.2f hab./km²\n", cidade1.cidade, cidade1.densidadep);
    } else {
        printf("%s vence com %.2f hab./km²\n", cidade2.cidade, cidade2.densidadep);
    }

    // Comparando as outras propriedades (Vence a carta com maior valor)
    printf("\nPropriedades restantes:\n");

    if (cidade1.area > cidade2.area) {
        printf("Área: %s vence com %.2f km²\n", cidade1.cidade, cidade1.area);
    } else {
        printf("Área: %s vence com %.2f km²\n", cidade2.cidade, cidade2.area);
    }

    if (cidade1.populacao > cidade2.populacao) {
        printf("População: %s vence com %.2f habitantes\n", cidade1.cidade, cidade1.populacao);
    } else {
        printf("População: %s vence com %.2f habitantes\n", cidade2.cidade, cidade2.populacao);
    }

    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("Pontos Turísticos: %s vence com %d pontos\n", cidade1.cidade, cidade1.pontos_turisticos);
    } else {
        printf("Pontos Turísticos: %s vence com %d pontos\n", cidade2.cidade, cidade2.pontos_turisticos);
    }

    if (cidade1.pib > cidade2.pib) {
        printf("PIB: %s vence com %.2f milhões\n", cidade1.cidade, cidade1.pib);
    } else {
        printf("PIB: %s vence com %.2f milhões\n", cidade2.cidade, cidade2.pib);
    }

    if (cidade1.pibcapita > cidade2.pibcapita) {
        printf("PIB per Capita: %s vence com %.2f milhões\n", cidade1.cidade, cidade1.pibcapita);
    } else {
        printf("PIB per Capita: %s vence com %.2f milhões\n", cidade2.cidade, cidade2.pibcapita);
    }

    // Calculando e comparando os Super Poderes
    float super_poder1 = calcular_super_poder(cidade1);
    float super_poder2 = calcular_super_poder(cidade2);

    printf("\nSuper Poder:\n");
    if (super_poder1 > super_poder2) {
        printf("%s vence com Super Poder %.2f\n", cidade1.cidade, super_poder1);
    } else {
        printf("%s vence com Super Poder %.2f\n", cidade2.cidade, super_poder2);
    }
}

int main() {
    Cidade cidades[MAX_CIDADES]; // Vetor para armazenar até MAX_CIDADES cidades
    int contador = 0; // Contador para saber quantas cidades foram adicionadas
    char opcao;

    // Loop principal que permite adicionar várias cidades
    do {
        if (contador >= MAX_CIDADES) {
            printf("Limite de cidades atingido.\n");
            break;
        }

        printf("\nDigite o Código do Estado (ex: SC):\n");
        scanf(" %s", cidades[contador].codigo_estado);

        printf("Digite o Codigo da Cidade  (ex: SC01):\n");
        scanf(" %s", cidades[contador].codigo_cidade);

        printf("Digite o Nome da Cidade:\n");
        getchar(); // Limpa o buffer para evitar problemas com \n
        fgets(cidades[contador].cidade, sizeof(cidades[contador].cidade), stdin);
        cidades[contador].cidade[strcspn(cidades[contador].cidade, "\n")] = 0; // Remove o '\n' no final

        printf("Digite o Numero da Área da Cidade:\n");
        scanf("%f", &cidades[contador].area);

        printf("Digite o Número Populacional da Cidade:\n");
        scanf("%f", &cidades[contador].populacao);

        printf("Digite o Número de Pontos Turísticos da Cidade:\n");
        scanf("%d", &cidades[contador].pontos_turisticos);

        printf("Digite o Número do PIB da Cidade:\n");
        scanf("%f", &cidades[contador].pib);

        // Calculando PIB per capita e densidade populacional
        cidades[contador].pibcapita = cidades[contador].pib / cidades[contador].populacao;
        cidades[contador].densidadep = cidades[contador].populacao / cidades[contador].area;

        printf("               V-V Carta Gerada Com Sucesso! V-V                   \n");
        printf("|-----------------------------------------------------------------|\n");
        printf("              Codigo do Estado: %s                                 \n", cidades[contador].codigo_estado);
        printf("              Codigo da Cidade: %s                                 \n", cidades[contador].codigo_cidade);
        printf("              Nome da Cidade: %s                                   \n", cidades[contador].cidade);
        printf("              Área da Cidade: %.2f km²                             \n", cidades[contador].area);
        printf("              População da Cidade: %.2f Habitantes                 \n", cidades[contador].populacao);
        printf("              Pontos Turísticos da Cidade: %d                      \n", cidades[contador].pontos_turisticos);
        printf("              PIB da Cidade: %.2f                                  \n", cidades[contador].pib);
        printf("              PIB per Capita da Cidade: %.2f Mil                   \n", cidades[contador].pibcapita);
        printf("              Densidade Populacional da Cidade: %.2f hab./km²      \n", cidades[contador].densidadep);
        printf("|-----------------------------------------------------------------|\n");

        contador++; // Aumenta o contador para a próxima cidade

        printf("\nDeseja adicionar outra cidade? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    // Exibe todas as cidades armazenadas até agora
    printf("\nTodas as Cidades Cadastradas:\n");
    for (int i = 0; i < contador; i++) {
        printf("\nCidade %d:\n", i + 1);
        printf("Codigo do Estado: %s\n", cidades[i].codigo_estado);
        printf("Codigo da Cidade: %s\n", cidades[i].codigo_cidade);
        printf("Nome da Cidade: %s\n", cidades[i].cidade);
        printf("Área da Cidade: %.2f km²\n", cidades[i].area);
        printf("População da Cidade: %.2f Habitantes\n", cidades[i].populacao);
        printf("Pontos Turísticos da Cidade: %d\n", cidades[i].pontos_turisticos);
        printf("PIB da Cidade: %.2f \n", cidades[i].pib);
        printf("PIB per Capita da Cidade: %.2f Mil\n", cidades[i].pibcapita);
        printf("Densidade Populacional da Cidade: %.2f hab./km²\n", cidades[i].densidadep);
    }

    // Comparação entre duas cidades cadastradas
    if (contador >= 2) {
        int cidade1, cidade2;
        printf("\nEscolha duas cidades para comparar:\n");
        printf("Escolha a primeira cidade (1 a %d): ", contador);
        scanf("%d", &cidade1);
        printf("Escolha a segunda cidade (1 a %d): ", contador);
        scanf("%d", &cidade2);

        if (cidade1 >= 1 && cidade1 <= contador && cidade2 >= 1 && cidade2 <= contador) {
            comparar_cartas(cidades[cidade1 - 1], cidades[cidade2 - 1]);
        } else {
            printf("Escolha inválida de cidade.\n");
        }
    }

    return 0;
}
