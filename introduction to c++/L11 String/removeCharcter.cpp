/*

For a given string(str) and a character X, complete the definition of the functions that removes all the characters in string(str) that matches the character X.
Input Format:
The first line of input contains a string without any leading and trailing spaces.

The second line of input contains a character(X) without any leading and trailing spaces.
Output Format:
The first line of output contains the characters that doesn't match the character 'X'.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aabccbaa
a
Sample Output 1:
bccb
Sample Input 2:
xxyyzxx
y
Sample Output 2:
xxzxx
void removeAllOccurrencesOfChar(string input, char c) 
{
    
}





*/

#include<bits/stdc++.h>
using namespace std;

void removeAllOccurrencesOfChar(string input, char c) 
{
    for(char it:input){
        if(it==c) continue;
        else cout<<it;
    }
}

int main(){
    string a;
    cin>>a;
    char c;
    cin>>c;
    removeAllOccurrencesOfChar(a,c);
}