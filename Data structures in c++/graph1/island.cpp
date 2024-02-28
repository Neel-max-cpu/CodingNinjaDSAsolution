/*

Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
    visited[start] = true;
    for(int i=0; i<n; i++){

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
    visited[start] = true;
    for(int i=0; i<n; i++){
        if(i==start) continue;
        
        if(edges[start][i] == 1 && !visited[i]){
            dfs_traversal(edges, n, visited, i);
        }
    }
}

int dfs(vector<vector<int>>&edges, int n){
    vector<bool>visited(n, false);

    int count = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs_traversal(edges, n, visited, i);
            count++;
        }
    }

    return count;
}


void bfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(i==current) continue;
            
            if(edges[current][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int bfs(vector<vector<int>>&edges, int n){
    vector<bool>visited(n, false);

    int count = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs_traversal(edges, n, visited, i);
            count++;
        }
    }

    return count;
}





int main() {
    // Write your code here

    int V,E; cin>>V>>E;

    vector<vector<int>>edges(V, vector<int>(V,0));

    for(int i=0; i<E; i++){
        int f,s; cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // using dfs
    // cout<<dfs(edges, V)<<endl;

    // using bfs
    cout<<bfs(edges, V)<<endl;
    
}