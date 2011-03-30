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
};









int main(int argc, char** argv) {

    return 0;
}

