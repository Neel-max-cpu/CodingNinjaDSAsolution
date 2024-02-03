/*

Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Time complexity should be O(h).

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315


#include <algorithm>
#include <vector>
using namespace std;

#define  ll long long int
const unsigned int  mod = 1e9+7;

int helper(vector<ll>dp, int n){

*/

#include <iostream>
using namespace std;



#include <algorithm>
#include <vector>
using namespace std;

#define  ll long long int
const unsigned int  mod = 1e9+7;

int helper(vector<ll>dp, int n){
    if(n<=1){
        return 1;
    }

    // already present  
    if(dp[n]!=-1) return dp[n];


    // different cases
    ll x = helper(dp, n-1)%mod;
    ll y = helper(dp, n-2)%mod;

    ll total = ((x*x)%mod + (2*x*y)%mod)%mod;
    dp[n] = total;

    return dp[n];
}

int balancedBTs(int n) {
    // Write your code here

    // code is similar to fibonacii sequence here were are calling h-1 and h-2

    // METHOD 1 -- DP Memoization
    /*
    vector<ll>dp(n+1, -1);
    int ans = helper(dp, n);
    return ans;
    */

    // METHOD 2 -- DP Tabulation
    vector<ll>dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n; i++){
        ll x = dp[i-1]%mod;
        ll y = dp[i-2]%mod;
        ll total = ((x*x)%mod + (2*x*y)%mod)%mod;
        dp[i] = total;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}