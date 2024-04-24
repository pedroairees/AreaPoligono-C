#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para representar um ponto no plano
typedef struct {
    float x;
    float y;
} Ponto;

// Função para calcular a área de um triângulo usando determinantes
float areaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * abs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)));
}

// Função para calcular a área de um polígono
float areaPoligono(Ponto vertices[], int num_vertices) {
    float area_total = 0.0;
    int i;

    // Calcular a área de cada triângulo formado pelos vértices consecutivos do polígono
    for (i = 1; i < num_vertices - 1; i++) {
        area_total += areaTriangulo(vertices[0], vertices[i], vertices[i+1]);
    }

    return area_total;
}

int main() {
    // Abrir o arquivo de entrada
    FILE *arquivo;
    arquivo = fopen("vertices.txt", "r");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ler o número de vértices do polígono do arquivo
    int num_vertices;
    fscanf(arquivo, "%d", &num_vertices);

    // Criar um array de pontos para armazenar os vértices do polígono
    Ponto vertices[num_vertices];

    // Ler os vértices do polígono do arquivo
    int i;
    for (i = 0; i < num_vertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].x, &vertices[i].y);
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Calcular a área do polígono
    float area = areaPoligono(vertices, num_vertices);

    // Exibir a área calculada
    printf("A area do poligono e: %.2f\n", area);

    return 0;
}
