/*


You are given an array/list ‘ARR’ of ‘N’ integers. You have to generate an array/list containing squares of each number in ‘ARR’, sorted in increasing order.
For example :
Input:
‘ARR’ = [-6,-3, 2, 1, 5] 

If we take a square of each element then the array/list will become [36, 9, 4, 1, 25].
Then the sorted array/list will be [1, 4, 9, 25, 36].

Output :
[1, 4, 9, 25, 36].
Input Format:
The first line of input contains a single integer ‘T’, representing the number of test cases.
Then the ‘T’ test cases follow.

The first line of each test case contains a single integer ‘N’ denoting the size of ‘ARR’.

The second line contains ‘N’ space-separated distinct integers denoting the array elements.
Output format:
For each test case, print the array elements separated by a single space.

The output of every test case will be printed in a separate line. 
Note :
You don’t have to print anything, it has already been taken care of. Just implement the given function.
Constraints
1 <= T <=100
1 <= N <= 10^4
-10^4 <=  ‘ARR[i]’ <= 10^4

Where 'ARR[i]' denotes the value of 'ARR' at index 'i'. 

Time limit: 1 sec
Sample Input 1:
2
4 
-3 -3 1 2
6 
0 1 2 3 4 5 
Sample Output 1:
1 4 9 9 
0 1 4 9 16 25
Explanation Of Sample Input 1:
For test case 1:
On taking the square of each element ‘ARR’ will become [9, 9, 1, 4].
Now we can sort the array/list and output will be [1, 4, 9, 9].

For test case 2:
On taking the square of each element ‘ARR’ will become [0, 1, 4, 9, 16, 25].
Now we can see that the array/list is already sorted, so the output will be  [0, 1, 4, 9, 16, 25].
Sample Input 2:
2
1
5
4
-6 -3 -2 -1
Sample Output 2:
25
1 4 9 36
Explanation Of Sample Input 2:
For test case 1:
On taking the square of each element ‘ARR’ will become [25].
Now as the array/list has only 1 element so it is already sorted, the output will be [25].

For test case 2:
On taking the square of each element ‘ARR’ will become [36,9,4,1].
Now we can see that the array/list is already sorted, so the output will be [36, 9, 4, 1].
#include <iostream>
#include<vector>
using namespace std;

#include "solution.h"

int main()
{

    ios_base::sync_with_stdio(false);
…    }
    return 0;
}





*/

#include <iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h> 
#include <vector>
#include <algorithm>
vector < int > sqsorted(vector < int > & arr) {
    // Write your code here.

    vector<int>v;
    for(int i=0; i<arr.size(); i++){
        v.push_back(arr[i]*arr[i]);
    }

    sort(v.begin(), v.end());
    return v;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testcase;
    cin>>testcase;
    
    while(testcase--){

        int n;
        cin>>n;

        vector<int>arr(n);
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int ans = sumOfMaxMin(arr, n);

        cout<<ans<<endl;
    }
    return 0;
}