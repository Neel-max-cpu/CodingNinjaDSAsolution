/*
Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
You are given a reference/address of a node in a connected undirected graph containing N nodes and M edges. You are supposed to return a clone of the given graph which is nothing but a deep copy. Each node in the graph contains an integer “data” and an array/list of its neighbours.

The structure of the graphNode class is as follows:

class graphNode 
{  
    public:
        int data;
        vector<graphNode*> neighbours;
}
Note :
1. Nodes are numbered from 1 to N.

2. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
2 <= N <= 100000
1 <= M <= min(N(N-1)/2,100000)
1 <= E[i][0], E[i][1] <= N

Where  ‘N’ is the number of nodes in the given graph, ‘M’ denotes the number of edges and ‘E’ denotes the edge matrix.

Time Limit: 1 sec.
Sample Input 1 :
2
5
6
1 2
4 1
2 4
3 4
5 2
1 3
3
2
1 2
1 3
Sample Output 1 :
true
true
Explanation of Input 1 :
In the first test case, the returned graph contains 5 nodes and 6 edges which are:
1 2
4 1
2 4
3 4
5 2
1 3
Since it is similar to the given graph with different address nodes then the solution is correct.

In the second test case, the returned graph contains 3 nodes and 2 edges which are:
1 2
1 3
Since it is similar to the given graph with different address nodes then the solution is correct.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2
Sample Output 2 :
true
true
Explanation of Input 2 :
In the first test case, the returned graph contains 5 nodes and 4 edges which are:
1 2
2 3
3 4
4 5
Since it is similar to the given graph with different address nodes then the solution is correct.

In the second test case, the returned graph contains 2 nodes and 1 edge which is:
1 2

Since it is similar to the given graph with different address nodes then the solution is correct.
#include <bits/stdc++.h> 
#include <vector>
using namespace std;
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <fstream>
#include<algorithm>

using namespace std;

class graphNode
{
public:
    int data;
    vector<graphNode *> neighbours;
    graphNode()
    {
        data = 0;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val)
    {
        data = val;
        neighbours = vector<graphNode *>();
    }

    graphNode(int val, vector<graphNode *> neighbours)
    {
        data = val;
        this->neighbours = neighbours;
    }

    ~graphNode()
    {
        neighbours.clear();
    }
};

#include <bits/stdc++.h> 
#include <vector>
using namespace std;
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
// https://www.youtube.com/watch?v=f2EfGComRKM ----- tutorial
void dfs(graphNode *curr, graphNode *node, vector<graphNode*>&visited){
	visited[node->data] = node;
	for(auto ele:curr->neighbours){
		if(visited[ele->data] == NULL){
			graphNode *newNode = new graphNode(ele->data);
			(node->neighbours).push_back(newNode);
			dfs(ele, newNode, visited);
		}
		else 
			(node->neighbours).push_back(visited[ele->data]);
	}
}



graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.

	if(node == NULL) return NULL;
	vector<graphNode*>visited(100000, NULL);
	graphNode* copy = new graphNode(node->data);
	visited[node->data] = copy;

	// iterate all the neighbours
	for(auto curr: node->neighbours){
		if(visited[curr->data] == NULL){
			graphNode *newNode = new graphNode(curr->data);
			(copy->neighbours).push_back(newNode);
			dfs(curr, newNode, visited);
		}
		else 
			(copy->neighbours).push_back(visited[curr->data]);
	}
	return copy;

	
}

bool comp(graphNode* a, graphNode* b)
{
    return a->data<b->data;
}

class Runner
{
    int t;
    vector<graphNode *> graphs;

public:
    bool bfsCheckAnswer(graphNode *ans, graphNode *src)
    {
        map<graphNode *, bool> visit, visitAns;
        queue<graphNode *> q, qans;
        q.push(src);
        qans.push(ans);
        visit[src] = true;
        visitAns[ans] = true;
        while (!q.empty())
        {
            graphNode *u = q.front();
            graphNode *p = qans.front();
            if (u->data != p->data)
            {
                return false;
            }
            if (u == p)
            {
                return false;
            }
            q.pop();
            qans.pop();
            vector<graphNode *> v = u->neighbours;
            vector<graphNode *> vAns = p->neighbours;

            if (v.size() != vAns.size())
            {
                return false;
            }

            int n = v.size();

            sort(v.begin(), v.end(),comp);
            sort(vAns.begin(), vAns.end(),comp);
            
            
            for (int i = 0; i < n; i++)
            {
                 if (v[i]->data != vAns[i]->data)
                {
                    return false;
                }
                if (!visit[v[i]])
                {
                    visit[v[i]] = true;
                    q.push(v[i]);
                }

                if (!visitAns[vAns[i]])
                {
                    visitAns[vAns[i]] = true;
                    qans.push(vAns[i]);
                }
            }
        }
        return true;
    }

    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n;
            graphNode *head;
            int m;
            cin >> m;

            map<int, graphNode *> check;

            for (int i = 0; i < m; i++)
            {
                int x, y;
                cin >> x >> y;
                if (x == y)
                {
                    continue;
                }
                if (!check[x])
                {
                    graphNode *temp = new graphNode();
                    head = temp;
                    temp->data = x;
                    check[x] = temp;
                }
                if (!check[y])
                {
                    graphNode *temp = new graphNode();
                    temp->data = y;
                    check[y] = temp;
                }

                vector<graphNode *> n1 = check[x]->neighbours;
                if (find(n1.begin(), n1.end(), check[y]) == n1.end())
                {
                    check[x]->neighbours.push_back(check[y]);
                }

                vector<graphNode *> n2 = check[y]->neighbours;
                if (find(n2.begin(), n2.end(), check[x]) == n2.end())
                {
                    check[y]->neighbours.push_back(check[x]);
                }
            }
            graphs.push_back(head);
        }
    }

    graphNode *copyGraphHelper(graphNode *node, unordered_map<graphNode *, graphNode *> &copies)
    {
        if (node == NULL)
        {
            return NULL;
        }

        graphNode *copy = new graphNode(node->data);
        copies[node] = copy;
        queue<graphNode *> level;
        level.push(node);

        while (!level.empty())
        {
            graphNode *cur = level.front();
            level.pop();
            for (graphNode *neighbor : cur->neighbours)
            {
                if (copies.find(neighbor) == copies.end())
                {
                    copies[neighbor] = new graphNode(neighbor->data, {});
                    level.push(neighbor);
                }
                copies[cur]->neighbours.push_back(copies[neighbor]);
            }
        }
        return copy;
    }

    graphNode *copyGraph(graphNode *node)
    {
        unordered_map<graphNode *, graphNode *> copies;
        return copyGraphHelper(node, copies);
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            graphNode *copy = copyGraph(graphs[i]);

            graphNode *ans = cloneGraph(copy);

            delete copy;
            delete ans;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            graphNode *copy = copyGraph(graphs[i]);

            graphNode *ans = cloneGraph(copy);

            if (bfsCheckAnswer(ans, graphs[i]))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }

            delete ans;
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}