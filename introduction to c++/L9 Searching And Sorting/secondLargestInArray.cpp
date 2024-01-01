/*

You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
Input format :
The first line contains an integer 'N' representing the size of the array/list.

The second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
Return the second largest element in the array/list.
Constraints :
0 <= N <= 10^2
1<=arr[i]<=10^3

Time Limit: 1 sec
Sample Input 1:
5
4 3 10 9 2
Sample Output 1:
9
Sample Input 2:
7
13 6 31 14 29 44 3
Sample Output 2:
31
int findSecondLargest(int arr[], int n)
{
    //Write your code here
}






*/



#include <iostream>
using namespace std;


#include <climits>

int findSecondLargest(int arr[], int n)
{
    //Write your code here
    int maxi = INT_MIN;
    int maxi2 = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>maxi){
            maxi2 = maxi;
            maxi = arr[i];
        } 
        else if(arr[i]>maxi2 && arr[i]<maxi)
            maxi2 = arr[i];
    }

    return maxi2;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = findSecondLargest(arr, n);
    cout<<ans;
    return 0;
}
