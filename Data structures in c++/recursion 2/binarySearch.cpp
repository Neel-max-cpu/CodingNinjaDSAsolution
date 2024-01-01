/*


Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
Hint : Use helper function to solve this question.
// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[], int size, int element) {
    // Write your code here

}






*/


#include <iostream>
using namespace std;
// input - input array
// size - length of input array
// element - value to be searched


int fun(int a[], int first, int last, int x){
    if(first>last) return -1;

    int mid = first + (last-first)/2;
    if(a[mid]==x) return mid;
    // see the left part
    if(a[mid]>x){
        return fun(a, first, mid-1, x);
    }

    // see the right part
    if(a[mid]<x){
        return fun(a, mid+1, last, x);
    }
}


int binarySearch(int input[], int size, int element) {
    // Write your code here
    int first = 0;
    int last = size -1;
    
    return fun(input, first, last, element);

}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
