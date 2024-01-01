/*

You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements are having the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
6
7 2 2 4 8 4
Sample Output 2 :
2
Explanation:
Here, both element '2' and element '4' have same frequency but '2' ocurr first in orignal array that's why we are returning '2' as output. 
#include <unordered_map>
#include <algorithm>
#include <climits>
int highestFrequency(int a[], int n) {
    // Write your code here
    unordered_map<int,int>m;
    

    // METHOD 1 ---
    /*







*/

#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <climits>
int highestFrequency(int a[], int n) {
    // Write your code here
    unordered_map<int,int>m;
    

    // METHOD 1 ---
    /*
    int ans = 0;
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(m.count(a[i]) >0){
            m[a[i]]++;
        }
        else{
            m[a[i]] = 1;
        }
    }

    for(int i=0; i<n; i++){
        if(m[a[i]] > max){
            ans = a[i];
            max = m[a[i]];
        }
    }
    return ans;
    */

    // METHDO 2 ---
    int maxfreq = 0;
    for(int i=0; i<n; i++){
        m[a[i]]++;
        maxfreq = max(maxfreq, m[a[i]]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(m[a[i]] == maxfreq){
            return a[i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}