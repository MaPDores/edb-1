#include <stdio.h>
#include <stdlib.h>
#include "../united-states-map/united-states-map.h"
//#include "../stack/stack.h"

void printPath(FILE* arq, int pathCount, int path[], int visited[CITYCOUNT]) {
    for (int i = 0; i < pathCount; i++) {
        fprintf(arq, " %s (visited %d times)\n", findCityByIndex(path[i]), visited[path[i]]);
        printf(" %s (visited %d times)\n", findCityByIndex(path[i]), visited[path[i]]);
    }
}

int hasVisitedAll(int visited[CITYCOUNT]) {
    for (int i = 0; i < CITYCOUNT; i++) {
        if (visited[i] == 0)
            return 0;
    }
    return 1;
}

int algorithm(FILE* arq, int initial, int path[], int visited[CITYCOUNT], int graph[CITYCOUNT][CITYCOUNT]) {
    int pathCount = 0;
    //int visited[CITYCOUNT] = { 0 };
    int currentCity = initial;

    fprintf(arq, "Ponto inicial = %d\n", initial);
    path[pathCount++] = initial;
    visited[currentCity]++; 

    while (1) {

        int option = -1;
        fprintf(arq, "Verificando cidades adjacentes...\n");
        for (int i = 0; i < CITYCOUNT; i++) {
            if (graph[currentCity][i] > 0) {
                fprintf(arq, "Achou! Cidade = %d\n", i);
                if (i == initial && hasVisitedAll(visited)) {
                    fprintf(arq, "Acabou!\n");
                    path[pathCount++] = initial;
                    return pathCount;
                }
                /* DESCOMENTAR POIS É O CÓDIGO CORRETO
                if (option == -1 || visited[i] < visited[option]) {
                    fprintf(arq, "É a melhor opção!\n");
                    option = i;
                }*/
                /*REMOVER*/
                if (visited[i] == 0) {
                    fprintf(arq, "É a melhor opção!\n");
                    option = i;
                }
                /*REMOVER*/
            }
        }
        /*REMOVER*/
        if (option == -1) {
            for (int i = 0; i < CITYCOUNT; i++) {
                if (graph[currentCity][i] > 0) {
                    fprintf(arq, "Achou! Cidade = %d\n", i);
                    if (i == initial && hasVisitedAll(visited)) {
                        fprintf(arq, "Acabou!\n");
                        path[pathCount++] = initial;
                        return pathCount;
                    }
                    if (option == -1 || visited[i] < visited[option]) {
                        fprintf(arq, "É a melhor opção!\n");
                        option = i;
                    }
                }
            }
            //fprintf(arq, "Não foi possivel completar o problema");
            //printf("Não foi possivel completar o problema");
            //return pathCount;
        }
        /*REMOVER*/


        fprintf(arq, "\nVisitando cidade = %d\n\n", option);
        currentCity = option;
        path[pathCount++] = currentCity;
        visited[currentCity]++;
    }
}

void main (int argc, char* argv[]) {
    FILE* arq = fopen("heuristic.log", "w");

    int greater = 0;
    for (int i = 0; i < CITYCOUNT; i++) {
        int visited[CITYCOUNT] = { 0 };
        int path[CITYCOUNT*CITYCOUNT] = { 0 };
        
        int pathCount = algorithm(arq , i, path, visited, map);
        
        printf("Beginning in: %d makes -%d- value\n\n", i, pathCount);
        if (greater < pathCount)
            greater = pathCount;
    }
    printf("O maior foi: -%d-\n\n", greater);
    /*fprintf(arq, "\n============================================\n");
    fprintf(arq, "Path Count: %d\n", pathCount);
    printPath(arq, pathCount, path, visited);*/
}