#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <queue>

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
    pair <Node *, int> u_edge(v, w);
    pair <Node *, int> v_edge(u, w);
    u->neighbours.push_back(u_edge);
    v->neighbours.push_back(v_edge);
}

auto cmp = [](Node *x, Node *y) { return x->dist > y->dist; };

bool relax(Node *u, Node *v, int weight) {
    if(u->dist>v->dist+weight){
        u->dist=v->dist+weight;
        return true;
    }
    return false;
}

void dijkstra(Node **nodes, int n, Node *start) {
    priority_queue <Node *, vector<Node *>, decltype(cmp)> queue(cmp);
  
    start->dist=0;
   
    queue.push(start);
    while(!queue.empty()){
       Node* u=queue.top();
        queue.pop();
    
        for(int i=0;i<u->neighbours.size();i++){
            if(relax(u->neighbours[i].first,u,u->neighbours[i].second)){
              
                queue.push(u->neighbours[i].first);
            }
            
        }
        
    }
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
    
    dijkstra(nodes, N, nodes[start]);
    
    cout << nodes[end]->dist << endl;

    for (int i=0; i<N; i++) delete nodes[i];
}