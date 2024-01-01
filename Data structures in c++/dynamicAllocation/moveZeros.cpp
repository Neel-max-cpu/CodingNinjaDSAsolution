/*

Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, and all the non-zero elements are moved to the front. Use the concept of dynamic memory allocation for taking array input.
All non zero element will remain in same order as before.
For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be:
[1, -2, 3, 4, 5, -27, 9, 0, 0, 0].
Input format :
The first line of input contains a single integer ‘T’ representing the number of test cases.      

The first line of each test case contains a single integer ‘N’ representing the size of the array. The second line of each test case contains ‘N’ integers representing the elements of the array.
Output Format :
For each test case, modify the input array and print the output in a new line 
Constraints :
1 <= T <= 50 
1 <= N <= 10^6
-10000 <= A[i] <= 10000

Where ‘T’ is the number of test cases, ‘N’ is the size of the array, A[i] is the value of the element present at the ith index.
Time Limit:1sec
Sample Input 1:
2
7
2 0 4 1 3 0 28
5
0 0 0 0 1
Sample Output 1:
2 4 1 3 28 0 0
1 0 0 0 0
The explanation for Sample Output 1 :
In the first testcase, All the zeros are moved towards the end of the array, and the non-zero elements are pushed towards the left, maintaining their order with respect to the original array.

In the second testcase, All zero are moved towards the end, hence the only non-zero element i.e 1 is in the starting of the array 
Sample Input 2:
2
5
0 3 0 2 0
4
0 0 0 0
Sample Output 2:
3 2 0 0 0
0 0 0 0
#include<iostream>
using namespace std;
int main()
{
    //write your code here
}





*/

#include<iostream>
using namespace std;
int main()
{
    //write your code here
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int *a = new int[n];
        int count = 0;
        for(int i=0; i<n; i++) {
            cin>>a[i];
            if(a[i]==0) count++;
        }

        int *b = new int[n];
        int j = 0;
        for(int i=0; i<n; i++){
            if(a[i]!=0){
                b[j] = a[i];
                j++;
            }
        }
        for(int i=j; i<n; i++){
            b[i] = 0;
        }

        for(int i=0; i<n; i++) cout<<b[i]<<" ";
        cout<<endl;
    }
}