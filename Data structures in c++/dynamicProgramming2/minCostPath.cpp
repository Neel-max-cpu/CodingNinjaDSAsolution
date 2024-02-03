/*

Problem statement
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;


bool isValid(int i, int j, int m, int n){
	// should be inside boundary
	if(i<m && j<n) return true;

*/


#include <bits/stdc++.h>
using namespace std;


#include <algorithm>
#include <climits>
#include <vector>
using namespace std;


bool isValid(int i, int j, int m, int n){
	// should be inside boundary
	if(i<m && j<n) return true;
	return false;
}

int helper(int **input, int m, int n, int i, int j){
	// base case
	if(i==m-1 && j==n-1){
		return input[i][j];
	}

	// three cases
	int x = INT_MAX, y = INT_MAX, z= INT_MAX;

	// go down
	if(isValid(i+1,j, m, n)){
		x = helper(input, m, n, i+1, j);
	}

	// go right
	if(isValid(i,j+1, m, n)){
		y = helper(input, m, n, i, j+1);
	}
	
	if(isValid(i+1,j+1, m, n)){
		z= helper(input, m, n, i+1, j+1);
	}

	int ans = min(x, min(y,z));
	// cout<<ans<<endl;
	return input[i][j]+ans;
}


int helper2(int **input, int m, int n, int i, int j, vector<vector<int>>&dp){

	// base case
	if(i==m-1 && j==n-1){
		return input[i][j];
	}

	// check
	if(dp[i][j]!=-1) return dp[i][j];

	// three cases
	int x = INT_MAX, y = INT_MAX, z= INT_MAX;
	// go down
	if(isValid(i+1,j, m, n)){
		x = helper(input, m, n, i+1, j);
	}

	// go right
	if(isValid(i,j+1, m, n)){
		y = helper(input, m, n, i, j+1);
	}
	
	if(isValid(i+1,j+1, m, n)){
		z= helper(input, m, n, i+1, j+1);
	}

	int ans = min(x, min(y,z));
	
	dp[i][j] = input[i][j]+ans;
	return dp[i][j];

}


int minCostPath(int **input, int m, int n)
{
	//Write your code here
	
	// METHOD 1 -- recursion
	/*
	int ans = helper(input, m, n, 0, 0);
	return ans;
	*/

	// METHOD 2 -- DP memoization
	/*
	vector<vector<int>>dp(m, vector<int>(n,-1));
	int ans = helper2(input, m, n, 0, 0, dp);
	return ans;
	*/


	// METHOD 3 -- DP tabulation here we should fill in top down manner
	vector<vector<int>>dp(m, vector<int>(n,-1));

	// fill the last cell
	dp[m-1][n-1] = input[m-1][n-1];

	// fill the last row(right to left manner)
	for(int i=n-2; i>=0; i--){
		//next dp value + input value
		dp[m-1][i] = input[m-1][i]+dp[m-1][i+1];
	}

	// fill the last column(down to up)
	for(int i=m-2; i>=0; i--){
		// next dp value + input value 
		dp[i][n-1] = input[i][n-1] + dp[i+1][n-1];
	}

	// fill the remainig cell
	for(int i=m-2; i>=0; i--){
		for(int j=n-2; j>=0; j--){
			// now from here all the cells have three
			// min of right , diagonal and down and + current cost(input)
			dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], dp[i+1][j])) + input[i][j];
		}
	}

	return dp[0][0];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}