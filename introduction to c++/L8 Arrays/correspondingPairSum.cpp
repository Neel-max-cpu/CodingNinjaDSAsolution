/*

Create a program that takes an array and its size as inputs and calculates the sum of the corresponding elements. The resulting sums should be stored in an output array.
For example, given an array Arr = {1, 2, 3, 5}, the first element corresponds to the fourth element, so the sum should be stored in output[0] = 6. Similarly, the second element corresponds to the third element, so the sum should be stored in output[1] = 5. The output array should be filled up to half of the size of the input array. It is not necessary to handle cases where the input array has an odd number of elements because the size of the array is always even.
Input format:
First line of the input contains the size 'N' of the array arr.
Next line contains N integers separated by a single space.
Output Format:
Output contains N/2 corresponding pair sums separated by a single space.
Constraints:
1<=N<=10000
0<=arr[i]<=10000
Input 1:
6
1 2 3 4 5 6
Output 1:
7 7 7
Input 2:
8
4 0 3 5 1 6 5 3
Output 2:
7 5 9 6
void correspondingPairSum(int arr[],int n,int output[]){
    //Write your code here
}





*/

void correspondingPairSum(int arr[],int n,int output[]){
    //Write your code here
    int i=0, j=n-1;
    int k = 0;
    while(i<j){
        int temp = arr[i]+arr[j];
        output[k] = temp;
        i++;
        j--;
        k++;
    }

    // for(int i=0; i<n/2; i++) cout<<output[i]<<" ";
}


#include<iostream>
using namespace std;





int main(){

    int n;
    cin>>n;
    int arr[2000];
    int output[1000];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    correspondingPairSum(arr,n,output);
    for(int i = 0;i<n/2;i++){
        
        cout<<output[i];
        if(i!=(n/2)-1){
            cout<<" ";
        }
    }
    
    return 0;
}