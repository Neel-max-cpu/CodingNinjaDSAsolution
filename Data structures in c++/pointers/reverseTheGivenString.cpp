/*

You are given a string 'str' consisting of lower case alphabets. You have to find the reverse of the string.
For example:
 If the given string is: str = "abcde". You have to print the string "edcba".
Input Format:
The first line of input contains a single integer 'T', representing the number of test cases or queries to be run. 

Then the 'T' test cases follow.

The first and only line of each test case contains a string 'STR'.
Output Format:
For each test case, print a single line containing a single string denoting the reverse of the given string 'STR'.

The output of each test case will be printed in a separate line.
Note:
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Constraints:
1 ≤ T ≤ 10
1 ≤ |str| ≤ 10 ^ 5 

Where |str| is the length of the string str

Time limit: 1 sec.
Sample Input 1:
3
abcde
coding
hello1
Sample Output 1:
edcba
gnidoc
1olleh
Explanation of the Sample Input 1:
For the first test case, STR = "abcde". We need to reverse the string, that is the first element becomes the last element and the last element becomes the first element, the second element becomes the second last element and the second last element becomes the second element and so on. So we get, "edcba".
Sample Input 2:
3
a
1det@Z
$1xYuP
Sample Output 2
a
Z@ted1
PuYx1$
void func(char *str) 
{
    //write your code here
}






*/


#include<iostream>

#include <cstring>

void func(char *str) 
{
    //write your code here
    char s [100001];
    int n = strlen(str);
    // for(int i = 0; i<n; i++){
    //     s[i] = str[n-1-i];
    // }

    for(int i=0; i<n/2; i++){
        char temp = str[i] ;
        str[i] = str[n-1-i];
        str[n-1-i] = temp;
    }

}

using namespace std;
int main()
{
    char ch[100001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>ch;
        func(ch);
        cout<<ch;
	cout<<endl;
    }
}