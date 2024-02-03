/*

Classroom
DP - 2
profile picture
Problem statement
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
#include<vector>
#include<algorithm>
using namespace std;

int helper_rec(int *arr, int ind){
	// base case
	if(ind<0){
		return 0;
	}



*/


#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>
using namespace std;

int helper_rec(int *arr, int ind){
	// base case
	if(ind<0){
		return 0;
	}

	// pick 
	int a = arr[ind] + helper_rec(arr, ind-2);


	// not pick
	int b = 0+helper_rec(arr, ind-1);

	return max(a,b);
}

int helper_mem(int *arr, int ind, vector<int>&dp){
	// base case
	if(ind<0){
		return 0;
	}

	// check
	if(dp[ind]!=-1) return dp[ind];


	// pick 
	int a = arr[ind] + helper_mem(arr, ind-2, dp);


	// not pick
	int b = 0+helper_mem(arr, ind-1, dp);

	int ans = max(a,b);

	dp[ind] = ans;
	return ans;
}



int maxMoneyLooted(int *arr, int n)
{
	//Write your code here

	// recursion ---
	// return helper_rec(arr, n-1);


	// memoization ---
	/*
	vector<int>dp(n+1, -1);
	return helper_mem(arr, n-1, dp);
	*/

	// tabulation ---
	if(n==0) return 0; 
	vector<int>dp(n, 0);

	// base case
	dp[0] = arr[0];
	// and
	if(n>1)
		dp[1] = max(arr[0], arr[1]);

	for(int i=2; i<n; i++){
		// pick 
		int a = dp[i-2]+arr[i];

		// not pick
		int b = dp[i-1];

		int ans = max(a,b);
		dp[i] = ans;
	}

	// for(auto it:dp) cout<<it<<" "<<endl;

	return dp[n-1];
	
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}