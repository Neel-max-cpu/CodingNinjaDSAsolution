/*

Classroom
Backtracking
profile picture
Problem statement
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10
0 <= MAZE[i][j] <=1

Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

Time Limit: 1 sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation for Sample Output 1:
Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

So our path matrix will look like this:

1 0 0
1 0 0
1 1 1

Which is returned from left to right and then top to bottom in one line.
Sample Input 2 :
2
1 0
0 1
Sample Output 2 :
 [Blank]
Explanation for Sample Output 2:
As no path is possible to the last cell, a blank vector will be returned and nothing is printed.


*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
using namespace std;


bool isvalid(int x, int y, vector<vector<int>>&maze, vector<vector<int>>&visited, int n){
  if((x<0 || x>=n) || (y<0 || y>=n)) return false;

  if(maze[x][y] == 0) return false;

  if(visited[x][y] == 1) return false;

  return true;
}

void helper(vector<vector<int>>&maze, int n, int row, int col, vector<vector<int>>&visited, vector<vector<int>>&ans){
  // base case
  if(row==n-1 && col==n-1){
    visited[row][col] = 1;
    vector<int>v;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        v.push_back(visited[i][j]);
      }
    }

    ans.push_back(v);
    visited[row][col] = 0;

      // for(auto it:visited){
      //   for(auto x:it) cout<<x<<" ";
      //   cout<<endl;
      // }
    return;
  }

  visited[row][col] = 1;
  
  // checking sequence
  // going up
  if(isvalid(row-1, col, maze, visited, n)){
    helper(maze, n, row-1, col, visited, ans);
  }


  // going down
  if(isvalid(row+1, col, maze, visited, n))
    helper(maze, n, row+1, col, visited, ans);


  // going left
  if(isvalid(row, col-1, maze, visited, n))
    helper(maze, n, row, col-1, visited, ans);



  // goind right
  if(isvalid(row, col+1, maze, visited, n))
    helper(maze, n, row, col+1, visited, ans);

  visited[row][col] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  
  vector<vector<int>>ans;
  vector<vector<int>>visited(n, vector<int>(n,0));
  if(n==1) {
    vector<int>v;
    v.push_back(1);
    ans.push_back(v);
    return ans;
  }
  
  helper(maze, n, 0 ,0, visited, ans );
  // for(auto it:ans){
  //   for(auto x:it) cout<<x<<" ";
  //   cout<<endl;
  // }
  return ans;

}

int main()
{

  int n;
  cin >> n;
  vector<vector<int>> maze(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> maze[i][j];
    }
  }
  
  vector<vector<int>> ans = ratInAMaze(maze, n);

  // sort(ans.begin(),ans.end());

  int s = ans.size();
  for (int i = 0; i < s; i++)
  {
    int t = ans[i].size();
    for (int j = 0; j < t; j++)
    {
      cout << ans[i][j] << " ";
    }

    cout << endl;
  }
}