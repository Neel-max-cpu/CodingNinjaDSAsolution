/*

You have been given an array/list(ARR) of size N. You need to swap every pair of alternate elements in the array.
You don't need to print or return anything, just change in the input array itself.
Input Format :
First line of contains an integer 'N' representing the size of the array.

Second line contains 'N' single space separated integers representing the elements in the array.
Output Format :
First line contains the elements of the resulting array in a single row separated by a single space.
Constraints :
0 <= N <= 10^5
Time Limit: 1sec
Sample Input 1:
6
9 3 6 12 4 32
Sample Output 1 :
3 9 12 6 32 4
Sample Input 2:
9
9 3 6 12 4 32 5 11 19
Sample Output 2 :
3 9 12 6 32 4 11 5 19 
void swapAlternate(int arr[], int size)
{

    
}






*/


#include <iostream>
using namespace std;

void swapAlternate(int arr[], int size)
{
    if(size%2!=0) size-=1;
    for(int i=0; i<size; i+=2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    
}

int main()
{
	
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		swapAlternate(arr, size);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	
}