/*

Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected and disconnected graph G(V, E), print its BFS traversal.

Note:

1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;


*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& graph, int start, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        for (int i = 0; i < graph.size(); i++) {
            // if (graph[current][neighbor] == 1 && !visited[neighbor]) {
            if (graph[current][i] == 1 && !visited[i]) {
                // visited[neighbor] = true;
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void bfsTraversal(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited);
        }
    }
}


void print_bfs(vector<vector<int>>&edges, int n, int starting_vertex){
    queue<int>q;
    vector<bool>visited(n, false);
    
    q.push(starting_vertex);
    visited[starting_vertex] =  true;

    while(!q.empty()){
        int currentVertex = q.front();
        cout<<currentVertex<<" ";
        q.pop();
        for(int i=0; i<n; i++){
            if(i==currentVertex) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}   


int main() {

    // METOHD 1--- all correct 
    // /*
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1; // Assuming undirected graph
    }

    bfsTraversal(graph, V);
    // */
    
    
    // METHOD 2 --- not all correct
    /*
    int v,e; cin>>v>>e;

    if(v>=0 && e==0) {
        for(int i=0; i<v; i++){
            cout<<i<<" ";
        }
        return 0;
    }

    vector<vector<int>>edges(v, vector<int>(v,0));

    for(int i=0; i<e; i++){
        int f, s; cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    print_bfs(edges, v, 0);
    */


    return 0;
}

