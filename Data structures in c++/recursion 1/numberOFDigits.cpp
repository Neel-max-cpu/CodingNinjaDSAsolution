/*


You are given a number 'n'.


Return number of digits in ‘n’.


Example:
Input: 'n' = 123

Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3. 


Input format:
The first line of input contains an integer ‘n’.


Output Format:
Return an integer as described in the problem statement. 


Note
You don’t need to print anything, it has already been taken care of, just complete the given function.
Sample Input 1:
121


Sample Output 1:
3


Explanation of sample output 1:
There are 3 digits in 121 are 1,2 and 1.

Sample Input 2:
38


Sample Output 2:
2


Expected time complexity :
The expected time complexity is O(log n).


Constraints:
1 <= ‘n’ <= 10^9
int countDigits(int n){
	// Write your code here.	
}





*/


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

int countDigits(int n){
	// Write your code here.	
	
	// METHOD 1
	/*
	if(n==0) return 0;
	return 1+countDigits(n/10);
	*/


	// METHOD 2
	return log10(n)+1;
}

class Runner
{
    int N;

public:
    void takeInput()
    {
        cin >> N;
    }

    void execute()
    {
        int ans = countDigits(N);
    }

    void executeAndPrintOutput()
    {

        int ans = countDigits(N);
        cout << ans << endl;
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}