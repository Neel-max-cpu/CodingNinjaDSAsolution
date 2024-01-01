/*

Given an array of n integers, find and return the pointer type reference to the highest element of the array. For example if the array is "1 2 3 4 5", you have to return the pointer type variable holding the address of "5".
Input format
First line of the input will consist of number of elements n .
Second line will consist of array ar elements separated by space.
Output format
A single line containing the highest number
Constraints
 1<= n <=10^6
-10^6 <= ar[i] <= 10^6
Note
You just have to write the definiton of the given function template and return the corresponding pointer type reference. No need of taking any input or printing any output.
Sample Input 1
 2
-56 10
Sample Output
10
Sample Input 2
4
1 2 3 4
Sample Output 2
4
#include <iostream>
#include "solution.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;







*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    //write your code here

    // METHOD 1
    
    /*
    int *maxi = ar;
    for(int i=1; i<n; i++){
        if(ar[i]>*maxi){
            maxi = &ar[i];
        }
    }

    return maxi;
    */

    // METHOD 2
    
    int maxi = ar[0];
    for(int i=1; i<n; i++){
        if(ar[i]>maxi) maxi = ar[i];
    }
    
    int *res = &maxi;
    return res;
}
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        swap(&a , &b);
        cout<<a<<" "<<b;
        cout<<endl;
    }
}