/*

You are given an array 'arr' of length 'n'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.


Peak element is defined as that element that is greater than both of its neighbors. If 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'.


Assume 'arr[-1]' and 'arr[n]' as negative infinity.


Note:
1.  There are no 2 adjacent elements having same value (as mentioned in the constraints).
2.  Do not print anything, just return the index of the peak element (0 - indexed).
3. 'True'/'False' will be printed depending on whether your answer is correct or not.


Example:
Input: 'arr' = [1, 8, 1, 5, 3]

Output: 3

Explanation: There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3.


Input format:
The first line contains an integer ‘n’, the number of elements in 'arr'.
The second line contains ‘n’ space-separated integers , the array 'arr'.


Output Format
The output contains True/ False depending whether the found number is peak element or not.


Sample Input 1:
5
1 8 1 5 3


Expected Answer:
1


Output on Console:
True


Explanation of sample input 1 :
There are two possible answers. Both 8 and 5 are peak elements, so the correct answers are their positions, 1 and 3. Any of these 2 numbers will print 'True'.


Sample Input 2:
3
1 2 1 


Expected Answer:
1


Output on Console:
True


Expected time complexity:
The expected time complexity is O(log 'n').


Constraints:
1 <= 'n' <= 10^5
1 <= 'arr[i]' <= 10^5
'arr[i]' != 'arr[i + 1]' for all 'i' in range 0 <= 'i' < 'n' - 1


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

#include <algorithm>
#include<vector>

#include<climits>


int findPeakElement(vector<int> &a) {
    // Write your code here

    int peak  = 0;
    int low = INT_MIN;
    int n = a.size();

    for(int i=0; i<n; i++){
        if(i==0){
            if(a[i]>low && a[i]>a[i+1]){
                peak = i;
                break;
            }
        }

        else if(i==n-1){
            if(a[i]>a[i-1] && a[i]>low){
                peak = i;
                break;
            }
        }

        else if(i>0 && i<n-1){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                peak = i;
                break;
            }
        }
    }

    return peak;
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