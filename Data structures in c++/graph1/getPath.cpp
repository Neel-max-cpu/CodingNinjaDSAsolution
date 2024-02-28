/*
Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using DFS and print the first path that you encountered.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1:
3 0 1
Sample Input 2:
6 3
5 3
0 1
3 4
0 3
Sample Output 2:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool checkDfs(vector<vector<int>>& edges, int n, int start, int end, vector<bool>& visited, vector<int>&ans) {
    // base case
    if (start == end) {
        ans.push_back(start);

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool checkDfs(vector<vector<int>>& edges, int n, int start, int end, vector<bool>& visited, vector<int>&ans) {
    // base case
    if (start == end) {
        ans.push_back(start);
        return true;
    }

    // ans.push_back(start);
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
            if(checkDfs(edges, n, i, end, visited, ans)){
                ans.push_back(start);
                return true;
            }
        }
    }
    return false;
}

void dfs(vector<vector<int>>&edges, int n, int a, int b){
    vector<bool>visited(n, false);

    vector<int>ans;
    // if(checkDfs(edges, n, b, a, visited, ans)){
    if(checkDfs(edges, n, a, b, visited, ans)){
        // reverse(ans.begin(), ans.end());
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }
    else {
        return;
    }
    // for(auto it:ans) cout<<it<<" ";
//     cout<<"New line "<<endl;
//     reverse(ans.begin(), ans.end());
//     for(auto it:ans) cout<<it<<" ";
}


vector<int>*helper(vector<vector<int>>&edges, int n, int start, int end, vector<bool>&visited){
    if(start == end){
        vector<int>*output = new vector<int>();
        output->push_back(start);
        return output;
    }

    visited[start] = true;
    for(int i=0; i<n; i++){
        if(edges[start][i] == 1 && !visited[i]){
            vector<int>*smallOuput = helper(edges, n, i, end, visited);
            if(smallOuput!=NULL){
                smallOuput->push_back(start);
                return smallOuput;
            }
        }
    }
    return NULL;
}

vector<int>* getdfs(vector<vector<int>>&edges, int n, int start, int end){
    vector<bool>visited(n, false);
    vector<int>*output = helper(edges, n, start, end, visited);

    return output;
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
    int a, b; cin>>a>>b;
    // METHOD 1 ---- my
    // dfs(edges, V, a, b);

    // METHOD 2----
    vector<int>*output = getdfs(edges, V, a, b);
    
    if(output!=NULL){
        for(int i=0; i<output->size(); i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
    }
} 