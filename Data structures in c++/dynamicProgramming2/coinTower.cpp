/*

Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins. 
#include<vector>
#include<algorithm>
using namespace std; 

int helper_rec(int n, int x, int y){
	// base case
	if(n==1 || n==x || n==y){
		// beerus win since he moves first(we are trying to make beerus win)
		return 1; 
	}
…	// }

}
*/

#include <iostream>
#include <string>
using namespace std;

#include<vector>
#include<algorithm>
using namespace std; 

int helper_rec(int n, int x, int y){
	// base case
	if(n==1 || n==x || n==y){
		// beerus win since he moves first(we are trying to make beerus win)
		return 1; 
	}
	
	// conditions
	int a = helper_rec(n-1, x, y);
	int b = 0, c = 0;
	if(n-x>=1) b = helper_rec(n-x, x, y);
	if(n-y>=1) c = helper_rec(n-y, x, y);

	// if at n-1 its 1(wins), at n-x its 1(wins) and n-y its 1(wins) then he won't win at n coins 
	// so, if all 1 then won't win but if there's atleast one possible condition where he can win(0) then !0 = 1(win)
	return !(a&&b&&c);
}

int helper_mem(int n, int x, int y, vector<int>& dp) {
    // Check if the result is already memoized
    if (dp[n] != -1) {
        return dp[n];
    }

    // Base cases
    if (n == 1 || n == x || n == y) {
        dp[n] = 1;  // Beerus wins
    } else {
        int a = helper_mem(n - 1, x, y, dp);
        int b = (n - x >= 1) ? helper_mem(n - x, x, y, dp) : 0;
        int c = (n - y >= 1) ? helper_mem(n - y, x, y, dp) : 0;

        // Update dp[n] based on the results
        dp[n] = !(a && b && c);
    }

    // Return the winner based on the memoized result
    return dp[n];
}

string findWinner(int n, int x, int y)
{
	// Write your code here .

	// recursion -----
	/*
	int ans = helper_rec(n,x,y);
	if(ans!=0) return "Beerus";
	else return "Whis";
	*/

	// memoization -----
	/*
	vector<int> dp(n + 1, -1);
    int ans =  helper_mem(n, x, y, dp);
	if(ans!=0) return "Beerus";
	else 
		return "Whis";
	*/

	// METHOD 1 --- better tabulation ----
	// /*
	vector<int>dp(n+1,0);
	// *****base cases
	// dp[0] = 0;
	// dp[1] = 1;
	// dp[x+1] = 1;			// done below
	// dp[y+1] = 1;
	int a=0,b=0,c=0;
	/*
	for(int i=2; i<=n; i++){
		// ****base cases 
		// if(i==x || i==y) continue
		if(i==x || i==y) {
			dp[i] = 1;
			continue;
		}
		if(i-x>=1){
			a = dp[i-x]^1;
		}

		if(i-y>=1){
			b=dp[i-y] ^1;
		}

		c = dp[i-1]^1;

		dp[i] = max(a,max(b,c));
	}
	*/

	// or we can directly write base case in the loop
	for(int i=1; i<=n; i++){
		// ****base cases 
		if(i==x || i==y || i==1) {
			dp[i] = 1;
			continue;
		}
		if(i-x>=1){
			// a = dp[i-x]^1;
			// or
			a = dp[i-x];
		}

		if(i-y>=1){
			// b=dp[i-y] ^1;
			// or
			b=dp[i-y];
		}

		// c = dp[i-1]^1
		// or;
		c = dp[i-1];

		// dp[i] = max(a,max(b,c));
		// or
		dp[i] = !(a&&b&&c);
	}

	if(dp[n]!=0){
		return "Beerus";
	}
	else 
		return "Whis";



	// METHOD 2 ---
	// considering y will always be greater
	// if(x>y) swap(x,y);


	// vector<bool>dp(n+1);

	// for(int i=1; i<=n; i++){
	// 	/*
	// 	Trivial case : if 1, x or y coins are remaining and it's Beerus' turn,
	// 	he will simply pick up all coins and win the game.
	// 	*/
	// 	if(i==1 || i==x || i==y){
	// 		dp[i] = true;
	// 	}
	// 	/*
	// 	If less than x coins remain, each player can only pick up one coin per turn.
	// 	So the result of the game when i coins are remaining will be the reverse
	// 	of the result when there were i - 1 coins.
	// 	*/
	// 	else if(i<x){
	// 		dp[i] = !dp[i-1];
	// 	}
	// 	/*
	// 	If the number of coins is between x and y, each player can pick up either 1 or x coins
	// 	per turn. Now, each player wants to win, so they will look at the state of the game when
	// 	i - 1 coins remain and also when i - x coins remain. If the player is winning in any of
	// 	those states, he will try to get to that state, i.e, if the player is winning in i - 1
	// 	state, he will remove 1 coin. If he's winning in the i - x state, he will remove i - x
	// 	coins. If he is losing in both states, then it doesn't matter what he does, he will still lose.
	// 	So to get the value of dp[i], we will first AND(&) the values of dp[i - 1] and dp[i - x]
	// 	and then NOT(!) it.
	// 	*/
	// 	else if(i<y){
	// 		dp[i] = !(dp[i-x]&&dp[i-1]);
	// 	}
	// 	/*
	// 	The reasoning for this case is similar to the one explained above
	// 	*/
	// 	else{
	// 		dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
	// 	}
	// }	
	// bool result = dp[n];
	// if (result){
	// 	return "Beerus";
	// }
	// else{
	// 	return "Whis"; 
	// }

}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}