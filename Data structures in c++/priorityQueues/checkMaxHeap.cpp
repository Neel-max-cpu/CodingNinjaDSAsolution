/*

Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
bool isMaxHeap(int arr[], int n) {
    // Write your code here
}





*/

#include <iostream>
using namespace std;


#include <queue>
bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0; i<n; i++){
        int leftchild = 2*i+1;
        // int rightchild = 2*i+2;
        int rightchild = leftchild+1;
        if(leftchild< n && arr[leftchild]>arr[i]) return false;
        if(rightchild<n && arr[rightchild]> arr[i]) return false;
    }
    return true;

   
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}