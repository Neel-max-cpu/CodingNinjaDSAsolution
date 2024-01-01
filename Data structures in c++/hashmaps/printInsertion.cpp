/*


You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array/list (ARR2).


Input format :
The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
Print the intersection elements. Each element is printed in a separate line.
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2

#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    
    unordered_map<int, int>first;
    unordered_map<int, int>second;
    // unordered_map<int, int>c;








*/


#include <iostream>
using namespace std;


#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    
    unordered_map<int, int>first;
    unordered_map<int, int>second;
    // unordered_map<int, int>c;


    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         if(arr2[i] == arr1[j]){

    //             if(c.count(arr2[i]) >0 && c[arr2[i]] == true) continue;
    //             else{
    //                 c[arr2[i]] = true;
    //                 cout<<arr2[i]<<endl;
    //             }
    //         }
    //     }
    // }

    for(int i=0; i<n; i++) first[arr1[i]]++;
    // for(int j=0; j<m; j++) second[arr2[j]]++;

    int i = 0, j=0;
    // 7 7 7
    // 7 7 7 7
    while(i<m){
        if(first[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            first[arr2[i]]--;
        }
        // for(int j=0; j<n; j++){
        //     // if(second[arr2[i]] == first[arr1[i]]){
        //     if(arr2[i] == arr1[j]){
        //         if(second[arr2[i]] > 0 && first[arr1[j]] >0){
        //             cout<<arr2[i]<<endl;
        //             second[arr2[i]]--;
        //             first[arr1[j]]--;
        //         } 
        //         else continue;
        //     }
        // }
        i++;
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}