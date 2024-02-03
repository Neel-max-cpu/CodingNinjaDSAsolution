/*


Problem statement
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.

Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
You need to find the edit distance from input string1 to input string2.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2

#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int helper(string s1, string s2){
	// base case

*/


#include <cstring>
#include <iostream>
using namespace std;


#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int helper(string s1, string s2){
	// base case
	if(s1.size()==0){
		return 0;
	}
	if(s2.size()==0 && s1.size()!=0){
		return s1.size();
	}


	// if 1st char matches
	if(s1[0]==s2[0]){
		// return editDistance(s1.substr(1), s2.substr(1));
		return helper(s1.substr(1), s2.substr(1));
	}

	// if doesn't matches
	else{
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;

		// inserting
		/*
			eg = s1 = abcd, and s2 = zxcd
			here insert in s2 = azcd therefore, s1[0]==s2[0] so, pass bcd and zxcd but here hypothetically inserted
		*/
		// a = 1 + editDistance(s1.substr(1), s2);
		a = 1 + helper(s1.substr(1), s2);

		// replace or update
		/*
			eg = s1 = abcd, and s2 = zxcd
			here replace in s2 = a(z)cd [z is replaced by a] therefore, s1[0]==s2[0] so, pass bcd and xcd but here hypothetically replaced
		*/
		// b = 1 + editDistance(s1.substr(1), s2.substr(1));
		b = 1 + helper(s1.substr(1), s2.substr(1));

		// delete
		/*
			eg = s1 = abcd, and s2 = zxcd
			here delete in s2 = (z)cd [z is deleted] so, pass abcd and xcd but here hypothetically deleted
		*/
		// c = 1 + editDistance(s1, s2.substr(1));
		c = 1 + helper(s1, s2.substr(1));

		int ans = min(a, min(b,c));
		return ans;
	}
}


int editDistance(string s1, string s2) {
	// Write your code here

	// METHOD 1 --- 6/7 tc passes
	/*
	if(s1.size()<s2.size()){
		return helper(s2, s1);
	}
	return helper(s1, s2);
	*/



	
	// METHOD 2 ---
	// base case
	if(s1.size()==0 || s2.size()==0){
		return max(s1.size(), s2.size());
	}


	// if 1st char matches
	if(s1[0]==s2[0]){
		return editDistance(s1.substr(1), s2.substr(1));
		// return helper(s1.substr(1), s2.substr(1));
	}

	// if doesn't matches
	else{
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;

		// inserting
		/*
			eg = s1 = abcd, and s2 = zxcd
			here insert in s2 = azcd therefore, s1[0]==s2[0] so, pass bcd and zxcd but here hypothetically inserted
		*/
		a = 1 + editDistance(s1.substr(1), s2);
		// a = 1 + helper(s1.substr(1), s2);

		// replace or update
		/*
			eg = s1 = abcd, and s2 = zxcd
			here replace in s2 = a(z)cd [z is replaced by a] therefore, s1[0]==s2[0] so, pass bcd and xcd but here hypothetically replaced
		*/
		b = 1 + editDistance(s1.substr(1), s2.substr(1));
		// b = 1 + helper(s1.substr(1), s2.substr(1));

		// delete
		/*
			eg = s1 = abcd, and s2 = zxcd
			here delete in s2 = (z)cd [z is deleted] so, pass abcd and xcd but here hypothetically deleted
		*/
		c = 1 + editDistance(s1, s2.substr(1));
		// c = 1 + helper(s1, s2.substr(1));

		int ans = min(a, min(b,c));
		return ans;
	}

}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}