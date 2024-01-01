/*

Reverse the given string word-wise. The last word in the given string should come at 1st place, the last-second word at 2nd place, and so on. Individual words should remain as it is.
Input format:
The first and only line of input contains a string without any leading and trailing spaces.
Output format :
The only line of the output prints the Word wise reversed string.
Constraints :
0 <= |S| <= 10^5
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
#include <iostream>
using namespace std;

string reverseStringWordWise(string input)
{
    //Write your code here
}

int main()
{






*/

#include <iostream>
#include <algorithm>
using namespace std;

string reverseStringWordWise(string input)
{
    //Write your code here

    // METHOD 1: 
    /*
    string s ="";
    for(int i=input.size()-1; i>=0; i--){
        s.push_back(input[i]);
    }
    // return s;

    int start = 0, end = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i]==' '){
            end = i-1;
            reverse(s.begin()+start, s.begin()+end);
            start = i+1;
        }
    }
    cout<<s<<endl;
    end = s.size()-1;
    reverse(s.begin()+start, s.begin()+end);

    return s;
    */



    // METHOD 2
    string s ="";
    int end = input.size()-1;
    for(int i=input.size()-1; i>=0; i--){
        // s.push_back(input[i]);
        if(input[i]==' '){
            for(int j=i+1; j<=end; j++){
                s.push_back(input[j]);
            }
            s.push_back(' ');
            end = i-1;
        }
    }

    for(int i=0; i<=end; i++){
        s.push_back(input[i]);
    }
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}