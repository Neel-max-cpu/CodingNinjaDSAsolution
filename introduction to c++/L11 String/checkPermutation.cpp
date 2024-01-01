/*

You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.
Note:
Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.
Example :
If 'STR1' = “listen” and 'STR2' = “silent” then the output will be 1.

Both the strings contain the same set of characters.
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases. 

The first and only line of each test case contains two space-separated strings 'STR1' and 'STR2', respectively.
Output Format:
For each test case, return true if the two strings are anagrams of each other else return false.

Print the output of each test case in a separate line.
Constraints:
1 <= T <= 100
1 <= |STR1|, |STR2| <= 10^3

Where |STR1| and |STR2| are the lengths of the string 'STR1' and 'STR2' respectively.

Time limit: 1 sec
Sample Input 1:
2
listen silent
east eats
Sample Output 1:
1
1
Explanation for Sample Output 1:
In test case 1, "listen" and "silent" has same set of characters.

In test case 2, "east" and "eats" has same set of characters.
Sample Input 2:
2
triangle integral
hearts earth
Sample Output 2:
1
0
Explanation for Sample Output 1:
In test case 1, "triangle" and "integral" has same set of characters.

In test case 2, "hearts" and "earth" does not have same set of characters.
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
}





*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>


using namespace std;
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if(str1.size()!=str2.size()) return false;
    else{
        for(int i=0; i<str1.size(); i++){
            if(str1[i]!=str2[i]) {
                return false;
            }
        }
        return true;
    }
}

class Runner
{
    int t;
    vector<vector<string> > arr;

public:
    void takeInput()
    {
        cin >> t;

        for (int c = 0; c < t; c++)
        {
            vector<string> temp(2);
            for(int i=0;i<2;i++)
                cin>>temp[i];
                arr.push_back(temp);
        }

    }


    void execute()
    {
        vector<vector<string> > arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            areAnagram(arrCopy[i][0], arrCopy[i][1]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            cout<<areAnagram(arr[i][0], arr[i][1])<<endl;
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}

