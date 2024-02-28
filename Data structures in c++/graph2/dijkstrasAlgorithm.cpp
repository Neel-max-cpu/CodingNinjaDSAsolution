/*

Classroom
Lecture 21 : Graphs 2
profile picture
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Input Graph

Sample Output 1 :
0 0
1 3
2 4
3 5


Input Graph

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<climits>
#include<queue>
using namespace std;

int min_distance_vertex(vector<int>&distance, vector<bool>&visited, int n){

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<climits>
#include<queue>
using namespace std;

int min_distance_vertex(vector<int>&distance, vector<bool>&visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}


void dijkstraAlgo1(vector<vector<int>>&edges, int n){
    vector<bool>visited(n, false);
    vector<int>distance(n, INT_MAX);
    distance[0] = 0;

    for(int i=0; i<n-1; i++){
        int u = min_distance_vertex(distance, visited, n);

        visited[u] = true;
        // explore all neighbours
        for(int j=0; j<n; j++){
            if(edges[u][j]!=0 && !visited[j]){
                int new_dist = distance[u] + edges[u][j];
                if(distance[j]>new_dist){
                    distance[j] = new_dist;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}


void dijkstraAlgo2(vector<vector<pair<int, int>>>& edges, int n) {
   vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);


    // Considering the source as 0
    distance[0] = 0;

    // Priority queue(greatest one on top) to store {distance, vertex} pairs, sorted by weight
    // so using greater<int> we get the smallest one on the top
    /*
        synatax :
        priority_queue<int>pq --- max
       priority_queue <int, vector<int>, greater<int>> pq; -- min 

       so here -- priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       meaning 
       pair --- meaning 2 elements are there
       and vector pair and greater int to make it min heap
    */
    /*
    the overall meaning is that the priority queue (pq) is a min-heap that stores pairs of 
    integers, where the priority is determined by the first element of the 
    pair (the distance of an edge). The pair with the smallest distance will be at the 
    top of the priority queue, allowing efficient retrieval of the minimum-distance edge.
    */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;

        for (const auto& neighbor : edges[u]) {
            int v = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[v] && distance[u] != INT_MAX && distance[u] + edgeWeight < distance[v]) {
                distance[v] = distance[u] + edgeWeight;
                pq.push({distance[v], v});
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}

int main() {
    // Write your code here

    int n, e; cin>>n>>e;

    // adjacency matrix
    // vector<vector<int>>edges(n, vector<int>(n,0));
    
    // using adjacency list
    vector<vector<pair<int,int>>>edges(n);
    
    for(int i=0; i<e; i++){
        int f,s,w;
        cin>>f>>s>>w;
        /*
        // for method 1 
        edges[f][s] = w;
        edges[s][f] = w;
        */

        // for method 2
       edges[f].push_back({s,w});
       edges[s].push_back({f, w});
    }


    // METHOD 1 ---
    // very similar to Prim's algo(almost same)
    // dijkstraAlgo1(edges, n);
    
    
    // METHOD 2 ---
    dijkstraAlgo2(edges, n);

}