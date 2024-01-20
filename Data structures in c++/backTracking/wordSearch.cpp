/*



Problem statement
You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.



Your task is to return true if the given word exists in the grid, else return false. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.



Note:
The same letter cell should not be used more than once.
For Example:
For a given word “design” and the given 2D board 
[[q’, ‘v’, ‘m’, ‘h’],
 [‘d’, ‘e’, ‘s’, ‘i’],
 [‘d’, ‘g’, ‘f’, ‘g’],
 [‘e’, ‘c’, ‘p’, ‘n’]]

The word design can be formed by sequentially adjacent cells as shown by the highlighted color in the 2nd row and last column.
board

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
coding
4 4
c z k l
o d i a
r g n m
m r s d
Sample Output 1:
true
Explanation For Sample Input 1:
For the given word, and grid we can construct from letters of sequentially adjacent cells as shown below:
board

Sample Input 2:
ninjas
4 4
c d k s
o d s i
d g n j
e r i n
Sample Output 2:
false
Constraints:
1 <= N <= 6
1 <= M <= 6
1 <= |word| <=20

Time Limit: 1 sec




*/










#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool f = false;

bool isValid(vector<vector<char>>&board, int n, int m, vector<vector<int>>visited, int x, int y, char c){
    // boundary
    if((x<0 || x>=n) || (y<0 || y>=m)) return false;

    // if visited or not
    if(visited[x][y]==1) return false;

    // if next word is present
    if(board[x][y]!=c) return false;

    return true;
}

void helper(vector<vector<char>> &board, string &word, int n, int m, vector<vector<int>>visited, int x, int y, int index){
    // base case
    if(index==word.size()-1){
        f = true;
        return;
    }

    visited[x][y] = 1;
    // pick the element
    // up
    if(isValid(board, n, m, visited, x-1, y, word[index+1])){
        helper(board, word, n, m, visited, x-1, y, index+1);
    }

    // down
    if(isValid(board, n, m, visited, x+1, y, word[index+1])){
        helper(board, word, n, m, visited, x+1, y, index+1);
    }

    // left
    if(isValid(board, n, m, visited, x, y-1, word[index+1])){
        helper(board, word, n, m, visited, x, y-1, index+1);
    }

    // right
    if(isValid(board, n, m, visited, x, y+1, word[index+1])){
        helper(board, word, n, m, visited, x, y+1, index+1);
    }

    visited[x][y] = 0;
    return;
} 


bool helper2(vector<vector<char>> &board, string &word, int n, int m, int x, int y, int index) {
    // base case
    if(index == word.size()-1) return true;

    if((x<0 || x>=n) || (y<0 || y>=m) || board[x][y] == '#' || board[x][y] != word[index]) return false;
    else{
        char temp = board[x][y];
        // means visited
        board[x][y] = '#';
        // up
        bool one = helper2(board, word, n, m, x-1, y, index+1);
        // down
        bool two = helper2(board, word, n, m, x+1, y, index+1);
        // left
        bool three = helper2(board, word, n, m, x, y-1, index+1);
        // right
        bool four = helper2(board, word, n, m, x, y+1, index+1);
        board[x][y] = temp;
        return (one||two||three||four);
    }
}


bool present(vector<vector<char>> &board, string &word, int n, int m) 
{
    // Write your code here.

    // METHOD 1 ---
    /*
    vector<vector<int>>visited(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                helper(board, word, n, m, visited, i, j, 0);
                if(f==true) return true;
            }
        }
    }
    if(f==false)
        return false;
    */

    // METHOD 2 ---

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                if(helper2(board, word, n, m, i, j, 0)) return true;
            }
        }
    }
    return false;

}

class Runner
{
    string s;
    int n,m;
    vector<vector<char>> mat;

public:
    
    void takeInput()
    {
        cin >> s >> n >> m;
        mat = vector<vector<char>> (n,vector<char> (m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin >> mat[i][j];
    }
    void execute()
    {
        // make copy if vector
        auto cmat = mat;
        present(cmat,s,n,m);
    }
    void executeAndPrintOutput()
    {
        auto cmat = mat;
        if(present(cmat,s,n,m))cout << "true";
        else cout << "false";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}