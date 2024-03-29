/*


You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6

#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	// METHOD 1 --
	/*
	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){







*/


#include <iostream>
using namespace std;


#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

	// METHOD 1 --
	/*
	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a = arr[i];
			int one = a+k;
			int two = a-k;
			if(arr[j] == one) count++;
			else if(arr[j] == two) count++;
		}
	}
	return count;
	*/

	// METHOD 2 ---
	unordered_map<int,int>freq;
	for(int i=0; i<n; i++) freq[arr[i]]++;

	int count = 0;
	for(int i=0; i<n; i++){
		int a = arr[i];
		if(k>0){
			int one = a+k;
			int two = a-k;
			
			if(freq.count(one) > 0){
				count += (freq[a] * freq[one]);
			}
			else if(freq.count(two) > 0){
				count += (freq[a] * freq[two]);
			}

			freq[a] = 0;
		}
		else if(k==0){
			int x = freq[a] -1;
			count += ((x*(x+1))/2);
			freq[a] = 0;
		}
	}
	return count;
}
int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}