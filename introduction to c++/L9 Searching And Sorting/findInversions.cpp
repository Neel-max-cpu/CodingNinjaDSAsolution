/*

In the realm of sorting algorithms, an inversion is a pair of elements that are out of order. Your task is to determine the number of inversions in a given array/list. In this problem, an inversion refers to a pair of elements that are in the wrong order and would require swapping to sort the array/list.
Example:
Input: ‘N’ = 5 
‘A’ = [3, 2, 11, 5, 1]

Output: 6
Input format :
The first line of input contains an integer ‘N’, denoting the size of the array/list. The second line contains ‘N’ single space-separated integers representing the elements in the array/list.
Output Format :
The output should be a single integer - the number of inversions in the array/list.
Constraints :
1 <= N <= 10^4
1 <= nums[i] <= 10^9
Time Limit: 1 sec
Sample Input 1:
5
3 2 11 5 1
Sample Output 1:
6
Explanation
When we apply selection sort, first swap will happen between array[0] to array[4], inversion will be (index of arrar[4]-index of array[0]) = 4-0=4 and the array after this will be [1, 2, 11, 5, 3], still the array is not sorted. So we will apply selection sort again, the swap will now take place between array[2] and array[4], inversion will be 4+(index of arrar[4]-index of array[2])=4+(4-2)=4+2=6.So the final sorted array now will be [1,2,3,5,11]
Sample Input 2:
7
17 5 14 16 11 18 10
Sample Output 2:
10
Explanation
Array: [17, 5, 14, 16, 11, 18, 10]
Inversion count = 10
int getInversions(int arr[], int n)
{
    //Write your code here
}





*/

#include<iostream>
using namespace std;

int getInversions(int arr[], int n)
{
    //Write your code here
    int inversion = 0;
    for(int i=0; i<n-1; i++){
        int min_index = i;
        
        // mini element and index
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }

        // swaping
        if(min_index!=i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            inversion += abs(i-min_index);
        }

    }

    return inversion;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
	    cin>>arr[i];
    }
    int ans = getInversions(arr, n);
    cout << ans << endl;
    return 0;
}
