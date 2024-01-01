/*

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
void heapSort(int arr[], int n) {
    // Write your code
}





*/

#include <iostream>
void heapSort(int arr[], int n) {
    // Write your code


    // MAIN FUNNY THING ABOUT THIS CODE IS THAT WE ARE DOING MIN HEAP HERE TO FIND THE DECREASING 
    // SORTED ARRAY --- but in actually we should be doing max Heapfy to find the decreaing , when we were doing with vector
    // i.e when we were using priority queue using extra space

    // SO, to find the increasing order we have to do the opposite, we have to do MAX HEAPFY to find the increasing order of
    // array





    int i = 1;
        // HERE THIS IS THE CODE FOR INSERTING ELEMENT SEE CLASS FUNCTION FOR THAT-
        // NOTE* here we are using min heapfy, inspite of question asking us to do in decresing order
    for(int i=1; i<n; i++){
        int child_index = i;
        int prevchild_index = child_index;
        while(child_index > 0){
            int parent_index = (child_index-1)/2;
            if(arr[child_index] < arr[parent_index]){
                
                int temp = arr[child_index];
                arr[child_index] = arr[parent_index];
                arr[parent_index] = temp;            
                
            }
            else break;
            child_index = parent_index;
        }
    }

    // now we have the array as = 1 2 3 4 5 6

    // HERE THIS IS THE CODE FOR REMOVING ELEMENT SEE CLASS FUNCTION FOR THAT-
    // NOTE* here we are using min heapfy, inspite of question asking us to do in decresing order 
    int size = n;
    while(size>1){
        int first = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = first;
        size--;

        int parent_index = 0;
        int leftchild_index = 2*parent_index+1;
        int rightchild_index = 2*parent_index+2;

        while(leftchild_index<size){
            int maxindex = parent_index;
            if(arr[leftchild_index] < arr[maxindex]){
                maxindex = leftchild_index;
            }

            if(rightchild_index<size && arr[rightchild_index] < arr[maxindex]){
                maxindex = rightchild_index;
            }

            if(maxindex == parent_index) break;

            int temp = arr[parent_index];
            arr[parent_index] = arr[maxindex];
            arr[maxindex] = temp;

            parent_index = maxindex;
            leftchild_index = 2*parent_index +1;
            rightchild_index = 2*parent_index+2;
        }

        // now after 1st iteration our array looks like = 2 3 4 5 6 1
        // 1 is at the last and rest now will iterate on with size become 1 less so , the 1st ele = 2
        // and the last ele is still 6, and when size = 1, we will have 6 5 4 3 2 1
    }

}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}