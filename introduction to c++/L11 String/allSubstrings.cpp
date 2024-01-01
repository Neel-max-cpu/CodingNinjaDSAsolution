/*

For a given input string(str), write a function to print all the possible substrings.
Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas "cdng" is not as the characters taken are not contiguous
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
Print all the substrings possible, where every substring is printed on a separate line.
Note:
The order in which the substrings are printed does not matter.
Constraints:
0 <= N <= 10^3
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abc
Sample Output 1:
a 
ab 
abc 
b 
bc 
c 
 Sample Input 2:
co
Sample Output 2:
c 
co 
o
#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    //Write your code here
}

int main() {






*/

#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    //Write your code here
    // METHOD 1
    /*
    for(int i=0; i<input.size(); i++){
        int j = i;
        while(j<input.size()){
            for(int l=i; l<=j; l++) cout<<input[l];
            j++;
            cout<<endl;
        }
    }
    */

    // MEHTOD 2
    for(int i=0; i<input.size(); i++){
        for(int j=i; j<input.size(); j++){
            for(int l = i; l<=j; l++) cout<<input[l];
            cout<<endl;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}