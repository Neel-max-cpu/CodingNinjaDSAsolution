/*



For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
int countBracketReversals(string input) {
	// Write your code here
}





*/


#include <iostream>
#include <string>
using namespace std;


#include <stack>
#include <algorithm>
#include<string>

int countBracketReversals(string input) {
	int len = input.size();

	if(len == 0)return 0;

	if(len %2 !=0) return -1;

	stack<char>s;

	for(int i=0; i<len; i++){
		char currentChar  = input[i];

		if(currentChar == '{'){
			s.push(currentChar);
		}
		else{
			// if '}' is the char and stack is not empty and top char is opening brac '{' then balanced so pop
			if(!s.empty() && s.top()=='{'){
				s.pop();
			}
			// else push the closing brac '}'
			else s.push(currentChar);
		}
	}

	// now we are left with all the unbalanced one

	int count = 0;

	// till stack is not empty
	while(!s.empty()){
		char char1 = s.top();
		s.pop();
		char char2 = s.top();
		s.pop();

		// if not equal then = }{ , 2option are there directly one after the other(still reverse both to be balanced) or 
		// there were some balanced bracket in between but were removed -- in all case +2
		if(char1!=char2){
			count +=2;
		}
		// similar  {{   or   }} ---- +1 in both case, first one change the 2nd one and in second one change the 1st one
		else count+=1;
	}

	return count;


}
/*
int countBracketReversals(string input) {
	// Write your code here
	
	
	int count = 0;
	if(input.size()%2==0){
		int n = input.size();
		stack<char>s;
		for(int i=0; i<n; i++){
			// if closing bracket and not empty
			if(input[i]=='}' && !s.empty()){
				if(s.top()=='{') s.pop();
				else s.push(input[i]);
			}
			else s.push(input[i]);
		}

		int len = s.size();
		n = 0;
		while(!s.empty() && s.top()=='{'){
			s.pop();
			n++;
		}
		return (len/2 + n%2);
	
	}
	else return -1;
}
*/

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}