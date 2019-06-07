#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

const int INF = INT_MAX;

typedef struct Node {
    vector <pair<Node *, int>> neighbours;
    int val, dist;
} Node;

Node *newNode(int val) {
    Node *n = new Node;
    n->val = val;
    n->dist = INF;
	return n;
}

void addEdge(Node *u, Node *v, int w) {
    pair <Node *, int> edge(v, w);
    u->neighbours.push_back(edge);
}

void relax(Node *u, Node *v, int weight) {
     if(u->dist>v->dist+weight){
        u->dist=v->dist+weight;
        
    }
   
}

bool bellmann_ford(Node **nodes, int n, Node *start) {
    start->dist=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
              for(int k=0;k<nodes[j]->neighbours.size();k++){
            relax(nodes[j]->neighbours[k].first,nodes[j],nodes[j]->neighbours[k].second);
            
        }
        
    }
    }
     for(int j=0;j<n;j++){
              for(int k=0;k<nodes[j]->neighbours.size();k++){
            if(nodes[j]->neighbours[k].first->dist>nodes[j]->dist+nodes[j]->neighbours[k].second)return false;
            
        }
     }
        return true;
     
}

int main() {
    int N, k, start, end;
    cin >> N >> k;
    Node *nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(i);

    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(nodes[u], nodes[v], w);
    }

    cin >> start >> end;
    if (!bellmann_ford(nodes, N, nodes[start])) cout << "CYKL" << endl;
    else if (nodes[end]->dist < INF) cout << nodes[end]->dist << endl;
    else cout << "NIE" << endl;

    for(int i=0; i<N; i++) delete nodes[i];
}