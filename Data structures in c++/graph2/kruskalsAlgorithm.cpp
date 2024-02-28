/*

Classroom
Lecture 21 : Graphs 2
profile picture
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
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
1 2 1
0 1 3
0 3 5
Input Graph

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// FOR METHOD 2 ----
class Edge{
    public:
    int source;

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// FOR METHOD 2 ----
class Edge{
    public:
    int source;
    int dest;
    int weight;
};

int findParent(int a, vector<int>parent){
    if(a!=parent[a]){
        parent[a] = findParent(parent[a], parent);
    }
    return parent[a];

    /*
    if(parent[a] == a){
        return a;
    }
    return findParent(parent[a], parent);
    */
}


void unionSets(int a, int b, vector<int>parent){
    a = findParent(a, parent);
    b = findParent(b, parent);
    if(a!=b){
        parent[b] = a;
    }
}



bool compare_method2(Edge e1, Edge e2){
    /*compare int a, int b
     return a<b --- here int shape
    */
    return e1.weight < e2.weight;
}

void kruskals(Edge *input, int n, int e){
    // sort the input array -- ascending order based on weights
    sort(input, input+e, compare_method2);

    Edge *output = new Edge[n-1];
    // or vector<Edge>output(n-1);

    vector<int>parent(n+1);
    for(int i=0; i<n+1; i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count!=n-1){
        /*  eg --
        int arr[9];
        int a = arr[i];
        */
        Edge currentEdge = input[i];

        // check if we can add the currentEdge in Mst or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent  = findParent(currentEdge.dest, parent);

        // if parent is diff then safe to add
        if(sourceParent!=destParent){
            output[count] = currentEdge;
            count++;
            
            // change the parent of one of the parent now
            // unionSets(sourceParent, destParent, parent);
            // or --- better way is this directly
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for(int i=0; i<n-1; i++){
        /*
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output->weight;
        }
        else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output->weight;
        cout<<endl;
        */
       cout<<min(output[i].source, output[i].dest)<<" "<<max(output[i].source, output[i].dest)<<" "<<output[i].weight;
       cout<<endl;
    }
}




// FOR METHOD 1--
bool compare_method1(vector<int>&a, vector<int>&b){
    /*compare int a, int b
     return a<b --- here int shape
    */
    return a[2]<b[2];
}


const int MAX_M = 100005;
int parent[MAX_M];


void makeset(int i){
    parent[i] = i;
}


int findSet(int v){
    if(v!=parent[v]){
        parent[v] = findSet(parent[v]);
    }
    return parent[v];
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a!=b){
        parent[b] = a;
    }
}

vector<vector<int>>helper(vector<vector<int>>&edges, int v, int e){
    int count = 0;

    // for the union function
    for(int i=0; i<=v; i++){
        makeset(i);
    }

    vector<vector<int>>ans;


    int i=0;
    while(count<v-1){
        // source
        int u = edges[i][0];
        // destination
        int v = edges[i][1];

        // ans sorted according to the weight of the edges

        int parentU = findSet(u);
        int parentV = findSet(v);

        if(parentU!=parentV){
            // change the parent
            unionSets(parentU, parentV);
            
            vector<int>temp;
            temp.push_back(edges[i][0]);
            temp.push_back(edges[i][1]);
            temp.push_back(edges[i][2]);

            ans.push_back(temp);

            // count++only if it is valid
            count++;
        }
        // cycle detected so don't count the edge and skip; don't do anything
        i++;        
    }

    return ans;
}


int main() {
    // Write your code here


    // METHOD 1----
    /*
    int v, e; cin>>v>>e;

    vector<vector<int>>edges(e, vector<int>(3));
    for(int i=0; i<e; i++){
        int source, destination, weight;
        cin>>source>>destination>>weight;
        // cout<<source<<destination<<weight<<endl;
        edges[i][0] = source;
        edges[i][1] = destination;
        edges[i][2] = weight;
    }


    // Here, a and b are iterators pointing to two different vectors within the edges vector. In simpler terms, a and b represent two different rows in the 2D vector.
    // When you use a.back() and b.back(), you're accessing the last element of each row, which is the third element in your case. So, the sort function is comparing and rearranging the rows based on their third elements, ensuring that the 2D vector is sorted according to the weights in ascending order.



    // sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
    //     return a.back() < b.back();
    // });
    // same just using our own compare function
    sort(edges.begin(), edges.end(), compare_method1);

    vector<vector<int>>ans = helper(edges, v, e);

    // for(auto it:ans){
    //     for(auto x:it) cout<<x<<" ";
    //     cout<<endl;
    // }



    // since there are v-1 edges
    for(int i=0; i<v-1; i++){
        if(ans[i][0]<ans[i][1])
            cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2];
        else
            cout<<ans[i][1]<<" "<<ans[i][0]<<" "<<ans[i][2];
        cout<<endl;
    }

    */

    // METHOD 2 --- using class

    int n,e; cin>>n>>e;
    // or Edge input[e];    
    Edge *input = new Edge[e];
    // vector<Edge>input;

    // basically instead of int/float/double type we are taking Edge type

    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, e);

    delete [] input;

    return 0;
}

