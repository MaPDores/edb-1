#include <stdio.h>
#include <stdlib.h>
#include "../united-states-map/united-states-map.h"
#include "../stack/stack.h"

void printPath(FILE* arq, int pathCount, int path[]) {
    for (int i = 0; i < pathCount; i++) {
        fprintf(arq, " %s\n", findCityByIndex(path[i]));
        printf(" %s\n", findCityByIndex(path[i]));
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




void DFS(FILE* arq, int graph[41][41], int* visited, int v, int n, int *trav, int *tind) {
	fprintf(arq, "executando DFS...");

	visited[v] = 1;
    fprintf(arq, "visitando -%d-", v);

	trav[(*tind)++] = v;

	for (int i = 0; i < n; i++)
        if (graph[v][i] > 0 && visited[i] != 1)
            DFS(arq, graph, visited, i, n, trav, tind);
}

int *dfs(FILE* arq, int graph[41][41], int n) {
	//int visited[41] = {0};
    int* visited = (int*)malloc(sizeof(int) * n);
	int* trav = (int*)malloc(sizeof(int) * n);
	int tind = 0;

	for (int i = 0; i < n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i]) {
			DFS(arq, graph, visited, i, n, trav, &tind);
		}
	free(visited);
	return trav;
}




int hamilton (FILE* arq, int X, int graph[42][42], int path[], int* pathCount, int visited[]) {
    stack s; initStack(&s); //inicia pilha
    visited[X]++; //salva visita de X
    //fprintf(arq, "Visitando %s\n", findCityByIndex(X));
    //printf("Visitando %s\n", findCityByIndex(X));
    int count = 0; //instancia de count pra verificar adjacencia
    for (int i = 0; i < 42; i++) { //loop pra cada cidade adjacente
        if (graph[X][i] > 0) {  //se maior que 0
            if (i == path[41 + 1]) //se igual cidade inicial (path[0] ou algo assim)
                if (hasVisitedAll(visited)) { //se passou por todos
                    //printf("cidade: %s\nindex: %d\npath count: %d\n\n", findCityByIndex(i), i, (*pathCount));
                    path[(*pathCount)++] = i;
                    return 1;
                }
            count++;
            push(&s, i);
        }
    }
    if (count == 1) {//se count for 1
        //nem verifica, 
        int w = pop(&s);//só popa em w
        //e lasca o hamiltão nele
        if (hamilton(arq, w, graph, path, pathCount, visited)) { //se resposta do hamiltão for 1
            //printf("cidade: %s\nindex: %d\npath count: %d\n\n", findCityByIndex(w), w, (*pathCount));
            path[(*pathCount)++] = w;//adiciona w no path
            return 1;
        }
    } else { //senão
        while (!isEmpty(s)) { //enquanto pilha não vazia
            int w = pop(&s);
            if (!visited[w]) //se não visitou
                if (hamilton(arq, w, graph, path, pathCount, visited)) { //se( hamilton == 1 )
                    //printf("cidade: %s\nindex: %d\npath count: %d\n\n", findCityByIndex(w), w, (*pathCount));
                    path[(*pathCount)++] = w; //adiciona w no path
                    return 1;
                }
        }
    }
    visited[X]--;
    //fprintf(arq, "Saindo de %s\n", findCityByIndex(X));
    //printf("Saindo de %s\n", findCityByIndex(X));
    return 0;
}


void main (int argc, char* argv[]) {
    // Set initial city
    int X = 17;

    FILE *arq = fopen("heuristic.log", "w");
    int path[42 + 1];
    int pathCount = 0;
    int visited[42] = {0};

    path[42] = X;
    if (hamilton(arq, X, map, path, &pathCount, visited)) {

        printPath(arq, pathCount, path);
    } else {
        printf("Não deu!");
    }

//    int greater = 0;
//    for (int i = 0; i < CITYCOUNT; i++) {
//        int visited[CITYCOUNT] = { 0 };
//        int path[CITYCOUNT*CITYCOUNT] = { 0 };
        
        //int* path = dfs(arq, map1, 41);
        
//        printf("Beginning in: %d makes -%d- value\n\n", i, pathCount);
//        if (greater < pathCount)
//            greater = pathCount;
//    }
//    printf("O maior foi: -%d-\n\n", greater);
    fclose(arq);
    /*fprintf(arq, "\n============================================\n");
    fprintf(arq, "Path Count: %d\n", pathCount);*/
    //printPath(arq, 41, path);
}