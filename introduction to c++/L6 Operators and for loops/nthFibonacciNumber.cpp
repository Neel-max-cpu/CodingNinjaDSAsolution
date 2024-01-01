/*
Write a program to find the Nth Fibonacci number using loops.


Note :
The Fibonacci series is a sequence of numbers in which each number is the sum of the two preceding ones, usually starting with first_number  and Second_number . 
First_number and Second_number in this question will be 1 . Soo that the resultant series will be 1, 1, 2, 3, 5, 8 ...
Input Format :
The first line of each test case contains a real number ‘N’.
Output Format :
For each test case, print its equivalent Fibonacci number.
Constraints:
1 <= N <= 10000     
Where ‘N’ represents the number for which we have to find its equivalent Fibonacci number.

Time Limit: 1 second
Sample Input 1:
6
Sample Output 1:
8
Explanation
The Fibonacci sequence starts with two numbers first number is 1 and second number is also 1. The subsequent numbers are found by adding the two preceding numbers. Therefore, the first six Fibonacci numbers are: 1, 1, 2, 3, 5, 8 . Hence, the 6th Fibonacci number is 8.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;cin>>n;
        int first = 1, second = 1;
        if(n==1 || n==2) cout<<1;
        else{
                for(int i=3; i<=n; i++){
                        int temp  = first+second;
                        first = second;
                        second = temp;
                }
                cout<<second;
        } 
}       