/*

Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
Note:
Fibonacci series is the series of numbers where each number is obtained by adding two previous numbers. The first two numbers in the Fibonacci series are 0 and 1.


Input Format :
Integer N
Output Format :
true or false
Constraints :
0 <= n <= 10^4
Sample Input 1 :
5
Sample Output 1 :
true
Sample Input 2 :
14
Sample Output 2 :
false    

bool checkMember(int n){

  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */








*/

#include<vector>





bool checkMember(int n){

  /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Return output and don't print it.
   * Taking input and printing output is handled automatically.
  */
  vector<int>dp(1e4+1);
  dp[0] = 0, dp[1] = 1;
  for(int i=2; i<=1e4; i++){
    dp[i] = dp[i-1] + dp[i-2]; 
  }

  for(int i=0; i<1e4+1; i++){
    if(dp[i]==n) return true;
  }
  return false;

}