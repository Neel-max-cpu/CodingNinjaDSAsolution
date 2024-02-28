/*
Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, vector<int>&temp, int start){
    visited[start] = true;
    temp.push_back(start);


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, vector<int>&temp, int start){
    visited[start] = true;
    temp.push_back(start);

    for(int i=0; i<n; i++){
        if(i==start) continue;

        if(edges[start][i] == 1 && !visited[i]){
            dfs_traversal(edges, n, visited, temp, i);
        }
    }
}


void dfs(vector<vector<int>>&edges, int n){
    vector<bool>visited(n, false);

    vector<vector<int>>ans;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int>temp;
            dfs_traversal(edges, n, visited, temp, i);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }

    for(auto it:ans){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void bfs_traversal(vector<vector<int>>&edges, int n, vector<bool>&visited, vector<int>&temp, int start){
    queue<int>q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        temp.push_back(current);
        for(int i=0; i<n; i++){
            if(i==current) continue;
            if(edges[current][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}


void bfs(vector<vector<int>>&edges, int n){
    vector<bool>visited(n, false);
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int>temp;
            bfs_traversal(edges, n, visited, temp, i);
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }

    for(auto it:ans){
        for(auto x:it) cout<<x<<" ";
        cout<<endl;
    }
}


int main() {
    // Write your code here
    int V,E; cin>>V>>E;

    vector<vector<int>>edges(V, vector<int>(V,0));

    for(int i=0; i<E; i++){
        int f, s; cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // METHOD 1 --- dfs
    // dfs(edges, V);


    // METHOD 2 --- BFS
    bfs(edges, V);

}