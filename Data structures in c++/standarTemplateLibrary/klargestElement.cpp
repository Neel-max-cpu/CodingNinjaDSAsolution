/*

You are given an unsorted array containing ‘N’ integers. You need to find ‘K’ largest elements from the given array and fill those K elements in the given output array.
Note:
You don't need to return or print anything it has already been taken care of. Just implement the given function and fill the output array as required.
Input Format:
The first line of the input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains two space-separated positive integers ‘N’ and ‘K’ denoting the number of the elements present in the array and count of the largest elements and fill the output array accordingly.

The second line of each test case contains ‘N’ space-separated integers denoting the elements of the array.
Output Format:
The only line of output of each test case should contain  ‘K’ largest elements in the array in non-decreasing order.

Print the output of each test case in a separate line.
Constraints:
1 <= T <= 100
1 <= N <= 10^4  
1<= K <= N  
-10^9 <= ARR[i] <= 10^9

Where ‘T’ is the number of test cases, ‘N’ is the size of the array, ‘K’ is the number of elements you need to find that are largest among the N elements.

Time Limit: 1 sec
Sample Input 1:
2
4 2
3 4 2 1
5 1
2 2 3 3 1
Sample Output 1:
3 4
3
Explanation for sample input 1:
Test case 1:
If we sort the array then it will look like: [1, 2, 3, 4]. The 2 largest elements will be [3, 4].

Test case 2:
If we sort the array then it will look like: [1, 2, 2, 3, 3]. Then the largest element will be [3].
Sample Input 2:
2
5 5
0 10 1 2 2
6 2
-2 12 -1 1 20 1 
Sample Output 2:
0 1 2 2 10
12 20
#include <algorithm>

void Klargest(int arr[],int output[],int n,int k){
    sort(arr, arr+n);
    int j = 0;
    for(int i=n-1; i>=k; i--){
        output[j] = arr[i];
        j++;
    }
}






*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <algorithm>

void Klargest(int a[],int b[],int n,int k){
    if(n==k){
        sort(a,a+n);
        for(int i=0; i<n; i++) b[i] = a[i];
        return;
    }

    sort(a,a+n);
    reverse(a,a+n);

    for(int i=0; i<k; i++){
        b[i] = a[i];
    }

    sort(b,b+k);
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
