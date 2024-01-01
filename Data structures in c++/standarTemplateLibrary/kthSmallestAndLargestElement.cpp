/*


You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.
Example:
Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
The next 2*T lines represent the ‘T’ test cases.

The first line of each test case contains two space-separated integers  ‘N’ and ‘K’ respectively.

The second line of the test case contains ‘N’ space-separated integers representing elements of the array ‘Arr’.
Output format :
For each test case, print a line consisting of two space-separated integers that represent the Kth smallest and Kth largest elements of the array.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. In the given function, you need to return an array consisting of 2 integers, where the first integer gives Kth smallest element and the second integer gives the Kth largest element.
Constraints:
1 <= T <= 50
1 <= N <= 10^4
1 <= K <= N
-10^9 <= Arr[i] <= 10^9

Where ‘T’ is the total number of test cases, ‘N’ is the size of array ‘Arr’ and Arr[i] is the element of the given array.

Time limit: 1 sec
Sample Input 1:
2
4 4
5 6 7 2
4 3
1 2 5 4
Sample Output 1:
7 2 
4 2
Explanation of Sample Input 1:
Test case 1:
Here, ‘N’ = 4, ‘Arr’ = [5, 6, 7, 2] and ‘K’ = 3.
Elements of the array in ascending order are [2, 5, 6, 7]
Thus the 4rd smallest and 4rd largest elements of this array are 7 and 2 respectively.

Test case 2:
See problem statement for an explanation.
Sample Input 2:
 2
 1 1
 2
 5 1
 5 4 3 2 1
Sample Output 2:
 2 2
 1 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;
…            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}






*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <algorithm>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	// 1 2 3 4 5 6 7 8 9 10 , and k = 4, 4th largest ele = 7, and 4th smallest element = 4
	int smallest = 0, largest = 0;
	// if(k>n/2){
	// 	smallest = arr[n-1-k-1];
	// 	largest = arr[k-1];
	// }
	// else{
	// 	smallest = arr[k-1];
	// 	largest = arr[n-1-k-1];
	// }

	smallest = arr[k-1];
	largest = arr[n-k];
	vector<int>v;
	v.push_back(smallest);
	v.push_back(largest);

	return  v;
}   

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int brr[k];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Klargest(arr, brr, n,k);
        for(int i = 0;i<k;i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
