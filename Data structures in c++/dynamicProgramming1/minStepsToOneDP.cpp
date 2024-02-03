/*


Problem statement
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int res  = 1e9;


int helper(vector<int>&dp, int n){
	// base case



*/




#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int res  = 1e9;


int helper(vector<int>&dp, int n){
	// base case
	if(n==1){
		return 0;
	}


	if(dp[n]!=-1) return dp[n];

	int x = helper(dp,n-1);


	int y=INT_MAX, z = INT_MAX;
	if(n%2==0){
		y = helper(dp, n/2);
	}

	
	if(n%3==0){
		z = helper(dp,n/3);
	}

	dp[n] =  1 + min(x, min(y,z));
	return dp[n];
}


int countStepsToOne(int n)
{
	//Write your code here

	// RECURSIVE CODE ----

	// METOHD 1-- my
	/*
	helper(n,0);
	return res;
	*/


	// METHOD 2 ---
	/*
	if(n==1){
		return 0;
	}

	int x = countStepsToOne(n-1);


	int y=INT_MAX, z = INT_MAX;
	if(n%2==0){
		y = countStepsToOne(n/2);
	}

	
	if(n%3==0){
		z = countStepsToOne(n/3);
	}

	int ans =  1 + min(x, min(y,z));
	return  ans;
	*/


	// METHOD 3 --- USING DP MEMOIZATON
	/*
	vector<int>dp(n+1,-1);
	int ans = helper(dp, n);
	return ans;
	*/


	// METHOD 4 --- USING TABULATION

	vector<int>dp(n+1);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<=n; i++){
		int x = dp[i-1];
		int y= INT_MAX, z = INT_MAX;

		if(i%2==0){
			y = dp[i/2];
		}
		if(i%3==0){
			z = dp[i/3];
		}

		dp[i] = 1+ min(x, min(y,z));
	}
	return dp[n];

	
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}