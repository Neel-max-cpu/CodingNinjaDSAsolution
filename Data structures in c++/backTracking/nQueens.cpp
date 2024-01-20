/*


Problem statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'N' <= 10

Time Limit: 1sec


For Example:
For a chessboard of size 4*4
The configurations are 
alt text

Sample Input 1:
4
Sample Output 1:
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
Sample Input 2:
3
Sample Output2:
      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty.



void print(vector<vector<int> >& board,vector<vector<int> >&ans,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           temp.push_back(board[i][j]);
        }
    }



*/


#include <iostream>
#include <vector>
using namespace std;



void print(vector<vector<int> >& board,vector<vector<int> >&ans,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int> >& board,int n){
    int x=row,y=col;

    // directly left ------
    while(y>=0){
        if(board[x][y]==1){
            return false;
        }
        y--;
   }
    
    // upper left diagonal ----
    x=row,y=col;
    while(x>=0 and y>=0){
         if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    // upper right diagonal
    x=row,y=col;
    while(x<n and y>=0){
         if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }
    return true;
}
void solve(int col,vector<vector<int> >& board,vector<vector<int> >&ans,int n){
    if(col>=n){
        // HERE pushing back the elements in the ans vector
        print(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,board,ans,n);
            board[row][col]=0;
        }
    }
}

// -------------------------------------------------- METHOD 1
bool isValid_method1(int x, int y, int n, vector<vector<int>>&visited){

    // checking directly above and below(though below is not needed), i.e the column stats const 
    for(int i = 0; i<n; i++){
        // up
        if(visited[i][y]==1) return false;
    }

    // upper left diagonal
    for(int i=x, j=y; i>=0 and j>=0 ; i--,j--){
        if(visited[i][j]==1) return false;
    }

    // upper right diagonal
    for(int i=x, j=y; i>=0 and j<n; i--,j++){
        if(visited[i][j]==1) return false;
    }

    return true;
}


// PASSED BY REFERENCE ans vector and visited vector
void helper(int row, int n, vector<vector<int>>&visited, vector<vector<int>>&ans){

    // base case
    if(row==n){
        // cout<<"new one here"<<endl;
        vector<int>v;
        for(auto it:visited){
            // for(auto x:it) cout<<x<<" ";
            for(auto x:it) v.push_back(x);
            // cout<<endl;
        }

        // ans.push_back(visited[row - 1]);
        ans.push_back(v);
        // cout<<"answer"<<endl;
        // for(auto it:ans){
        //     for(auto x:it) cout<<x<<" ";
        //     cout<<endl;
        // }
        return;
    }


    for(int i=0; i<n ;i++){
        if(isValid_method1(row, i, n, visited)){
            // board[row][i] = 'q';
            visited[row][i] = 1;
            helper(row+1, n, visited, ans);
            visited[row][i] = 0;
        }
    }
}






vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    
    // METHOD 2 --- USING COLUMN WISE, we are passing column and iterating row wise
    /*
    vector<vector<int> >board(n,vector<int>(n,0));
    vector<vector<int> >ans;
    solve(0,board,ans,n);
    return ans;
    */

    // METHOD 1 --- using row wise, we are passing row, and checking column wise
    vector<vector<int>>visited(n, vector<int>(n,0));
        
    int row = 0;
    vector<vector<int>>ans;
    // helper(row, n, visited, ans, board);

    // important step pass by REFERENCE ---
    helper(row, n, visited, ans);

    // checking the ans

    // for(auto it:ans){
    //     for(auto x:it) cout<<x<<" ";
    //     cout<<endl;
    // }
    return ans;

    /*
    ONLY difference bettween the two method is in the isSafe/isvalid_method1 function
    only the first case, in row wise we are checking whether directly above(and below though not needed) there is queen or not
    in column wise we are seeing if directly left side there is queen or not
    */
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> answer;
    answer = solveNQueens(n);

    for (auto sol : answer) {
        for (auto i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}