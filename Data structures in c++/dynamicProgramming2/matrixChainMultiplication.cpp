/*

Problem statement
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int helper(int *arr, int start, int end){
    // base case
    // start == end no matrix
    // start == end-1 , 1 matrix directly multiply
    if(start==end || start==end-1) return 0;


*/


#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int helper(int *arr, int start, int end){
    // base case
    // start == end no matrix
    // start == end-1 , 1 matrix directly multiply
    if(start==end || start==end-1) return 0;


    int ans = INT_MAX;
    // k will go from start+1 to end-1
    for(int k = start+1; k<end; k++){
        int f1 = helper(arr, start, k);
        int f2 = helper(arr, k, end);
        int f3 = arr[start]*arr[k]*arr[end];
        int res = f1+f2+f3;
        ans = min(res, ans);
    }

    return ans;
}

int helper_mem(int *arr, int start, int end, vector<vector<int>>&dp){
    // base case
    // start == end no matrix
    // start == end-1 , 1 matrix directly multiply
    if(start==end || start==end-1) return 0;

    // check
    if(dp[start][end]!=-1) return dp[start][end];

    int ans = INT_MAX;
    // k will go from start+1 to end-1
    for(int k = start+1; k<end; k++){
        int f1 = helper_mem(arr, start, k, dp);
        int f2 = helper_mem(arr, k, end, dp);
        int f3 = arr[start]*arr[k]*arr[end];
        int res = f1+f2+f3;
        ans = min(res, ans);
    }

    dp[start][end] = ans;
    return ans;
}

int helper_tab(int *arr, int n){
    
    /*
    For simplicity of the program, one extra row and one
    extra column are allocated in dp[][]. 0th row and 0th
    column of dp[][] are not used
    */
    n += 1;
    /*
    dp[i,j] = Minimum number of scalar multiplications needed
    to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is arr[i-1] x arr[i]
    */
    vector<vector<int>> dp(n, vector<int>(n));

    // base case
    // Cost is zero when multiplying one matrix.
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    
    // L is chain length.
    /*
    chain length" refers to the number of matrices being multiplied together in a sequence
    
    for n = 3, (2 3 4 5) arr
    
    L=2to<4 i.e 2,3

    L = 2: We consider chains of length 2.
    (i = 1 to i<3)
    i=1: dp[1][2]:
    ->(k=1to<=1)k=1: dp[1][1] + dp[2][2] + (2 * 3 * 4) = 0 + 0 + 24 = 24
    i=2: dp[2][3]:
    ->(k=2to<=2)k=2: dp[2][2] + dp[3][3] + (3*4*5) = 0 + 0 + 60 = 60

    L = 3:** We consider chains of length 3.
    - For chain A1A2A3, we calculate the cost using different parenthesizations.
    (i=1 to i<2):
    i=1: dp[1][3]:
    ->(k=1 to<=2):
    k = 1: dp[1][1] + dp[2][3] + (2 * 3 * 5) = 0 + 60 + 30 = 90
    therefore, dp[1][3] = 90;
    k = 2: dp[1][2] + dp[3][3] + (2 * 4 * 5) = 24 + 0 + 40 = 64
    here q<dp[1][3] = 64<90; so, dp[1][3] = 64;

    done

    for n = 3, (2 3 4 5) arr
    0 0 0 0
    0 0 24 64
    0 0 0 60
    0 0 0 0

    */
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j-1; k++) {
                // similar to recursion --- f(arr, s,k)+f(arr,k,e)+ (arr[s]*arr[k]*arr[e]);
                int q = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if (q < dp[i][j]) dp[i][j] = q;
            }
        }
    }

//   for(int i=0; i<n; i++){
//       for(int j=0; j<n; j++) cout<<dp[i][j]<<" ";
//       cout<<"new row"<<endl;
//   }
//     cout<<"new here"<<endl;

    return dp[1][n - 1];
}



int matrixChainMultiplication(int* arr, int n) {
    // Write your code here

    /*  3 = 10 15 20 25, there are n(3) matrix then we need n+1 how
    dimensions of matrices are 10*15, 15*20, 20*25, --- since we can only multiply matrix when 
    the column of the 1st matrix == row of the 2nd matrix

    eg -- how many operations needed ---
    n = 3
    2 3 4 5 === then the actual matrices are 2*3, 3*4, 4*5, now lets see how many operations needed
    (2*3  x 3*4) x 4*5 
    here in the bracket 2x3x4 operations needed = 24 and the resultant matrix dimension = 2*4
    now, 2*4 x 4*5 , here 2x4x5 = 40 operation, then total operations = 24+40 = 64 operations

    now different brackets 2 = 2*3 x (3*4 x 4*5), 
    operations in the bracket = 3x4x5 = 60 operations, and the resultant matrix = 3*5
    2*3 x 3*5 = 2x3x5 = 30 operation, therefore total operations, 60+30 = 90 operations,
    
    so, where put the brackets matters very much
    */

    // recursive solution --
    // return helper(arr, 0, n);

    // dp memoization --- 
    /*
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    return helper_mem(arr, 0, n, dp);
    */

    // dp tabulation ---
    return helper_tab(arr, n);
    
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}