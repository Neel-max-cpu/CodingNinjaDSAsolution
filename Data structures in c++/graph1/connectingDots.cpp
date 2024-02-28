/*
Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<vector<char>>edges(1000, vector<char>(1000));




*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<vector<char>>edges(1000, vector<char>(1000));



bool helper(int x, int y, int preX, int preY,  char color, vector<vector<bool>>&visited){

    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(edges[x][y] != color) return false;

    // if its true then we have reach the cycle
    // see here we are not back tracking
    if(visited[x][y]) return true;


    visited[x][y] = true;
    int dx[] = {0, 0 , -1, 1};
    int dy[] = {-1, 1, 0 , 0};

    for(int i=0; i<4; i++){
        int nextX = x+dx[i];
        int nextY = y+dy[i];

        if(nextX == preX && nextY == preY) continue;

        // if(isValid(nextX, nextY, color, visited)){
        if(helper(nextX, nextY, x, y, color, visited)) return true;
        // }
    }
    return false;
}

bool hasCycle(){
    vector<vector<bool>>visited(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                if(helper(i, j, -1, -1, edges[i][j], visited)) return true;
            }
        }
    }
    return false;
}

int main()
{
    //Write your code here

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>edges[i][j];
    }

    bool res = hasCycle();
    if(res) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}