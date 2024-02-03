/*



Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1

#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;


int helper(int n){


*/

#include <bits/stdc++.h>
using namespace std;


#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;


int helper(int n){

	// base case
	if(n==0){
		return 0;
	}

	int y = INT_MAX;
	for(int i=1; i<=sqrt(n); i++){
		int x = 1 + helper(n-i*i);
		y = min(x, y);
	}

	return y;

}

int helper2(int n, vector<int>dp){
	if(n==0){
		return 0;
	}

	if(dp[n]!=-1) return dp[n];

	int y = INT_MAX;
	for(int i=1; i<=sqrt(n); i++){
		int x = 1+helper2(n-i*i, dp);
		y = min(x,y);
	}

	dp[n] = y;
	return dp[n];
	
}

int minCount(int n)
{
	//Write your code here

	// METHOD 1 -- recursion
	/*
	int ans = helper(n);
	return ans;
	*/

	// METHOD 2 -- Memoization dp
	/*
	vector<int>dp(n+1, -1);
	int ans = helper2(n, dp);
	return ans;
	*/

	// METHOD 3 -- dp tabulation not initiallized with -1 since we are taking min and -1 would be smaller than any count
	// vector<int>dp(n+1, INT_MAX);
	// dp[0] = 0;
	// dp[1] = 1;
	// for(int i=2; i<=n; i++){
	// 	for(int j=1; j<=sqrt(i); j++){
	// 		// same thing done, dp[i] = (eg i = 2) then 2(1^2 + 1^2) basically for 1 and second one is for to check for each sq
	// 		dp[i] = min(dp[i], 1+dp[i-j*j]);
	// 	}
	// }
	// return dp[n];



	// using array dynamic allocated array
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2; i<=n; i++){
		arr[i] = INT_MAX;
		for(int j=1; j<=sqrt(i); j++){
			// same thing done, dp[i] = (eg i = 2) then 2(1^2 + 1^2) basically for 1 and second one is for to check for each sq
			arr[i] = min(arr[i], 1+arr[i-j*j]);
		}
	}

	int res = arr[n];
	delete [] arr;
	return res;


}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}