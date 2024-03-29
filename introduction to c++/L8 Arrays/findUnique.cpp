/*
You have been given an integer array(ARR) of size N.
Now, in the given array, all numbers are present twice or more than twice except only one number is present only once.
You need to find and return that number which is unique in the array.
 Note:
Unique element is always present in the array according to the given condition.
Input format :
First line contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array.
Output Format :
 First line contains the unique element present in the array.
Constraints :
0 <= N <= 10^3
Time Limit: 1 sec
Sample Input 1:
7
2 3 1 6 3 6 2
Sample Output 1:
1
Sample Input 2:
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
10
#include<iostream>
using namespace std;

#include"solution.h"

int main(){

    int n;
    cin>>n;
    int arr1[n];
…    for(int i = 0;i<n;i++){
        cout<<arr3[i]<<" ";
    }
    
    return 0;
}






*/


#include<iostream>
using namespace std;

#include <algorithm>


int findUnique(int arr[], int size)
{   
    // sorting  --- not needed
    // for(int i=0; i<size; i++){
    //     for(int j=i+1; j<size; j++){
    //         if(arr[i]>arr[j]){
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }

    // searching
    int i,j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(arr[i] == arr[j] && i!=j) break;
        }
        if(j==size) return arr[i]; 
    }
   
   
}

int main(){

    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    int arr3[n];
    
    for(int i = 0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i = 0;i<n;i++){
        cin>>arr2[i];
    }
    sumOfTwoArrays(arr1,arr2,n,arr3);
    for(int i = 0;i<n;i++){
        cout<<arr3[i]<<" ";
    }
    
    return 0;
}