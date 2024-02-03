/*

Classroom
DP - 2
profile picture
Problem statement
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= N <= 10^3
Time Limit: 1 second
Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2


#include<algorithm>
#include<vector>
using namespace std;



int longestIncreasingSubsequence(int* arr, int n) {



*/

#include <iostream>
using namespace std;



#include<algorithm>
#include<vector>
using namespace std;



int longestIncreasingSubsequence(int* arr, int n) {

	// different kind of dp problem

	vector<int>dp(n);
	dp[0] = 1;
	int best = 0;

	for(int i=1; i<n; i++){
		dp[i] = 1;
		for(int j=i-1; j>=0; j--){
			// strictly increasing
			if(arr[j]>=arr[i]) continue;
			int possible_ans = dp[j]+1;
			if(possible_ans > dp[i])
				dp[i] = possible_ans;
		}
		best = max(best, dp[i]);
		// cout<<i<<":"<<dp[i]<<endl;
	}
	/*
	int best = 0;
	for(int i=0; i<n; i++){
		if(best<dp[i]) best = dp[i];
	}
	*/
	return best;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}