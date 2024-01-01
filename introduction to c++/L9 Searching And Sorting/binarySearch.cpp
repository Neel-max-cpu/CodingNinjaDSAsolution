/*

You are given an integer array 'A' of size 'N', sorted in ascending order. You are also given an integer 'target'.
Your task is to write a function to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing. Otherwise, return -1.
Example:
Input: ‘N’ = 7 ‘target’ = 3
‘A’ = [1, 3, 7, 9, 11, 12, 45]

Output: 1

Explanation: For A = [1, 3, 7, 9, 11, 12, 45],
The index of element '3' is 1.
Hence, the answer is '1'.
Input format :
The first line contains an Integer 'N', which denotes the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.

The third line contains the value of 'target' to be searched for in the array/list.
Output Format :
Return the index at which 'target' is present for each test case, -1 otherwise.
Constraints :
1 <= N <= 10^4
1 <= A[i] <= 10^9
1 <= target <= 10^9
Time Limit: 1 sec
Sample Input 1:
7
1 3 7 9 11 12 45
3
Sample Output 1:
1
Explanation of sample output 1:
For nums = [1, 3, 7, 9, 11, 12, 45],
The index of element '3' is 1.
Hence, the answer is '1'.
Sample Input 2:
7
1 2 3 4 5 6 7
9
Sample Output 2:
-1
Explanation of sample output 2:
For nums = [1, 2, 3, 4, 5, 6, 7],
Element '9' doesn't exist.
Hence, the answer is '-1'.
int binarySearch(int nums[], int left, int right, int target) {
    // Write Your Code Here
}





*/


#include<iostream>
using namespace std;


int binarySearch(int nums[], int left, int right, int target) {
    while(left<=right){
        // int mid = (left+right)/2;
        
        // avoid overflow
        int mid = left+((right-left)/2);
        if(nums[mid]==target) return mid;

        // target is smaller
        if(nums[mid]>target) right = mid-1;
        else left = mid+1;
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left = 0;
    int right =n-1;
    int target;
    cin>>target;


    int ans = binarySearch(arr, 0, n-1, target);


    cout<<ans;




    return 0;
}