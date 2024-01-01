/*


You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.


You must sort the elements between 'l' and 'r'.


Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Input format :
The first line contains an integer <em>**'N'**</em> representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output format :
You don't need to return anything. In the output, you will see the array after you do the modification.
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
}






*/

#include <iostream>
using namespace std;

void merge(int a[], int l, int r){
    int i = l;
    int mid = l+(r-l)/2;
    int j = mid+1;

    // dynamic array
    int *arr = new int[r-l+1];
    int k = 0;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = a[j];
            j++;
            k++;
        }
    }

    // put the remaining elements if j is finished
    while(i<=mid){
        arr[k] = a[i];
        i++;
        k++;
    }

    // put the remaining elements if i is finished
    while(j<=r){
        arr[k] = a[j];
        j++;
        k++;
    }

    // then copy the elements from the temp arr to the main array
    k = 0;
    for(int i=l ;i<=r; i++){
        a[i] = arr[k];
        k++;
    }


    // also remember to delete the the array, since we are taking it dynamically
    delete []arr;
}


void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here

    // base case 
    if(l>=r) return;

    // merge sort intution, divide the array in to two parts, then sort them separately then join(merge) the sorted array together

    int mid = l+(r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
   
    // merge the sorted array together
    merge(arr,l,r); 
    
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, arr_size - 1);

    for(int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}