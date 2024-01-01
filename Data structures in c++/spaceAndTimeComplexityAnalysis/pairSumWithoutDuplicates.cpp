/*

You have been given a sorted integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can not contain duplicate elements. 
Input format :
First line contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
0 <= N <= 10^5
0 <= num <= 10^5
Time Limit: 1 sec
Sample Input 1:
5
1 2 3 4 5
7
Sample Output 1:
2
Sample Input 2:
5
1 2 3 4 5
10
Sample Output 2:
0
int pairSum(int A[], int size, int K)
{
     // Write your code here.
}






*/


#include <iostream>
using namespace std;
int pairSum(int a[], int size, int k)
{
     // Write your code here.
     int i =0, j = size -1;
     int ans = 0;
     while(j>i){
          if(a[i]+a[j]==k){
               ans++;
               i++;
               j--;
          }
          else if(a[i]+a[j]<k){
               i++;
          }
          else if(a[i]+a[j]>k){
               j--;
          }
     }

     return ans;
}
int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    int k;
    cin>>k;
    int ans = pairSum(input, n, k);
    cout<<ans;
    return 0;
}