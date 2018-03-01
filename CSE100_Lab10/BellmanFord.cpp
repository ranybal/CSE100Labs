/*
 Nimitt Tripathy 
 December 6th 2017 
 LAB 20 Bellman Ford; 
 Lab 04L
 */

#include <iostream>
#include <limits.h>
using namespace std;


void Init_Single_Source(int *d, int NV){
        for(int i = 0; i < NV; i++) {//INITIALIZE-SINGLE-SOURCE (G,s)
        d[i] = INT_MAX; //v.d = infinity
    }
    d[0] = 0;//d[s] <- 0

}

void RELAX(int **G, int *d, int NV, int NE)
{
    int i;
    int j;
    //d[s] <- 0
    for(i = 1; i < NV; i++) { //for i <- 1 to |V| - 1
        for(j = 0; j < NE; j++) { //for each edge
           int u = G[0][j];
           int v = G[1][j];
           int w = G[2][j];
            if(d[u] != INT_MAX) {//RELAX(u,v,w)
                if(d[v] > d[u] + w){
                d[v] = d[u] + w;//RELAX (u,v,w) d[v] <- d[u] + w(u, v)
                }
            }
        }
    }

}

void PRINT_FUNC(int *d, int NV)
{
    cout << "TRUE" <<endl;
    for(int i = 0; i < NV; i++) {
        if(d[i] < INT_MAX)
            cout << d[i] <<endl; //(0,0), (0,1)... (0, |V|-1), per line
        if(d[i] == INT_MAX) //unreachable
            cout << "INFINITY" <<endl;
    }
}

void Bellman_Ford(int ** G, int NV, int NE) {
    int condition = 1;//case (i), no negative weight cycles reachable from s
    int i, j;
    int d[NV];
    bool reachable = true;
    
    
    //for each vertex V in G
    Init_Single_Source(d, NV);// We initialize the shortest-path estimates and predecessors by the following O(V) Time Procedure
    
    
    RELAX(G, d, NV, NE);// The process of relaxing an edge consists of testing whether we can im- prove the shortest path found so far by going through u and, if so, updating v.d.
    
    for(j = 0; j < NE; j++) { //for each edge (u,v) -> G.E
      int u = G[0][j];
      int v = G[1][j];
      int w = G[2][j];
        if(d[u] != INT_MAX) {
            if(d[G[1][j]] > d[G[0][j]] + G[2][j])//if v.d > u.d + w(u,v)
            condition = 2;//case (ii), there is a negative cycle reachable from s
           // break;
      }
    }
    switch(condition){
        case 1://case (i), no negative weight cycles reachable from s
            PRINT_FUNC(d, NV);
        break;
        case 2:
            cout << "FALSE" << endl;//case (ii), there is a negative cycle reachable from s
        break;
        default:
            NULL;
        
    }
}

int main() {
    
    int i, j;
    int NV = 0;
    int NE = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    cin >> NV;
    cin >> NE;
    int **G;
    G = new int *[3]; //create and initialize the graph
    for(i = 0; i < NV; i++) {
        //G = new int *[3];
        G[i] = new int[NE]; //graph for inputs, vert, weights, etc.
    }
    for(i = 0; i < NE; i++) {
        cin >> u >> v >> w; //read input
        G[0][i] = u; //set from 0 - 2 based on the Graph wrt G(V, E)
        G[1][i] = v;
        G[2][i] = w;
    }
    
    Bellman_Ford(G, NV, NE);
    return 0;
    
}