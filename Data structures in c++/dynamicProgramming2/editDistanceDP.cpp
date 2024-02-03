/*

Classroom
DP - 2
profile picture
Problem statement
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.

Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9

#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int helper(string s1, string s2, vector<vector<int>>dp){
	

*/


#include <iostream>
#include <cstring>
using namespace std;


#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int helper(string s1, string s2, vector<vector<int>>dp){
	
	int m = s1.size();
	int n = s2.size();

	// base case
	if(s1.size()==0 || s2.size()==0){
		return max(s1.size(), s2.size());
	}

	// if ans already exists
	if(dp[m][n] != -1) return dp[m][n];
	
	int ans;

	// if 1st char matches
	if(s1[0]==s2[0]){
		// int a = helper(s1.substr(1), s2.substr(1), dp);
		ans = helper(s1.substr(1), s2.substr(1), dp);
		// dp[m][n] = a;
		// return a;
	}

	// if doesn't matches
	else{
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;

		// inserting
		/*
			eg = s1 = abcd, and s2 = zxcd
			here insert in s2 = azcd therefore, s1[0]==s2[0] so, pass bcd and zxcd but here hypothetically inserted
		*/
		a = 1 + helper(s1.substr(1), s2, dp);

		// replace or update
		/*
			eg = s1 = abcd, and s2 = zxcd
			here replace in s2 = a(z)cd [z is replaced by a] therefore, s1[0]==s2[0] so, pass bcd and xcd but here hypothetically replaced
		*/
		b = 1 + helper(s1.substr(1), s2.substr(1), dp);

		// delete
		/*
			eg = s1 = abcd, and s2 = zxcd
			here delete in s2 = (z)cd [z is deleted] so, pass abcd and xcd but here hypothetically deleted
		*/
		c = 1 + helper(s1, s2.substr(1), dp);

		// int ans = min(a, min(b,c));
		ans = min(a, min(b,c));
		// dp[m][n] = ans;
		// return ans;
	}

	dp[m][n] = ans;
	return ans;
}

int editDistance(string s1, string s2)
{
	//Write your code here
	
	// dp memoization ----
	// /*
	vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1,-1));
	return helper(s1, s2, dp);
	// */


	// dp tabulation ---- code is similar to lcs
	/*
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>>dp(m+1, vector<int>(n+1));

	// directly fill
	dp[0][0] = 0;

	// for 1st row
	for(int j=1; j<=n; j++){
		dp[0][j] = j;
	}

	// for 1st column
	for(int i=1; i<=m; i++){
		dp[i][0] = i;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			// check if 1st ele is same or not
			if(s1[m-i] == s2[n-j]){
				dp[i][j]  = dp[i-1][j-1];
			}
			else{
				// insert -- then s1 becomes short and s2 remains same
				int a = 1+dp[i-1][j];
				// delete -- then s1 remains same and s2 becomes short
				int b = 1+dp[i][j-1];
				// replace -- then both becomes short
				int c = 1+dp[i-1][j-1];
				dp[i][j]  = min(a,min(b,c));
			}
		}
	}
	
	return dp[m][n];
	
	*/
	


}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}