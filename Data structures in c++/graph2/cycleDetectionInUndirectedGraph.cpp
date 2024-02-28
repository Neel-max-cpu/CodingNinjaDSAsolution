/*

Classroom
Lecture 21 : Graphs 2
profile picture
Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3. 
Example

Note:

1. There are no parallel edges between two vertices.

2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

3. The graph can be disconnected.
For Example :

Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
Output: Yes

Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 5000
0 <= M <= min(5000, (N * (N - 1)) / 2)
1 <= edges[i][0] <= N 
1 <= edges[i][1] <= N 

Time Limit: 1 sec 
Sample Input 1:
1
3 2
1 2
2 3
Sample output 1:
No
Explanation of Sample output 1:
 The above graph can be represented as 
Example

There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
Sample Input 2:
2
4 0 
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX_N = 5000;
const int MAX_M = 5000;
int parent[MAX_N + 1];


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX_N = 5000;
const int MAX_M = 5000;
int parent[MAX_N + 1];


void makeSet(int v){
    // make the default parent of each edge = themselves
    parent[v] = v;
}

int findSet(int v){
    if (v != parent[v])
        parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSets(int a, int b){
    // make the parent of b = a
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

bool containsCycle(int n, int edges[][2], int m){
    for (int i = 1; i <= n; i++){
        makeSet(i);
    }

    for (int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int parentU = findSet(u);
        int parentV = findSet(v);
        if (parentU == parentV)
                return true;
        // instead of union we can directly put
        // unionSets(parentU, parentV);
        parent[parentU] = parentV;
    }
    return false;
}

int main()
{
    //Write your code here
    int t;cin>>t;
    while(t--){

        // METHDO 1---- mine
        /*
        int n,m; cin>>n>>m;
        vector<int>parents(n+1);
        for(int i=0; i<n+1; i++){
            // by default
            parents[i] = i;
        }

        bool flag = false;

        for(int i=0; i<m; i++){
            int f, s; cin>>f>>s;
            if(parents[f] == parents[s]){
                // cycle found
                flag = true;
            }
            else{
                if(parents[f] > parents[s]){
                    int temp = parents[f];
                    parents[f] = parents[s];
                    for(int i=0; i<n+1; i++){
                        if(parents[i]==temp){
                            parents[i] = parents[s];
                        }
                    }
                }
                // parents[f] < parents[s]
                else{
                    int temp = parents[s];
                    parents[s] = parents[f];
                    for(int i=0; i<n+1; i++){
                        if(parents[i]==temp){
                            parents[i] = parents[f];
                        }
                    }
                }
            }
        }

        if(flag == true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        */

        // METHDO 2 ---
        int n, m;
        cin >> n >> m;

        int edges[MAX_M][2];
        for (int i = 0; i < m; i++)
                cin >> edges[i][0] >> edges[i][1];
                
        bool result = containsCycle(n, edges, m);
        /*
        if little bit confuse -- then dry run with this eg--
        n = 7, m=7
        2 6 
        2 3
        2 4
        1 5
        5 7
        6 7
        3 7
        answer will be Yes, since at 3 7 both parents will be same

        */

        if(result)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}