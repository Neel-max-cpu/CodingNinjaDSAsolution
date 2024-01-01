/*

Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

string uniqueChar(string str) {
	// Write your code here
	unordered_map<char,int>m;
	
	







*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

string uniqueChar(string str) {
	// Write your code here
	unordered_map<char,int>m;
	
	
	// METHOD 1 ----
	/*
	t += str[0];
	string t = "";
	m[str[0]]++;
	for(int i=1 ; i<str.size(); i++){
		if(m.count(str[i]) <= 0){
			t+=str[i];
			m[str[i]]++;
		}
	}
	return t;
	*/

	// METHOD 2 ----
	string ans;
	unordered_set<char>s;
	
	for(char ch: str){
		// if not found
		if(s.find(ch) == s.end()){
			ans.push_back(ch);
			s.insert(ch);
		}
	}
	/*
	eg --
	  if (sampleSet.find("geeks1") != sampleSet.end()) { 
        cout << "element found." << endl; 
    }  else { 
        cout << "element not found" << endl; 
    }
	*/
	
	return ans;

}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}