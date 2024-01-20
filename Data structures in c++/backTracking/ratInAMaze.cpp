/*


You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).

Note:
Here, sorted paths mean that the expected output should be in alphabetical order.
For Example:
Given a square matrix of size 4*4 (i.e. here 'N' = 4):
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1 
Expected Output:
DDRDRR DRDDRR 
i.e. Path-1: DDRDRR and Path-2: DRDDRR

The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
2 <= N <= 5
0 <= MATRIX[i][j] <= 1

Where N is the size of the square matrix.

Time Limit: 1sec
Sample Input 1:
4
1 0 0 0 
1 1 0 1
1 1 0 0
0 1 1 1
Sample Output 1:
DDRDRR DRDDRR
Explanation For Sample Input 1:
The rat can reach the destination at (3, 3) from (0, 0) by two paths, i.e. DRDDRR and DDRDRR when printed in sorted order, we get DDRDRR DRDDRR.
Sample Input 2:
2
1 0
1 0
Sample Output 2:
[]
Explanation For Sample Input 2:




*/






#include <iostream>
#include <vector>

using namespace std;

#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) {
  
  if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && arr[newx][newy] == 1) {
    return true;
  } 
  else {
    return false;
  }
}
void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path) {
  
  //      BASE CASE
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  // marking it visited
  vis[x][y] = 1;
  //      NOW WE WILL HAVE 4 MOVEMENTS  ( DOWN , LEFT , RIGHT , UP )

  //     DOWN CASE
  if (isSafe(x + 1, y, vis, arr, n)) {
    solve(x + 1, y, arr, n, ans, vis, path + 'D');
  }

  //      LEFT CASE
  if (isSafe(x, y - 1, vis, arr, n)) {
    solve(x, y - 1, arr, n, ans, vis, path + 'L');
  }

  //      RIGHT CASE
  if (isSafe(x, y + 1, vis, arr, n)) {
    solve(x, y + 1, arr, n, ans, vis, path + 'R');
  }
  //      UP CASE
  if (isSafe(x - 1, y, vis, arr, n)) {
    solve(x - 1, y, arr, n, ans, vis, path + 'U');
  }
  vis[x][y] = 0;
}

bool isvalid(int x, int y, vector<vector<int>> &arr, vector<vector<int>> &v) {
  // x is out of bounds
  if (x < 0 || x >= arr.size())
    return false;

  // y is out of bounds
  
  if (y < 0 || y >= arr.size())
    return false;

  // cell is not accessible
  if (arr[x][y] == 0)
    return false;

  // if already visited
  if (v[x][y] == 1)
    return false;
  
  return true;

  // if((x>=0 and x<=arr.size()-1) and (y>=0 and y<=arr.size()-1) and (arr[x][y]==1) and (v[x][y]==0))
  //   return true;
  // else return false;
}

vector<string> helper(vector<vector<int>> &arr, int n, vector<vector<int>> &v, int x, int y, string path) {

//  cout << "Current Position: (" << x << ", " << y << "), Path: " << path << endl;


  // base case
  if (x == n - 1 && y == n - 1) {
    vector<string>ans;
    ans.push_back(path);
    // v[x][y] = 0;
    return ans;
  }

  // marking it visited
  v[x][y] = 1;
  
  vector<string> s;
  
  // pick the place
  // up
  if (isvalid(x - 1, y, arr, v)) {
    vector<string> s3;
    s3 = helper(arr, n, v, x - 1, y, path+'U');
    s.insert(s.end(), s3.begin(), s3.end());
  }

  // down
  if (isvalid(x + 1, y, arr, v)) {
    vector<string> s4;
    s4 = helper(arr, n, v, x + 1, y, path+'D');
    s.insert(s.end(), s4.begin(), s4.end());
  }

  // left
  if (isvalid(x, y - 1, arr, v)) {
    vector<string> s1;
    s1 = helper(arr, n, v, x, y - 1, path+'L');
    s.insert(s.end(), s1.begin(), s1.end());
  }

  // right
  if (isvalid(x, y + 1, arr, v)) {
    vector<string> s2;
    s2 = helper(arr, n, v, x, y + 1, path+'R');
    s.insert(s.end(), s2.begin(), s2.end());
  }

  v[x][y] = 0;

  return s;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  // METHOD 1 ---
  // /*
   vector <string> ans ;
   vector <vector <bool> > visited (n , vector<bool> (n,0)) ;
   string path = "" ;
   if (arr[0][0] == 0)
       return ans ;

   solve (0 , 0 , arr , n , ans , visited , path) ;
   return ans ;
  //  */

  //  METHOD 2 --- MY
  // vector<vector<int>> v(n, vector<int>(n, 0));

  // vector<string> s = helper(arr, n, v, 0, 0, "");
  // return s;
}

class Runner {
    int t;
    vector<vector<int>> arr;

public:
    void takeInput() {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            arr.push_back(vector<int>());
            for(int j=0;j<n;j++)
            {
                int x;
                cin>>x;
                arr[i].push_back(x);
            }
        }
    }

    void execute() {
        vector<vector<int> > arrCopy = arr;

        vector<string> ans= searchMaze(arrCopy, arrCopy.size());
    }

    void executeAndPrintOutput() {
        vector<string> ans = searchMaze(arr,arr.size());
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
};

int main() {

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}