/*

Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

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
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;



vector<int>*helper(vector<vector<int>>&edges, int n, int start, int end, vector<bool>&visited){

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;



vector<int>*helper(vector<vector<int>>&edges, int n, int start, int end, vector<bool>&visited){

    queue<int>q;
    unordered_map<int,int>m;
    vector<int>*ans = new vector<int>();
    q.push(start);
    visited[start] = true;


    while(!q.empty()){
        int current = q.front();
        if(current == end){
            ans->push_back(current);
            break;
        }
        q.pop();

        for(int i=0; i<n; i++){
            if(edges[current][i]==1 && !visited[i]){
                visited[i] = true;
                // i = vertex(children) and current = parent
                m[i] = current;
                q.push(i);
            }
        }
    }

    // for(auto it:m){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    // cout<<"new line"<<endl;

    // keep track of the the parent as value not as key; children->parent
    if(ans->size()>0){
        /*
        int a = ans->at(0);
        while(a!=start){
            auto it = m.find(a);
            ans->push_back(it->second);
            a = it->second;
        }
        return ans;
        */
        // OR 
        int a = end;
        // don't push since already pushed int the map
        while(a!=start){
            a = m[a];
            ans->push_back(a);
        }
        return ans;
    }
    return NULL;

}


vector<int>*getbfs(vector<vector<int>>&edges, int n, int a, int b){
    vector<bool>visited(n, false);
    vector<int>*ans = helper(edges, n, a, b, visited);

    return ans;
}

vector<int>*gethelper(vector<vector<int>>&edges, int n, int start, int end){

    queue<int>q;
    vector<bool>visited(n, false);

    q.push(start);
    visited[start] = true;

    bool pathfound = false;

    // FOR METHOD 2 -- we use vector
    // vector<int>parent(n, -1);   

    // FOR METHOD 3 -- we use map
    unordered_map<int,int>parent;

    while(!q.empty() && !pathfound){
        int current = q.front();
        q.pop();

        for(int i=0; i<n; i++){
            if(edges[current][i]==1 && !visited[i]){
                // parent[i] = current will remain the same for METHOD 3 AND METHOD 2
                parent[i] = current;
                q.push(i);
                visited[i] = true;
                if(i==end){
                    pathfound = true;
                    break;
                }
            }
        }
    }

    if(!pathfound){
        return NULL;
    }

    vector<int>*output = new vector<int>();
    int current = end;
    output->push_back(current);
    while(current!=start){
        // for METHOD 2 and METHOD 3-- this too will remain the same
        current = parent[current];
        output->push_back(current);
    }

    return output;

}


int main() {
    // Write your code here

    int V, E; cin>>V>>E;

    vector<vector<int>>edges(V, vector<int>(V,0));
    for(int i=0; i<E; i++){
        int f,s; cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int a, b; cin>>a>>b;

    // METHOD 1 ----
    /*
    vector<int>*output = getbfs(edges, V, a, b);
    if(output!=NULL){
        for(int i=0; i<output->size(); i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
        cout<<endl;
    }
    */

    // METHOD 2---
    /*
    vector<int>*output = gethelper(edges, V, a, b);
    if(output!=NULL){
        for(int i=0; i<output->size(); i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
        cout<<endl;
    }
    */

    // METHOD 3 -- mix of method 2 and 1
    vector<int>*output = gethelper(edges, V, a, b);
    if(output!=NULL){
        for(int i=0; i<output->size(); i++){
            cout<<output->at(i)<<" ";
        }
        delete output;
        cout<<endl;
    }
}