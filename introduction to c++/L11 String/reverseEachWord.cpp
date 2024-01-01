/*

Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to print the sentence such that each word in the sentence is reversed.
Example:
Input Sentence: "Hello, I am Aadil!"
The expected output will print, ",olleH I ma !lidaA".
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input string represents the sentence given to Aadil.
Output Format:
The only line of output prints the sentence(string) such that each word in the sentence is reversed. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Always indent your code
Sample Output 2:
syawlA tnedni ruoy edoc
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    //Write your code here
}





*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    //Write your code here

    // METHOD 1
    /*
    string s;
    // for string getline(cin, nameString) , and for char array, cin.get(name, size);
    getline(cin,s);
    // cout<<s;
    string t = "";
    int start = 0, end  = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            end = i;
            reverse(s.begin()+start , s.begin()+end);
            start = end+1;
        }
    }

    reverse(s.begin()+start, s.end());
    cout<<s;
    */

    // METHOD 2
    string s;
    while(cin>>s){
        reverse(s.begin(),s.end());
        cout<<s<<" ";
    }

}