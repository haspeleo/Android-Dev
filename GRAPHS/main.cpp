/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 30 mars 2011, 09:24
 */

#include <cstdlib>

#define MAXV 1000

using namespace std;

typedef struct{
    int y;
    int weight;
    struct edgenode *next;
} edgenode;


typedef struct {
  edgenode *edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  bool directed;
} graph;

void initializeGraph(graph *g, bool directed) {
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;

    for(int i = 1; i < MAXV; i++) {
        g->degree[i] = 0;
    }

    for(int i = 1; i < MAXV; i++) {
        g->edges[i] = NULL;
    }
}




void readGraph(graph *g, bool directed) {
    int m;
    int x, y;

    initializeGraph(g, directed);

    cin >> g->nvertices >> m;
    for(int i = 0; i <  m; i++) {
        cin >> x >> y;
        insertEdge(g, x, y, directed);
    }
}

void insertEdge(graph *g, int x, int y, bool directed) {
    
    edgenode *p;
    p = malloc(sizeof(struct edgenode));
    p->y = y;
    p->weight = NULL;
    p->next = g->degree[x];

    g->edges[x] = p;
    g->degree[x] ++;

    if(directed == false)
        insertEdge(g, x, y, true);
    else
        g->nedges ++;
}

void printGraph(graph *g) {

    edgenode *p;
    for(int i = 0; i < g->nvertices; i++) {
        cout <<i<<": "<<endl;
        p = g->edges[i];

        while(!p) {
            cout <<p->y<<endl;
            p = p->next;
        }
        cout <<" "<<endl;
    }
}

int main(int argc, char** argv) {

    return 0;
}

