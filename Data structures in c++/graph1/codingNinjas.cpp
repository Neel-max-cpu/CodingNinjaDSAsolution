/*

Classroom
Lecture 20 : Graphs 1
profile picture
Problem statement
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string s = "CODINGNINJA";

int N,M;

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

string s = "CODINGNINJA";

int N,M;
vector<vector<char>>Edges(1000, vector<char>(1000));

bool can(vector<vector<char>>&edges, int i, int j, int current, int n, int m, vector<vector<bool>>&visited){
    if(current == s.size()) return true;
    else{
        if(i>=n || j>=m || i<0 || j<0 || edges[i][j]=='X' || visited[i][j] == true) return false;
        if(edges[i][j]!=s[current]) return false;
        return true;
    }
}


// bool check(int i, int j, vector<vector<char>>&edges, vector<bool>&visited, int current){
bool check(int i, int j, vector<vector<char>>&edges, int current, int n, int m, vector<vector<bool>>&visited){

    // base case
    if(current==s.size()) return true;

    // i can go in 8 directions
    // up 
    bool flag = false;
    visited[i][j]=true;
    if(can(edges, i-1, j, current+1, n, m, visited)){
        flag = check(i-1, j, edges, current+1, n, m, visited) || flag;
    }

    // down
    if(can(edges, i+1, j, current+1, n, m, visited)){
        flag = check(i+1, j, edges, current+1, n, m, visited) || flag;
    }

    // left 
    if(can(edges, i, j-1, current+1, n, m, visited)){
        flag = check(i, j-1, edges, current+1, n, m, visited) || flag;
    }

    // right
    if(can(edges, i, j+1, current+1, n, m, visited)){
        flag = check(i, j+1, edges, current+1, n, m, visited) || flag;
    }

    // up left diagonal
    if(can(edges, i-1, j-1, current+1, n, m, visited)){
        flag = check(i-1, j-1, edges, current+1, n, m, visited) || flag;
    }

    // up right diagonal
    if(can(edges, i-1, j+1, current+1, n, m, visited)){
        flag = check(i-1, j+1, edges, current+1, n, m, visited) || flag;
    }

    // down left diagonal
    if(can(edges, i+1, j-1, current+1, n, m, visited)){
        flag = check(i+1, j-1, edges, current+1, n, m, visited) || flag;
    }

    // down right diagonal
    if(can(edges, i+1, j+1, current+1, n, m, visited)){
        flag = check(i+1, j+1, edges, current+1, n, m, visited) || flag;
    }
    visited[i][j]=false;

    return flag;

}

void solve(vector<vector<char>>&edges, int n, int m){
     vector<vector<bool>>visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(edges[i][j] == 'C'){
                // visited<bool>visited(26, false);             
                // if(check(i,j, edges, visited, 0)){
                if(check(i,j, edges, 0, n, m, visited)){
                    cout<<1<<endl;
                    return;
                }
            }
        }
    }
    cout<<0<<endl;
    return;
}

bool isValid(int x, int y, int start){
    return (x>=0 && x<N && y>=0 && y<M && Edges[x][y]==s[start]);
}

bool searchWord(int x, int y, int start){
    if(start == s.size()-1) return true;

    char temp = Edges[x][y];
    Edges[x][y] = '#';
    //(0)-diagonally_up_left, (1)-up, (2)-diagonally_up_right, (3)-left, 
    //(4)-right, (5)-diagonally_down_left, (6)-down, (7)-diagonally_down_right
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(isValid(nx, ny, start+1)){
            if(searchWord(nx, ny, start+1))
                return true;
        }
    }

    Edges[x][y] = temp;
    return false;
}


bool isWordPresent(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            if(Edges[i][j]=='C'){
                if(searchWord(i,j,0)) return true;
            }
        }
    }
    return false;
}

int main()
{
    //Write your code here

    // METHDO 1--- MINE
    /*
    int n, m; cin>>n>>m;
    vector<vector<char>>edges(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin>>edges[i][j];
        }
    }

    solve(edges, n, m);
    */

    // METHOD 2 
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin>>Edges[i][j];
    }


    bool res = isWordPresent();
    if(res) cout<<1<<endl;
    else cout<<0<<endl;

}