/* The Algorithm design manual p.153
 *
 * http://www.cppreference.com/wiki/algorithm/start --algorithms defined in <algorithm>
 */

//#include <cstdlib>
//#include <iostream>
//
//#define MAXV 1000
//
//using namespace std;
//
//struct edgenode {
//    int y;
//    int weight;
//    struct edgenode *next;
//};
//
//struct graph {
//  edgenode *edges[MAXV + 1];
//  int degree[MAXV + 1];
//  int nvertices;
//  int nedges;
//  bool directed;
//};
//
//void initializeGraph(graph *g, bool directed) {
//    g->nvertices = 0;
//    g->nedges = 0;
//    g->directed = directed;
//
//    for(int i = 1; i <= MAXV; i++) {
//        g->degree[i] = 0;
//    }
//
//    for(int i = 1; i <= MAXV; i++) {
//        g->edges[i] = NULL;
//    }
//}
//
//void insertEdge(graph *g, int x, int y, bool directed) {
//
//    struct edgenode *p = NULL;
//    p = (struct edgenode*)malloc(sizeof(struct edgenode));
//    p->y = y;
//    p->weight = NULL;
//    p->next = g->edges[x];
//
//    g->edges[x] = p;
//    g->degree[x] ++;
//
//    if(directed == false)
//        insertEdge(g, x, y, true);
//    else
//        g->nedges ++;
//}
//
//void readGraph(graph *g, bool directed) {
//    int m;
//    int x, y;
//
//    initializeGraph(g, directed);
//    scanf("%d %d", &(g->nvertices), &m);
////    cin >> g->nvertices;
//  //  cin >> m;
//    for(int i = 1; i <= m; i++) {
//    //    cin >> x >> y;
//	scanf("%d %d", &x, &y);
//
//        insertEdge(g, x, y, directed);
//    }
//}
//
//
//void printGraph(graph *g) {
//
//    edgenode *p;
//    for(int i = 1; i <= g->nvertices; i++) {
//	printf("%d : ", i);
//	//cout <<i<<": "<<endl;
//        p = g->edges[i];
//
//        while(!p) {
//           // cout <<p->y<<endl;
//	    printf("p->y: ", p->y);
//            p = p->next;
//        }
//        printf("\n"); //cout <<" "<<endl;
//    }
//}
//
//





/**************************************************************/



#include <iostream>
using namespace std;

struct node {
    int info;
    node *next;
};

class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void add(int);
    int get();
private:
    node *first, *last;
};

class Graph {
public:
    Graph(int size = 2);
    ~Graph();
    bool isConnected(int, int);
    // adds the (x, y) pair to the edge set
    void addEdge(int x, int y);
    // performs a Breadth First Search starting with node x
    void BFS(int x);
    // searches for the minimum length path
    // between the start and target vertices
    void minPath(int start, int target);
private:
    int n;
    int **A;
};

Queue::Queue() {
    first = new node;
    first->next = NULL;
    last = first;
}

Queue::~Queue() {
    delete first;
}

bool Queue::isEmpty() {
    return (first->next == NULL);
}

void Queue::add(int x) {
    node *aux = new node;
    aux->info = x;
    aux->next = NULL;
    last->next = aux;
    last = aux;
}

int Queue::get() {
    node *aux = first->next;
    int value = aux->info;
    first->next = aux->next;
    if (last == aux) last = first;
    delete aux;
    return value;
}

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
        delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int x, int y) {
    return (A[x - 1][y - 1] == 1);
}

void Graph::addEdge(int x, int y) {
    A[x - 1][y - 1] = A[y - 1][x - 1] = 1;
}

void Graph::BFS(int x) {
    Queue Q;
    bool *visited = new bool[n + 1];
    int i;
    for (i = 1; i <= n; ++i)
        visited[i] = false;
    Q.add(x);
    visited[x] = true;
    cout << "Breadth First Search starting from vertex ";
    cout << x << " : " << endl;
    while (!Q.isEmpty()) {
        int k = Q.get();
        cout << k << " ";
        for (i = 1; i <= n; ++i)
            if (isConnected(k, i) && !visited[i]) {
                Q.add(i);
                visited[i] = true;
            }
    }
    cout << endl;
    delete [] visited;
}

void Graph::minPath(int start, int target) {
    Queue Q;
    int i, p, q;
    bool found;

    struct aux {
        int current, prev;
    };
    aux *X = new aux[n + 1];
    int *Y = new int[n + 1];
    bool *visited = new bool[n + 1];
    for (i = 1; i <= n; ++i)
        visited[i] = false;
    Q.add(start);
    visited[start] = true;
    found = false;
    p = q = 0;
    X[0].current = start;
    X[0].prev = 0;
    while (!Q.isEmpty() && !found) {
        int k = Q.get();
        for (i = 1; i <= n && !found; ++i)
            if (isConnected(k, i) && !visited[i]) {
                Q.add(i);
                ++q;
                X[q].current = i;
                X[q].prev = p;
                visited[i] = true;
                if (i == target) found = true;
            }
        ++p;
    }
    cout << "The minimum length path from " << start;
    cout << " to " << target << " is : " << endl;
    p = 0;
    while (q) {
        Y[p] = X[q].current;
        q = X[q].prev;
        ++p;
    }
    Y[p] = X[0].current;
    for (q = 0; q <= p / 2; ++q) {
        int temp = Y[q];
        Y[q] = Y[p - q];
        Y[p - q] = temp;
    }
    for (q = 0; q <= p; ++q)
        cout << Y[q] << " ";
    cout << endl;
    cout << "Length = " << q - 1 << endl;
    delete [] visited;
    delete [] X;
    delete [] Y;
}






int main(int argc, char** argv) {

//    graph *g = NULL;
//    insertEdge(g, 1, 2, false);
//    insertEdge(g, 2, 3, false);
//    insertEdge(g, 2, 3, false);
//
//    readGraph(g, false);
//    printGraph(g);
    return 0;
}

