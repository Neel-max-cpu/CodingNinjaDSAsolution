/*

You have been given an array/list. Your task in to return the missing number. Array contains the distinct element form (0,N), both are inclusive. Missing number is the number that is not present in the array.
Input: ‘N’ = 4 
‘A’ = [3, 1, 0, 4]

Output: 2

Explanation: For nums = [3, 1, 0, 4],
The array does not contain the element '2' in the range of [0,4]. So, the answer would be 2.
Input format :
The first line contains an Integer 'N', which denotes the size of the array/list.

The second line contains 'N+1' single space-separated integers representing the elements in the array/list.
Output Format :
Return the missing number.
Constraints :
1 <= N <= 10^4
0 <= nums[i] <=10^9-1
Time Limit: 1 sec
Sample Input 1:
4
3 1 0 4
Sample Output 1:
2
Sample Input 2:
6
3 2 5 4 0 1
Sample Output 2:
6
int missingNumber(int arr[], int n)
{
    //Write your code here
    
}





*/


#include<iostream>
using namespace std;


int missingNumber(int arr[], int n)
{
    //Write your code here
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    // cout<<endl;
    for(int i=0; i<n; i++){
        if(i!=arr[i]) return i;
    }
    
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
    int ans = missingNumber(arr, n);
    cout<<ans;
    return 0;
}