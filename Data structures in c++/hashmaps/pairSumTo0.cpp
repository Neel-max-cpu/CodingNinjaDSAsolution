/*

Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.


Note:
Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
Explanation
(2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2.

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
int pairSum(int *arr, int n) {
	// Write your code here

	// METHOD 1 --- not fully correct
	/*
	unordered_map<int,int>m;






*/

#include <iostream>
using namespace std;


#include <unordered_map>
#include <unordered_set>
#include <algorithm>
int pairSum(int *arr, int n) {
	// Write your code here
	unordered_map<int,int>m;

	// METHOD 1 --- not fully correct
	/*
	for(int i=0; i<n; i++) m[arr[i]]++;

	int count = 0;
	for (auto it: m){
		int a = it.first;
		int b = (-1)*a;	
			// not found
		if(a == 0){
			count += (it.second)*2;
			m[a] = 0;
			// s.insert(a);
		}
		else{
			if(m.count(b)>0){
				count+= (m[a] * m[b]);
				// s.insert(a);
				// s.insert(b);
				m[a] = 0;
				m[b] = 0;
			}
		}
	}
	return count;
	*/
	
	// METHOD 2 ---
	m[arr[0]]++;
	int count = 0;
	for(int i=1; i<n; i++){
		int b = (-1)*arr[i];
		// if(m.count(b) >0){
		if(m.find(b) != m.end()){				// find of set and maps are a bit diff, see that 
			count += m[b];
			m[arr[i]]++;
		}
		else m[arr[i]]++;
		
	}
	return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}