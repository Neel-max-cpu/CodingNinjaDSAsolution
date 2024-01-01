/*

You have been given a vectors of pairs. Your task is to complete the function given which counts the pairs which have first value greater than their second value and returns the count.
Note:
You don't have to print anything it has been already taken care of. Just complete the function as required and return the count.
Input Format:
First line contains a single integer which is the size of the vector of pairs.
Next N lines contains 2 integers each which denotes a pair of integers
Output Format:
First line contains the count of pair which have first value greater than second value. 
Constraint:
1<=N<=1000
1<=value<=100000
Sample Input 1
5
1 2
3 0
7 5
8  4
10 9
Output 1
4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "solution.h"

int main() {
    int t;
    cin >> t;
…            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}








*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <utility>



int countPairs(vector<pair<int,int>> a){
    int  ans = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i].first > a[i].second) ans++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int brr[k];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Klargest(arr, brr, n,k);
        for(int i = 0;i<k;i++){
            cout<<brr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
