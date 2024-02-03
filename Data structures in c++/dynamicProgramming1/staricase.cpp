/*

Problem statement
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with mod(10^9 +7)

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
const unsigned int mod = 1e9+7;

int helper(int n){
    // base case
    if(n==0){


*/


#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
const unsigned int mod = 1e9+7;

int helper(int n){
    // base case
    if(n==0){
        return 1;
    }

    // different cases
    int x = helper(n-1);

    int y  = 0, z = 0;
    if(n>=2){
        y = helper(n-2);
    }

    if(n>=3){
        z = helper(n-3);
    }

    return x+y+z;
}


int helper2(vector<int>&dp, int n){

    // base case
    if(n==0){
        return 1;
    }

    // different cases
    ll x = helper2(dp, n-1);

    ll y = 0, z = 0;
    if(n>=2){
        y = helper2(dp, n-2);
    }

    if(n>=3){
        z = helper2(dp, n-3);
    }

    ll ans = (x%mod+y%mod+z%mod)%mod;
    dp[n] = ans%mod;
    return dp[n]%mod;

}

int countWays(int n){
    // METHOD 1 -- using recursion
    /*
    int ans = helper(n);
    return ans;
    */

    // METHOD 2 -- using dp memoization
    /*
    vector<int>dp(n+1,-1);
    ll ans = helper2(dp, n);
    return ans;
    */

    // METHOD 3  -- using dp tabulation
    /*
    vector<ll>dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(ll i=2; i<=n; i++){
        ll x = dp[i-1];
        
        ll y = 0, z= 0;
        if(i>=2){
            y = dp[i-2];
        }

        if(i>=3){
            z = dp[i-3];
        }

        ll ans = (x%mod+y%mod+z%mod)%mod;
        
        dp[i] = ans;
    }

    return dp[n]%mod;
    */


    // Method 4 -- direct storing the variables

    if(n<=1){
        return 1;
    }
    
    // a represents number of ways to climb 0stairs = 1 way
    // b represents number of ways to climb 1stair = 1 way (0 and 1 both 1 way)
    // c represents number of ways to climb 2stair = 2 ways(0-1-2 or 0-2)
    // similar to dp but here we aren't saving each value
    ll a = 1, b= 1, c= 2;
    for(int i=0; i<=n-3; i++){
        ll d = (a+b+c)%mod;
        a = b;
        b = c;
        c = d;
    }
    return c;

}


int main()
{
    // take input from the user.
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int a = countWays(n);
        cout<<a<<endl;
    }
    return 0;
}