/*


Problem statement
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.

Note: A substring is a contiguous segment of a string.

For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= |S|<= 15
where |S| denotes the length of string 'S'.

Time Limit: 1 sec.
Sample Input 1:
aaC
Sample Output 1:
["C", "a", "a"]
["C", "aa"]
Explanation for input 1:
For the given string "aaC" there are two partitions in which all substring of partition is a palindrome.
Sample Input 2:
BaaB
Sample Output 2:
["B", "B", "a", "a"]
["B", "B", "aa"]
["BaaB"]
Explanation for input 2:
For the given string "BaaB", there are 3 partitions that can be made in which every substring is palindromic substrings.



*/


#include <iostream>
#include <algorithm>
using namespace std;

#include <bits/stdc++.h> 
#include<vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string t){
	string s = t;
	reverse(t.begin(), t.end());
	if(s==t) return true;
	else return false;
}


// void helper(string &s, int index, vector<vector<string>>&ans, vector<string>&v, string t){
void helper(string &s, int index, vector<vector<string>>&ans, vector<string>&v){


	// base case
	 if (index == s.size()) {
        ans.push_back(v);
        return;
    }

    for (int i = index; i < s.size(); ++i) {
		// s.substr(start index and length of the substring)
        string substring = s.substr(index, i - index + 1);
		// cout<<substring<<endl;

        if (isPalindrome(substring)) {
            v.push_back(substring);
			// calling for the next index
            helper(s, i + 1, ans, v);
            v.pop_back();
        }
    }

}


void helper2(string &s, int start, vector<vector<string>>&ans, vector<string>&v, vector<vector<bool>>dp){
	if(start>=s.size()){
		ans.push_back(v);
		return;
	}

	for(int i = start; i<s.size(); i++){
		if(dp[start][i]){
			v.push_back(s.substr(start, i+1-start));
			helper2(s, i+1, ans, v, dp);
			v.pop_back();
		}
	}
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.

	// METHOD 1 ---
	/*
    vector<vector<string>>ans;
    vector<string>v;

    helper(s, 0, ans, v);
	// for(auto it:ans){
	// 	for(auto x:it) cout<<x<<" ";
	// 	cout<<endl;
	// }
	return ans;
	*/


	// METHOD 2 --- same like method 1 just here we are precomputing which substring are palindrome
	// previously in method 1 we were directly checking
	vector<vector<string>>ans;
	vector<vector<bool>>dp(s.size(), vector<bool>(s.size(), false));
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<=i; j++){
			// length is 0 or 1  --- i ___ j , check if s[i] == s[j] and yes then check i+1 and j-1 is true(get from dp)
			// since 2loops so dp[j+1][i-1] 
			if(s[i]==s[j] && (i-j<2 || dp[j+1][i-1]))
				dp[j][i] = true;
		}
	}

	vector<string>v;
	helper2(s, 0, ans, v, dp);
	return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    //string str;
    //getline(cin, str);
    while(t--) {

    	string S;
    	getline(cin, S);

    	vector<vector<string>> ans = partition(S);
    	
    	for(int i = 0; i < ans.size(); i++) {

    		cout << "[";
    		
    		sort(ans[i].begin(), ans[i].end());
    		for(int j = 0; j < ans[i].size(); j++) {

    			if(j != ans[i].size() - 1) {
    				cout << "\"" << ans[i][j] << "\", ";
    			}
    			else {
    				cout << "\"" << ans[i][j] << "\"";
    			}

    		}

    		cout << "]" << endl;

    	}

    }

    return 0;

}