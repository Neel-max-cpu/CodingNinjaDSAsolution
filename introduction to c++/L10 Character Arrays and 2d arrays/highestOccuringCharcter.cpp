/*

For a given a string(str), find and return the highest occurring character.
Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.
Consider:
Assume all the characters in the given string to be in lowercase always.
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string. 
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abdefgbabfba
Sample Output 1:
b
Sample Input 2:
xy
Sample Output 2:
x
char highestOccurringChar(char input[]) {
    // Write your code here
}






*/

#include <iostream>
#include <cstring>
using namespace std;


#include <algorithm>
#include <cstring>
#include <map>

char highestOccurringChar(char input[]) {
    // Write your code here
    map<char,int>m;
    int n = strlen(input);
    for(int i= 0; i<n; i++) m[input[i]]++;

    char c;
    int mx = 0;
    for(auto it:m){
        if(it.second>mx){
            mx = it.second;
            c = it.first;
        }
    }
    return c;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}