/*

Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void helper(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
// bool helper(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
    visited[start] = true;


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void helper(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
// bool helper(vector<vector<int>>&edges, int n, vector<bool>&visited, int start){
    visited[start] = true;

    for(int i=0; i<n; i++){
        if(i==start) continue;

        if(edges[start][i]==1 && !visited[i]){
            // visited[i] = true;
            helper(edges, n, visited, i);
        }
    }

    // for(auto it:visited){
    // //     if(it==false){
    // //         return false;
    // //     }
    //     cout<<it<<" ";
    // }
    // cout<<"hehe"<<start<<" new number"<<endl;
    // return true;
}


bool check(vector<vector<int>>&edges, int n){

    // METHOD 1 ---DFS APPROACH
    /*
    vector<bool>visited(n, false);

    helper(edges, n, visited, 0);

    for(auto it:visited){
        if(it==false)return false;
    }
    return true;
    */


    // METHOD 2 --- BFS APPROACH
    vector<bool>visited(n, false);
    queue<int>q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(i==current) continue;
            if(edges[current][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    } 

    for(auto it:visited){
        if(it==false) return false;
    }
    return true;
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

    if(E==0 && V>1) cout<<"false"<<endl;
    else {

        if(check(edges, V)){
            cout<<"true"<<endl;
        }
        else cout<<"false"<<endl;
    }

}