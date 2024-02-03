/*

Classroom
DP - 1
profile picture
Problem statement
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Write a simple recursive solution.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315


    // identify the trees as 
    /*
            0
           /   \
        []      []

        of height n, then left and right subtree and have height of h-1 and h-1; h-1 and h-2; and h-2 and h-1
        to be balanced since a binary tree to be balanced abs(height of left_subtree - height of right_subtree) == 1


*/


#include <iostream>
using namespace std;

#define ll long long int 
const unsigned int mod = 1e9+7;

int balancedBTs(int n) {
    // Write your code here
    
    // base case
    if(n<=1){
        return 1;
    }


    // identify the trees as 
    /*
            0
           /   \
        []      []

        of height n, then left and right subtree and have height of h-1 and h-1; h-1 and h-2; and h-2 and h-1
        to be balanced since a binary tree to be balanced abs(height of left_subtree - height of right_subtree) == 1
        and left and right subtree should be balanced

        so to find the count of total balanced binary tree of height "h" there are 3 possible combination ---
        h-1 and h-1(left and right-- height)
        h-2 and h-1(left and right-- height)
        h-1 and h-2(left and right-- height)

        so basically = (h-1 * h-2) + (h-1 * h-2) + (h-1 * h-1);
        = (h-1 *h-2) * 2 + (h-1 * h-1);

    */

    // different cases
    ll left_subtree = (balancedBTs(n-1))%mod;
    
    ll right_subtree = (balancedBTs(n-2))%mod;

    ll total = ((((left_subtree*right_subtree)%mod)*2)%mod + ((left_subtree*left_subtree)%mod))%mod;
    return total;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}