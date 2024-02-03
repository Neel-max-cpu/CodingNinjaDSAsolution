/*

Classroom
DP - 2
profile picture
Problem statement
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Detailed explanation ( Input/output format, Notes, Images )
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
#include<vector>
#include<algorithm>
using namespace std;


int helper_rec(int **arr, int i, int j){
	// base case
	if(i<0 || j<0) return 0;

	// conditions


*/


#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>
using namespace std;


int helper_rec(int **arr, int i, int j){
	// base case
	if(i<0 || j<0) return 0;

	// conditions
	if (arr[i][j] == 0) {
        // If the current cell is 0, find the size of the square submatrix
        // formed by considering the cells diagonally, above, and to the left
        int sizeDiagonal = helper_rec(arr, i - 1, j - 1);
        int sizeAbove = helper_rec(arr, i - 1, j);
        int sizeLeft = helper_rec(arr, i, j - 1);

        // The size of the square submatrix at the current cell is
        // 1 + minimum of the sizes of the above three submatrices
        int currentSize = 1 + min(sizeDiagonal, min(sizeAbove, sizeLeft));

        return currentSize;
    }
	return 0;
}

int helper_mem(int **arr, int i, int j, vector<vector<int>>&dp){

	// base case
	if(i<0 || j<0){
		return 0;
	}

	// check 
	if(dp[i][j]!=-1) return dp[i][j];

	// conditions
	if(arr[i][j]==1) return dp[i][j] = 0;

	// diagonally left 
	int a = helper_mem(arr, i-1, j-1, dp);
	// directly above
	int b = helper_mem(arr, i-1, j, dp);
	// directly left
	int c = helper_mem(arr, i, j-1, dp);

	int put = min(a,min(b,c));
	dp[i][j] = put+1;
	return dp[i][j];

}

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here

	// index ij would represent largest sq that would end at an index
	/*
	eg  
	3x3
	0 0 0
	0 0 1
	1 0 0 

	dp-- base case since single element(0 = 1 and 1=then 0)
	1 1 1
	1 0 0
	0 0 0

	now, after solving
	1 1 1
	1 2 0
	0 1 1
	max = 2
	*/

	// recursion approach ---
	/*
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ans = max(ans, helper_rec(arr, i, j));
		}
	}
	return ans;
	*/


	// dp memoization ---
	/*
	vector<vector<int>>dp(n, vector<int>(m,-1));
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ans = max(ans, helper_mem(arr, i, j, dp ));
		}
	}
	return ans;
	*/

	// dp tabulation ---
	// /*
	vector<vector<int>>dp(n, vector<int>(m,0));

	// base cases fill the 0th row
	for(int j=0; j<m; j++){
		// if 0 then 1 if 1 then 0
		if(arr[0][j]==0){
			dp[0][j] = 1;
		}
		else
			dp[0][j] = 0;
	}

	// fill the 0th column
	for(int i=1; i<n; i++){
		if(arr[i][0]==0){
			dp[i][0] = 1;
		}
		else
			dp[i][0] = 0;
	}

	int ans = 0;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(arr[i][j]==1){
				dp[i][j] = 0;
			}
			else{
				// if directly above/directly left, and diagonal left is same ans then +1 with them

				// left diagonally
				int a = dp[i-1][j-1];
				// directly above
				int b = dp[i-1][j];
				// directly left
				int c = dp[i][j-1];
				
				int put = min(a,min(b,c)) + 1;
				
				dp[i][j] = put;
				ans = max(ans, dp[i][j]);
			}			
		}
	}

	// for(auto it:dp){
	// 	for(auto x:it) cout<<x<<" ";
	// 	cout<<"new row here"<<endl;
	// }
	// cout<<"new"<<endl;

	return ans;
	// */
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}