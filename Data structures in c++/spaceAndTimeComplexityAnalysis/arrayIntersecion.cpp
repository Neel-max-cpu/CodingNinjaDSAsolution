/*

You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.
void intersection(int *arr1, int *arr2, int n, int m) 
{
    //Write your code here
}






*/  

#include <iostream>
#include <algorithm>
using namespace std;


#include <algorithm>
#include <vector>


bool search(int *a, int n, int x){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(a[mid]==x){
            return true;
        }
        // x greater , increase the start
        else if(a[mid]<x){
            start = mid+1;
        }
        // x smaller, decrease the end
        else{
            end = mid -1;
        }
    }
    return false;
}

void intersection(int *a1, int *a2, int n, int m) 
{
    //Write your code here
    // METHOD1 -- O(nm), o(1), little bit more here, than the eg given in the video, since i am sorting vector, and extra space for vector
    /*
    vector<int>v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a1[i]==a2[j]) v.push_back(a1[i]);
        }
    }

    sort(v.begin(), v.end());
    cout<<v[0]<<" ";
    for(int i=1; i<v.size(); i++){
        if(v[i-1]!=v[i]) cout<<v[i]<<" ";
    }
    */


    // METHOD 2
    // sorting will give nlogn, mlog, and going through will give m+n total so, m+n+nlogn + mlogm = O(nlogn) ,and space o(logn)
    // /*
    sort(a1, a1+n);
    sort(a2, a2+m);

    int i = 0, j = 0;
    while(i<n && j<m){
        if(a1[i]==a2[j]) {
            cout<<a1[i]<<" ";
            i++;
            j++;
        }
        else if(a1[i]<a2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    // */


    // METHOD 3
    // didn't work though gave tle
    /*
    if(m>n){
        // n is smaller
        sort(a1, a1+n);
        for(int i=0; i<m; i++){
            if(binary_search(a1,n,a2[i])) cout<<a2[i]<<" ";
            // if(search(a1, n, a2[i])==true)  cout<<a2[i]<<" ";
        }
    }
    else{
        // m is smaller
        sort(a2, a2+m);
        for(int i=0; i<n; i++){
            if(binary_search(a2,m,a1[i])) cout<<a1[i]<<" ";
            // if(search(a2, m, a1[i])==true)  cout<<a1[i]<<" ";
        }
    }
    
    */

    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}