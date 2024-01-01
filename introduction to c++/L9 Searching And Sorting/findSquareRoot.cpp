/*

You are given a positive integer ‘N’. Your task is to find and return its square root. If ‘N’ is not a perfect square, then return the floor value of sqrt(N).
Example:
Input: ‘N’ = 6

Output: 2

Explanation: The square root of the number 6 lies between 2 and 3, so the floor value is 2.
Input Format:
The first line of input contains the Integer ‘N’.
Output Format:
Return a single line containing an integer denoting the square root of ‘N’.
Note:
In case, if you are facing the test case failure, take the variables inside the function in 'unsigned int' data type.
Constraints:
0 <= N <= 10 ^ 16

Time Limit: 1 sec.
Sample Input 1:
6
Sample Output 1:
2
Explanation of Sample Input 1:
The square root of the given number 6 lies between 2 and 3, so the floor value is 2.
Sample Input 2:
100
Sample Output 2:
10
Explanation of Sample Output 2:
The square root of the given number 100 is 10.
long long int floorSqrt(long long int N)
{
    // Write your code here.
}





*/


#include <bits/stdc++.h>

using namespace std;

long long int floorSqrt(long long int N)
{
    // Write your code here.
    long long int ans = sqrt(N);
    return ans;
}

class Runner
{
    int t = 1;

    vector<long long int> allN;

public:
    void takeInput()
    {
        // cin >> t;

        allN.resize(t);

        for (int i = 0; i < t; i++)
        {
            cin >> allN[i];
        }

        return;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            long long int copyN = allN[i];

            // Get the answer from scaffold/solution
            int result = floorSqrt(copyN);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int result = floorSqrt(allN[i]);
            cout << result ;
            cout << "\n";
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
