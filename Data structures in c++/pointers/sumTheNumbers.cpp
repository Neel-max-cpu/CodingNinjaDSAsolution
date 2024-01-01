/*


Given an array of length N, you need to find and return the sum of all elements of the array using the concept of pointer arithmetic and pointers.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
a single line containing the sum of array elements
Constraints :
1 <= N <= 10^3
Note
You don't have to print anything. Just complete the definition of the function given.
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
Sample Input 2 :
3
4 2 1
Sample Output 2 :
7    
int sum(int *ar , int n)
{
    //write your code here
}





*/

#include<iostream>
int sum(int *ar , int n)
{
    //write your code here
    int sum = 0;
    for(int i=0; i<n; i++) sum = sum + *(ar+i);

    return sum;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int ans = sum(ar,n);
    cout<<ans;
}