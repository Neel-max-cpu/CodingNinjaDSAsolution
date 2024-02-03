/*

Problem statement
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry, you have to find and return the maximum value that thief can generate by stealing items.

Note
Space complexity should be O(W).
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13

#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int helper(int *weights, int *values, int n, int maxWeight, int i){
	// base case
	if(i==n || maxWeight==0){
		return 0;


*/


#include <cstring>
#include <iostream>
using namespace std;


#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int helper(int *weights, int *values, int n, int maxWeight, int i){
	// base case
	if(i==n || maxWeight==0){
		return 0;
	}

	// pick the weight
	int a = 0, b = 0;
	if(maxWeight-weights[i]>=0){
		a = values[i] + helper(weights, values, n, maxWeight-weights[i], i+1);
	}

	// don't pick the weigh
	b = helper(weights, values, n, maxWeight, i+1);

	return max(a,b);
}

int helper_rec(int *weights, int *values, int index, int maxWeight){
	// base case here should be <0 since we should consider item of index = 0
	if(index < 0 || maxWeight == 0) return 0;

	// pick 
	int take = 0, notTake = 0;
	if(maxWeight - weights[index] >=0){
		take = values[index] + helper_rec(weights, values, index-1, maxWeight-weights[index]);
	}

	// not pick
	notTake =  helper_rec(weights, values, index-1, maxWeight);

	return max(take, notTake);
}

int helper2(int *weights, int *values, int index, int maxWeight, vector<vector<int>> &dp){

	// base case 
	/*
	if(index == 0){
		if(weigh[0]<=maxWeight) return values[0];
		else return 0;
	}
	*/

	// base case here should be <0 since we should consider item of index = 0
	if(index < 0 || maxWeight == 0) return 0;

	// check
	if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

	// pick 
	int take = 0, notTake = 0;
	if(maxWeight - weights[index] >=0){
		take = values[index] + helper2(weights, values, index-1, maxWeight-weights[index], dp);
	}

	// not pick
	notTake =  helper2(weights, values, index-1, maxWeight, dp);

	int ans = max(take, notTake);
	dp[index][maxWeight] = ans;
	return ans;
}

// tutorial --- https://www.youtube.com/watch?v=GqOmJHQZivw&list=TLPQMjYwMTIwMjSonI0CyA5a3w&index=2
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	
	// ****recursion ---
	/*
	int ans = helper(weights, values, n, maxWeight, 0);
	return ans;
	*/


	// ****recursion --- method 2
	/*
	int ans = helper_rec(weights, values, n-1, maxWeight);
	return ans;
	*/


	// ****dp memoization --- 
	/*
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	int ans = helper2(weights, values, n-1, maxWeight, dp);
	return ans;
	*/

	// ****dp tabulation --- Striver
	
	// vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));

	/* 
	see in the memoizatino, when ever index < 0 and if index == 0 , but then the state maxWeight < weight[0] then return 0
	else atleast(bar minimun) it would be weigth[0] i.e would return the value[0]

	eg -- if wt[0] = 5 and maxWeight = 4 then it would return 0, maxWeight = 3 then 0, maxWeight = 2 then 0 return.....
	eg -- if wt[0] = 5 and maxWeight = 6 then return value[0], if maxWeight = 5 return value[0]

	***therfore, for ever weight. wt[0] to maxWeight i can steal it ---- so that's will be the base case
	and apart from this everyone will be 0 initiallized
	*/
	
	// for(int W = weights[0]; W<=maxWeight; W++){
	// 	dp[0][W] = values[0];
	// }

	/*
	now look out for the changing parameters, here the changing parameters are indexs and maxWeight so 2 loops
	and since 0th case done, so move 1 to n-1, and maxWeight would be 0 to maxWeight
	then copy the recurance
	*/

	// for(int ind = 1; ind<n; ind++){
	// 	for(int W=0; W<=maxWeight; W++){
	// 		int notTake = 0 + dp[ind-1][W];
	// 		int take = 0;
	// 		if(weights[ind]<=W){
	// 			take  = values[ind] + dp[ind-1][W- weights[ind]];
	// 		}
	// 		dp[ind][W] = max(take, notTake);
	// 	}
	// }

	// return dp[n-1][maxWeight];
	


	// ****Space optimization ---- if there is ind-1 then we can space optimise (2rows)
	// METHOD 1 ---
	/*
	vector<int>prev(maxWeight+1, 0), current(maxWeight+1, 0);
	
	// base case
	for(int W = weights[0]; W<=maxWeight; W++){
		prev[W] = values[0];
	}

	for(int ind = 1; ind<n; ind++){
		for(int W=0; W<=maxWeight; W++){
			int notTake = 0 + prev[W];
			int take = 0;
			if(weights[ind]<=W){
				take  = values[ind] + prev[W- weights[ind]];
			}
			current[W] = max(take, notTake);
		}
		prev = current;
	}

	// dp[n-1] will become prev
	return prev[maxWeight];
	*/


	// METHOD 2 --- 1row optimization
	vector<int>prev(maxWeight+1, 0);
	//  here if we look closedly we are using the cell less than the W, so by filling it from backwards we can keeping using the 
	// same row, and hence 1 row optimization
	
	// base case
	for(int W = weights[0]; W<=maxWeight; W++){
		prev[W] = values[0];
	}

	for(int ind = 1; ind<n; ind++){
		// its dependent on the previous row, not any thing in the same row, so even if we do reverse, we will get same ans
		for(int W=maxWeight; W>=0; W--){
			int notTake = 0 + prev[W];
			int take = 0;
			if(weights[ind]<=W){
				take  = values[ind] + prev[W- weights[ind]];
			}
			prev[W] = max(take, notTake);
		}
	}

	// dp[n-1] will become prev
	return prev[maxWeight];

	

}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}