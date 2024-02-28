/*
Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



bool checkDfs(vector<vector<int>>& edges, int n, int start, int end, vector<bool>& visited) {
    // base case

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



bool checkDfs(vector<vector<int>>& edges, int n, int start, int end, vector<bool>& visited) {
    // base case
   if(start==end) return true;

    visited[start] = true;
    for (int i = 0; i < n; i++) {
        if (start == i) continue;

        // if (edges[start][i] == 1) {
        //     if (visited[i]) continue;
        //     if (checkDfs(edges, n, i, end, visited)) {
        //         return true;
        //     }
        // }

        if(edges[start][i] == 1 && !visited[i]){
            if(checkDfs(edges, n, i, end, visited)){
                return true;
            }
        }
    }
    return false;
}

void dfs(vector<vector<int>>& edges, int n, int a, int b) {
    vector<bool> visited(n, false);

    if (checkDfs(edges, n, a, b, visited)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

bool checkBfs(vector<vector<int>>& edges, int n, int start, int end, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == end) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (edges[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return false;
}

void bfs(vector<vector<int>>& edges, int n, int a, int b) {
    vector<bool> visited(n, false);

    // start from a 
    if (checkBfs(edges, n, a, b, visited)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int a, b;
    cin >> a >> b;

    // using dfs
    dfs(edges, V, a, b);

    // using bfs
    // bfs(edges, V, a, b);

    return 0;
}
