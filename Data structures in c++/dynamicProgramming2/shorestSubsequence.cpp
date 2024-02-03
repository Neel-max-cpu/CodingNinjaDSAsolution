/*

Problem statement
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.

#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
using namespace std;

// string helper_rec(string s, string v, int i, int j){
int helper_rec(string s, string v, int m, int n) {


*/


#include <iostream>
#include <string>
using namespace std;


#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
using namespace std;

// string helper_rec(string s, string v, int i, int j){
int helper_rec(string s, string v, int m, int n) {
    // base cases
    if (n == 0) {
        return 1; // Shortest Subsequence in S will be of length 1
    }
    if (m == 0) {
        return 1001; // Since it is given that the answer to the problem always exists
                     // So length of "s" cannot be zero
    }

    char current = s[m - 1];
    // finds the occurance of current in whole of v
    // substr (0,n) -- starting index 0 and length n and reverse find(rfind -- gives last occurance)
    auto it = v.substr(0, n).rfind(current);
    if (it != string::npos) {
        return min(helper_rec(s, v, m - 1, n), helper_rec(s, v, m - 1, it) + 1);
    } 
    else {
        return 1;
    }
}


int helper_mem(string s, string v, int m, int n, vector<vector<int>>&dp) {
    // base cases
    if (n == 0) {
        return 1; // Shortest Subsequence in S will be of length 1
    }
    if (m == 0) {
        return 1001; // Since it is given that the answer to the problem always exists
                     // So length of "s" cannot be zero
    }

    // check 
    if(dp[m][n]!=-1) return dp[m][n];


    char current = s[m - 1];
    // finds the occurance of current in whole of v
    // substr (0,n) -- starting index 0 and length n and reverse find(rfind -- gives last occurance)

    auto it = v.substr(0, n).rfind(current);
    if (it != string::npos) {
        int ans = min(helper_mem(s, v, m - 1, n, dp), helper_mem(s, v, m - 1, it, dp) + 1);
        dp[m][n] = ans;
        return ans;
    } 
    else {
        dp[m][n] = 1;
        return 1;
    }
}

int solve(string s, string v) {
    // Write your code here
    int m = s.length();
    int n = v.length();

    // recursion ---
    /*
    return helper_rec(s, v, m, n);
    */

    // dp memoization ---
    /*
    vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
    return helper_mem(s,v,m,n,dp);
    */

    // dp tabulation ---
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1001));

    // Base cases -- 1st col initiallized with 1
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1; // Shortest Subsequence in S will be of length 1
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            char current = s[i - 1];
            /*
            When i=1 and j=1:
            current is assigned the value of s[0], which is 'b'.
            v.substr(0, 1) is the substring of v from index 0 to 0, which is "b".
            The last occurrence of 'b' in this substring is at index 0.
            Therefore, it is assigned the value 0.
            */        
            auto it = v.substr(0, j).rfind(current);
            if (it != string::npos) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][it] + 1);
            } else {
                dp[i][j] = 1;
            }
        }
    }

    /*
    for eg == 
    babab
    babba
        |  0    1      2        3      4      5
  ----|----------------------------------
    0  |  1  1001 1001 1001 1001 1001
    1  |  1  2       2       1001 1001 1001
    2  |  1  1       2       3       3       1001
    3  |  1  1       2       3       3       4
    4  |  1  1       2       2       3       4
    5  |  1  1       2       2       2       3


    */


    // for(auto it:dp){
    //     for(auto x:it) cout<<x<<" ";
    //     cout<<"new row"<<endl;
    // }
    // cout<<"new here"<<endl;

    return dp[m][n];
}

int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}