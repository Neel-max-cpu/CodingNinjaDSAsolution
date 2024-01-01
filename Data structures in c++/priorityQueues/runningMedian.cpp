/*

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
void findMedian(int *arr, int n)
{
    // Write your code here
}





*/


#include <iostream>
using namespace std;


#include <vector>
#include <algorithm>
#include <queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==0) return;


    // METHDO 1 ----
    /*
    cout<<arr[0]<<" ";
    vector<int>v; 
    v.push_back(arr[0]);
    for(int i=1; i<n; i++){
        v.push_back(arr[i]);
        sort(v.begin(), v.end());
        if(i%2==1){
            int mid_left = i/2;
            int mid_right = mid_left+1;
            int a = v[mid_left];
            int b = v[mid_right];
            cout<<(a+b)/2<<" ";
        }
        else {
            int mid = i/2;
            cout<<v[mid]<<" ";
        }
    }
    cout<<endl;
    */

    // METHOD 2:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    // METHOD 1 ---
    /*
    maxHeap.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1; i<n; i++){
        if(maxHeap.top()<arr[i]){
            minHeap.push(arr[i]);
        }
        else maxHeap.push(arr[i]);

        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() == minHeap.size()) {
            int median = (maxHeap.top() + minHeap.top()) / 2;
            cout << median << " ";
        } else if (maxHeap.size() > minHeap.size()) {
            cout << maxHeap.top() << " ";
        } else {
            cout << minHeap.top() << " ";
        }
    }
    */


    // METHOD 2 ----
    for(int i=0; i<n; i++){
        // check the size of the max heap is > 0
        if(maxHeap.size() && arr[i]>maxHeap.top()) minHeap.push(arr[i]);
        else maxHeap.push(arr[i]);

         if(abs(maxHeap.size() - minHeap.size()) > 1){
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        int median;
        int totalSize = minHeap.size() + maxHeap.size();

        if(totalSize % 2== 1){
            if(maxHeap.size() > minHeap.size()){
                median = maxHeap.top();
            }
            else median = minHeap.top();
        }
        else{
            median = 0;
            if(!maxHeap.empty()) median += maxHeap.top();
            if(!minHeap.empty()) median += minHeap.top();
            median /= 2;
        }

        cout<<median<<" ";
    }
    cout<<endl;

  
}   

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
