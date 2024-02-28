/*

Classroom
Lecture 21 : Graphs 2
profile picture
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.



Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.



For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note: Order of different edges doesn't matter.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Input Graph



Sample Output 1 :
0 1 3
1 2 1
0 3 5
Input Graph

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// class Edge{
//     public:
//     int source;
//     int dest;

*/

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// class Edge{
//     public:
//     int source;
//     int dest;
//     int weight;
// };

// bool check(vector<bool>&visited, int n){
//     for(int i=0; i<n; i++){
//         if(visited[i]==false) return true;
//     }
//     return false;
// }

// int find_next(vector<bool>&visited, int n, vector<int>&Weight){
//     int mn = 100005;
//     for(int i=0; i<n; i++){
//         if(visited[i]==false){
//             mn=min(mn, Weight[i]);
//         }
//     }
//     return mn;
// }


// void explore(int n, vector<int>&parent, Edge *input, vector<bool>visited, vector<int>&Weight, int current){
//     for(int i=0; i<n; i++){
//         if(input[i].source == current){
//             // dest --
//             int wei = input[i].weight;
//             int des = input[i].dest;
//             if(wei<Weight[des] && !visited[des]){
//                 // update weight
//                 Weight[des] = wei;
//                 // update parent
//                 parent[des] = current;
//             }
//         }
//         else if(input[i].dest ==  current){
//             // source --
//             int wei = input[i].weight;
//             int src = input[i].source;
//             if(wei<Weight[src] && !visited[src]){
//                 // update weight
//                 Weight[src] = wei;
//                 // update parent
//                 parent[src] = current;
//             }
//         }
//     }
// }


// void primsAlgo(Edge *input, int n, int e){
//     vector<int>vertex(n);
//     for(int i=0; i<n; i++){
//         vertex[i] = i;
//     }

//     // default -1
//     vector<int>parent(n, -1);

//     // default weight of all is max except first considering 0
//     vector<int>Weight(n, 100005);
//     Weight[0] = 0;


//     // by default all false
//     vector<bool>visited(n, false);  

//     // consider the source as 0 , so its parent will be -1 and weight 0 

//     // do till all the element in the visited are not true
//     int i=0;
//     while(check(visited, n)){
//         visited[i] = true;
//         // here explore the neighbour of the current i and update its parent and weight
//         explore(n, parent, input, visited, Weight, i);

//         // find the next min from non visited
//         i = find_next(visited, n, Weight);
//     }

//     for(int i=1; i<n; i++){
//         int first = min(parent[i], vertex[i]);
//         int second = max(parent[i], vertex[i]);
//         cout<<first<<" "<<second<<" "<<Weight[i];
//         cout<<endl;
//     }

// }


// int main() {
//     // Write your code here

//     int n, e; cin>>n>>e;

//     Edge *input = new Edge[e];

//     for(int i=0; i<e; i++){
//         int a, b, c; 
//         cin>>a>>b>>c;
//         input[i].source = a;
//         input[i].dest = b;
//         input[i].weight = c;
//     }

//     primsAlgo(input, n, e);
// }






// Above one giving tle don't know why
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<climits>
#include<queue>
using namespace std;
#define ll long long int
const unsigned int mod = 1e9+7;


//(x^y)%mod, use to calculate mod power
// O(log n) -- return  , stl power function O(n)
//power function
int Modpower(int a, int b){
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll res = 1;
    while(b){
        if(b%2==0){
            ll ans = Modpower(a,b/2);
            return (ans*ans)%mod;
        }
        else{
            ll ans = Modpower(a,(b-1)/2);
            return ((a*ans)%mod *ans)%mod;
        }
    }
    return res;
}

int findMinVertex(vector<int>&weights, vector<bool>visited, int n){
    int minVertex = -1;
    for(int i=0; i<n; i++){
        // if minVertex == -1 directly true and update else check for the 2nd condition
        if(!visited[i] & (minVertex == -1 || weights[i]<weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}


void prims1(vector<vector<int>>&edges, int n){
    vector<int>parent(n);
    vector<int>weights(n, INT_MAX);
    vector<bool>visited(n, false);

    // considering the source as 0
    parent[0] = -1;
    weights[0] = 0;
    
    // we can run till n-1 since last ele will automatically add itself, since it won't have any unvisited to check from
    for(int i=0; i<n-1; i++){
        // find Min Vertex
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;

        // explore un visited neighbour
        for(int j=0; j<n; j++){
            // if weight>0 and should be not visited
            if(edges[minVertex][j]!=0 && !visited[j]){
                // if weight is better 
                if(edges[minVertex][j] < weights[j]){
                    // update the weight
                    weights[j] = edges[minVertex][j];
                    // update the parent
                    parent[j] = minVertex;
                }
            }
        }
    }


    for(int i=1; i<n; i++){
        // i = vertex and parent[i] = parent
        int first = min(i, parent[i]);
        int second = max(i, parent[i]);
        cout<<first<<" "<<second<<" "<<weights[i];
        cout<<endl;
    }
}


void prims2(vector<vector<pair<int, int>>>& graph, int n) {
    vector<int> parent(n, -1);
    vector<int> weights(n, INT_MAX);
    vector<bool> visited(n, false);

    // Considering the source as 0
    weights[0] = 0;

    // Priority queue(greatest one on top) to store {weight, vertex} pairs, sorted by weight
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
    pair (the weight of an edge). The pair with the smallest weight will be at the 
    top of the priority queue, allowing efficient retrieval of the minimum-weight edge.
    */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;

        // for (const auto& neighbor : graph[u]) {   -- same 
        for(auto neighbor : graph[u]){
            int v = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[v] && edgeWeight < weights[v]) {
                weights[v] = edgeWeight;
                parent[v] = u;
                pq.push({weights[v], v});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        int first = min(i, parent[i]);
        int second = max(i, parent[i]);
        cout << first << " " << second << " " << weights[i] << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //this is fast I/O (inputput output) use header file <cstdio>
    
    int n, e; cin>>n>>e;

    // adjacency matrix
    // vector<vector<int>>edges(n, vector<int>(n,0));
    
    // using adjacency list
    vector<vector<pair<int,int>>>edges(n);

    for(int i=0; i<e; i++){
        int f, s, weight;
        cin>>f>>s>>weight;
        /*
        for method 1 
        edges[f][s] = weight;
        edges[s][f] = weight;
        */

        // for method 2
       edges[f].push_back({s,weight});
       edges[s].push_back({f, weight});
    }

    // METHOD 1 ---
    // prims1(edges, n);

    // METHOD 2 ---
    prims2(edges, n);


    return 0;
}