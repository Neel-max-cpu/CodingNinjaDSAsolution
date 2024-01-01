/*

Ninja has been given a binary string ‘STR’ containing either ‘0’ or ‘1’. A binary string is called beautiful if it contains alternating 0s and 1s.
For Example:‘0101’, ‘1010’, ‘101’, ‘010’ are beautiful strings.
He wants to make ‘STR’ beautiful by performing some operations on it. In one operation, Ninja can convert ‘0’ into ‘1’ or vice versa.
Your task is to determine the minimum number of operations Ninja should perform to make ‘STR’ beautiful.
For Example :
Minimum operations to make ‘STR’ ‘0010’ beautiful is ‘1’. In one operation, we can convert ‘0’ at index ‘0’ (0-based indexing) to ‘1’. The ‘STR’ now becomes ‘1010’ which is a beautiful string. 
Input Format :
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The only line of each test case contains a binary string 'STR'.
Output Format :
For each test case, print the minimum operations needed to make ‘STR’ beautiful.

Print the output of each test case in a separate line.
Note :
You are not required to print the expected output, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 100
2 <= |STR| <= 10^5
STR[i] = ‘1’ or ‘0’

Where '|STR|' denotes the length of ‘STR’.

Time Limit: 1 sec 
Sample Input 1 :
2
0000
1010
Sample Output 1 :
2
0
Explanation of Sample Input 1 :
For the first test case:
The two beautiful strings that can be formed from the given ‘STR’ 
are “1010” and “0101”. Ninja can transform ‘STR’ to “1010” by 
performing the following operations:
Replace ‘0’ at index 0 by ‘1’.
Replace ‘0’ at index 2 by ‘1’.

Ninja can transform ‘STR’ to “0101” by performing the following 
operations:
Replace ‘0' at index 1 by ‘1’.
Replace ‘0’ at index 3 by ‘1’.

The minimum number of operations in transforming ‘STR’ to either of the two beautiful strings is 2.

For the second test case:
Given ‘STR’ is already beautiful so the minimum number of operations required is 0.
Sample Input 2 :
2
01011
1001
Sample Output 2 :
1
2
Explanation of Sample Input 2 :
For the first test case:
The two beautiful strings that can be formed from the given ‘STR’ are “10101” and “01010”. Ninja can transform ‘STR’ to “10101” by performing the following operations:
Replace ‘0’ at index 0 by ‘1’.
Replace ‘1’ at index 1 by ‘0’.
Replace ‘0’ at index 2 by ‘1’
Replace ‘1’ at index 4 by ‘0’.

Ninja can transform ‘STR’ to “01010” by performing the following operations:
Replace ‘1’ at index 4 by ‘0’.

The minimum number of operations in transforming ‘STR’ to beautiful is the minimum of the above two which is 1.

For the second test case:
The two beautiful strings that can be formed from the given ‘STR’ are “1010” and “0101”. Ninja can transform ‘STR’ to “1010” by performing the following operations:
Replace ‘0’ at index 2 by ‘1’.
Replace ‘1’ at index 3 by ‘0’.

Ninja can transform ‘STR’ to “0101” by performing the following operations:
Replace ‘0’ at index 0 by ‘1’.
Replace ‘1’ at index 1 by ‘0’.

The minimum number of operations in transforming ‘STR’ to either of the two beautiful strings is 2.
int makeBeautiful(string str) {
	// Write your code here
}





*/

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include<climits>

using namespace std;
int makeBeautiful(string str) {
	// Write your code here
	int n = str.size();
	string s1 = "";
	string s2 = "";

	for(int i=0; i<n; i++){
		if(i%2==0) s1.push_back('1');
		else s1.push_back('0');
	}

	for(int i=0; i<n; i++){
		if(i%2==0) s2.push_back('0');
		else s2.push_back('1');
	}

	int count1 = 0, count2 = 0;
	for(int i=0; i<n; i++){
		if(str[i]!=s1[i]) count1++;
		if(str[i]!=s2[i]) count2++;
	}

	return min(count1, count2);
	
}


class Runner
{
    int t;
    vector<string> str;

public:
    void takeInput()
    {
        cin >> t;
        for (int c = 0; c < t; c++)
        {
            string temp;
            cin >> temp;
            str.push_back(temp);
        }
    }

    void execute()
    {
        vector<string> strCopy = str;
        for (int i = 0; i < t; i++)
        {
            int ans = makeBeautiful(strCopy[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = makeBeautiful(str[i]);
            cout << ans << "\n";
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