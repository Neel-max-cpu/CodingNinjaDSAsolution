/*


For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
Input Format:
The first and the only line of input contains a string expression without any spaces in between. Input string will only consists of round brackets.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function. 
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
bool isBalanced(string expression) 
{
    // Write your code here
}





*/

#include <iostream>
#include <string>
using namespace std;


#include <stack>
#include <string>
#include <cstring>
#include <algorithm>


bool isBalanced(string s) 
{
    // Write your code here
    stack<char>a;

  // METHOD 1 ----
    for(int i=0; i<s.size(); i++){
        if(a.empty()){
            a.push(s[i]);
        }
        else if(a.top()=='(' && s[i]==')') a.pop();
        else a.push(s[i]);
    }

    if(a.empty()) return true;
    else return false;


 // METHOD 2  ---- optimised
  // string s1 and stack s
 stack<char>s;
    for(char ch:s1){
        if(ch=='('){
          s.push(ch);
        }
        else{
            if(s.empty()) return false;

            char top=s.top();

            if(ch==')' && top!='('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
