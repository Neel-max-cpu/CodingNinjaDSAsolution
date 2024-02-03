/*


Problem statement
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

Return 0 if the change isn't possible.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
#include<vector>
#include<algorithm>
using namespace std;

int helper(int a[], int n, int value){
	// base case
	if(n!=0){
		if(value == 0) return 1;
		else if(value<0) return 0;
	}


*/

#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>
using namespace std;

int helper(int a[], int n, int value){
	// base case
	if(n!=0){
		if(value == 0) return 1;
		else if(value<0) return 0;
	}
	else if(n==0){
		if(value==0) return 1;
		else return 0;
	}


	/*
	2 options not three --- pick the ele and don't go forward and don't pick the elem and go forward
	cause for eg --
	3
	1 2 3
	4

	and i am at 1(1-- value left); 3 options count1 = pick and don't go forward 1(0) yes
	count2 = pick and go forward 1(0) -- yes
	count3 = don't pick and go forward --- 2(1) 
	count 2 and 1 repeats themselves

	*/
	// each has 3 options
	// pick the element but not not going forward
	int count1 = 0+helper(a, n, value-a[0]);

	// pick the element and go forward
	// int count2 = 0+helper(a+1, n-1, value-a[0]);

	// don't pick the element and go forward
	int count3 = 0+helper(a+1, n-1, value);

	// finally return sum
	// int ans = count1 + count2 + count3;
	int ans = count1 + count3;
	return ans;
}

int helper_mem(int a[], int n, int value, vector<vector<int>>&dp){
	// base case
	if(n!=0){
		if(value == 0) return 1;
		else if(value<0) return 0;
	}
	else if(n==0){
		if(value==0) return 1;
		else return 0;
	}

	// check 
	if(dp[n][value] != -1) return dp[n][value];

	int count1 = 0+helper_mem(a, n, value-a[0], dp);

	// don't pick the element and go forward
	int count2 = 0+helper_mem(a+1, n-1, value, dp);

	// finally return sum

	int ans = count1 + count2;
	dp[n][value] = ans;
	return ans;
}

int helper_tab(int a[], int n, int value){
	vector<vector<int>>dp(n+1, vector<int>(value+1, 0));

	// base case if value == 0 then there will be 1 way
	for(int i=0; i<=n; i++){
		dp[i][0] = 1;
	}
	// base case 2  == 0th row(from col 1 to n) will be all 0 since if n=0 and value>0 there can't be a way to fill up the coins
	// since we don't coins to start with

	for(int i=1; i<=n; i++){
		for(int j=1; j<=value; j++){
			// take without the value of the current
			/*
				int count2 = 0+helper_mem(a+1, n-1, value, dp);
				what are we doing , our value doesn't change while going forward
				so, just put the prev value
				*** remember i = n(elements in the array) and j = value
				** j remains same since value doesn't change
			*/
			int count1 = dp[i-1][j];

			// taking the value of the current
			/*
				int count1 = 0+helper_mem(a, n, value-a[0], dp);
				what are we doing here, taking the current value , sub it with value and don't move forward
				**since not going forward so i stays the same
				** j means current value remaing and a[i-1] = current value coing which we sub(why i-1 since i = n we are taking and indexing wise it starts from 0)
				check whether we won't reach -ve, if yes = no point in going so return 0
				else put the value
			*/
			int count2 = 0;
			if(j>=a[i-1]){
				count2  = dp[i][j-a[i-1]];
			}

			// total ways
			dp[i][j] = count1+count2;
		}
	}

	return dp[n][value];

}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here

	// recursion ---
	// return helper(denominations, numDenominations, value);

	// dp memoization -- here changing parameters are index and value so 2d matrix and thing reverse top to bottom
	/*
	vector<vector<int>>dp(numDenominations+1,  vector<int>(value+1, -1));
	return helper_mem(denominations, numDenominations, value, dp);
	*/

	// dp tabulation ---
	return helper_tab(denominations, numDenominations, value);

}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}